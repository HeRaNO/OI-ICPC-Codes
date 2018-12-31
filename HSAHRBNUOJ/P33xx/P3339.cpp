#pragma GCC optimize("O2")
#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 100010
#define logN 28
using namespace std;

inline int myabs(int x)
{
	return x < 0 ? -x : x;
}
inline bool isneg(int x)
{
	return x < 0;
}
inline int mymin(int a, int b)
{
	return a < b ? a : b;
}
inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

struct longint
{
	bool neg;
	unsigned long long a;
	longint() {}
	longint(unsigned long long _a, bool _x): a(_a), neg(_x) {}
	inline longint operator +(const int &x)const
	{
		int r = myabs(x);
		if (neg ^ isneg(x))
		{
			if (a < r) return longint(r - a, isneg(x));
			else return longint(a - r, neg);
		}
		else return longint(a + r, neg);
	}
	inline longint operator +(const longint &x)const
	{
		if (neg ^ x.neg)
		{
			if (a < x.a) return longint(x.a - a, x.neg);
			else return longint(a - x.a, neg);
		}
		else return longint(a + x.a, x.neg);
	}
	inline longint operator *(const int &x)const
	{
		int r = myabs(x);
		if (isneg(x)^neg) return longint(1LL * r * a, true);
		else return longint(1LL * r * a, false);
	}
	inline void print()
	{
		if (neg && a) putchar('-');
		printf("%llu\n", a);
		return ;
	}
} ans;

struct link
{
	int to, nxt;
};

struct SegmentTree
{
	int p, r, m;
	longint x, lazy;
};

link e[MAXN << 1];
SegmentTree tree[1 << 18];
int head[MAXN], cnt, top;
int n, T, R = 1, u, v, x, opt;
int fib[logN], lable[MAXN];
int range[2][MAXN][logN], sta[MAXN];
queue <int> q;

inline void add(int u, int v)
{
	e[cnt] = (link)
	{
		v, head[u]
	};
	head[u] = cnt++;
	e[cnt] = (link)
	{
		u, head[v]
	};
	head[v] = cnt++;
}

inline void BFS_Relabel()
{
	fib[1] = fib[2] = 1;
	for (int i = 3; fib[i - 1] <= n; i++) fib[i] = fib[i - 1] + fib[i - 2];
	fib[1] = 0;
	q.push(1);
	lable[1] = R;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = head[u]; ~i; i = e[i].nxt)
			if (!lable[e[i].to])
			{
				lable[e[i].to] = ++R;
				q.push(e[i].to);
			}
	}
	return ;
}

inline void DFS(int x, int father)
{
	sta[++top] = x;
	for (int i = 1; top - fib[i] > 0; i++)
	{
		range[0][sta[top - fib[i]]][i] = mymin(range[0][sta[top - fib[i]]][i], lable[x]);
		range[1][sta[top - fib[i]]][i] = mymax(range[1][sta[top - fib[i]]][i], lable[x]);
	}
	for (int i = head[x]; ~i; i = e[i].nxt)
		if (e[i].to != father) DFS(e[i].to, x);
	top--;
	return ;
}

inline void Push_Down(int u)
{
	if (tree[u].lazy.a)
	{
		int len = tree[u << 1].r - tree[u << 1].p;
		tree[u << 1].lazy = tree[u << 1].lazy + tree[u].lazy;
		tree[u << 1].x = tree[u << 1].x + tree[u].lazy * len;
		len = tree[u << 1 | 1].r - tree[u << 1 | 1].p;
		tree[u << 1 | 1].lazy = tree[u << 1 | 1].lazy + tree[u].lazy;
		tree[u << 1 | 1].x = tree[u << 1 | 1].x + tree[u].lazy * len;
		tree[u].lazy = longint(0, 0);
	}
	return ;
}

inline void Build_A_Tree(int u)
{
	if (tree[u].p + 1 == tree[u].r) return ;
	tree[u].m = tree[u].p + tree[u].r >> 1;
	tree[u << 1].p = tree[u].p;
	tree[u << 1].r = tree[u].m;
	Build_A_Tree(u << 1);
	tree[u << 1 | 1].p = tree[u].m;
	tree[u << 1 | 1].r = tree[u].r;
	Build_A_Tree(u << 1 | 1);
	return ;
}

inline void modify(int u, int l, int r, int v)
{
	if (tree[u].p == l && tree[u].r == r)
	{
		tree[u].lazy = tree[u].lazy + v;
		tree[u].x = tree[u].x + longint(1LL * (r - l) * myabs(v), isneg(v));
		return ;
	}
	Push_Down(u);
	if (r <= tree[u].m) modify(u << 1, l, r, v);
	else if (tree[u].m <= l) modify(u << 1 | 1, l, r, v);
	else
	{
		modify(u << 1, l, tree[u].m, v);
		modify(u << 1 | 1, tree[u].m, r, v);
	}
	tree[u].x = tree[u << 1].x + tree[u << 1 | 1].x;
	return ;
}

inline longint query(int u, int l, int r)
{
	if (tree[u].p == l && tree[u].r == r) return tree[u].x;
	Push_Down(u);
	if (r <= tree[u].m) return query(u << 1, l, r);
	else if (tree[u].m <= l) return query(u << 1 | 1, l, r);
	else return query(u << 1, l, tree[u].m) + query(u << 1 | 1, tree[u].m, r);
}

inline void read(int &x)
{
	x = 0;
	bool f = false;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = true;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	if (f) x = -x;
	return ;
}

int main()
{
	//freopen("tree2.in","r",stdin);freopen("tree2.out","w",stdout);
	memset(head, -1, sizeof head);
	memset(range[0], 0x7f, sizeof range[0]);
	read(n);
	read(T);
	for (int i = 1; i < n; i++)
	{
		read(u);
		read(v);
		add(u, v);
	}
	BFS_Relabel();
	DFS(1, -1);
	tree[1].p = 1;
	tree[1].r = n + 1;
	Build_A_Tree(1);
	while (T--)
	{
		read(opt);
		read(u);
		opt--;
		if (!opt)
		{
			read(x);
			for (int i = 1; range[1][u][i]; i++)
				modify(1, range[0][u][i], range[1][u][i] + 1, x);
		}
		else
		{
			ans = longint(0, 0);
			for (int i = 1; range[1][u][i]; i++)
				ans = ans + query(1, range[0][u][i], range[1][u][i] + 1);
			ans.print();
		}
	}
	return 0;
}