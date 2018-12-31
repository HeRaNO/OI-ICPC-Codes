#include <cstdio>
#include <cstring>
#define MAXN 100010
#define MOD 1000000007LL
using namespace std;

struct KSM
{
	long long m[3][3];
	void clean()
	{
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				m[i][j] = (i == j);
		return ;
	}
};

struct SegmentTree
{
	int p, r, m;
	KSM a;
};

struct link
{
	int to, nxt;
};

link e[MAXN << 1];
int head[MAXN], cnt;
KSM ans, base;
SegmentTree tree[1 << 18];
int n, T, R = 1, u, v, k;
int in[MAXN], out[MAXN], seq[MAXN], a[MAXN];

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

inline KSM multiply(KSM a, KSM b)
{
	KSM res;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			res.m[i][j] = 0LL;
			for (int k = 0; k < 3; k++)
				res.m[i][j] = (res.m[i][j] + a.m[i][k] * b.m[k][j]) % MOD;
		}
	return res;
}

void dfs(int node, int father)
{
	in[node] = R;
	seq[R++] = node;
	for (int i = head[node]; ~i; i = e[i].nxt)
		if (e[i].to != father) dfs(e[i].to, node);
	out[node] = R;
	return ;
}

inline void getset(int v, int k)
{
	memset(base.m, 0, sizeof base.m);
	base.m[0][1] = base.m[1][0] = base.m[1][1] = base.m[2][2] = 1;
	base.m[2][1] = k;
	memset(ans.m, 0, sizeof ans.m);
	ans.m[0][0] = ans.m[2][2] = 1;
	ans.m[2][1] = v;
	k--;
	while (k)
	{
		if (k & 1) ans = multiply(ans, base);
		base = multiply(base, base);
		k >>= 1;
	}
	return ;
}

inline void Push_Down(int u)
{
	tree[u << 1].a = multiply(tree[u << 1].a, tree[u].a);
	tree[u << 1 | 1].a = multiply(tree[u << 1 | 1].a, tree[u].a);
	tree[u].a.clean();
	return ;
}

void Build_A_Tree(int u)
{
	if (tree[u].p + 1 == tree[u].r)
	{
		tree[u].a.m[0][0] = a[seq[tree[u].p]];
		tree[u].a.m[0][2] = 1;
		return ;
	}
	tree[u].m = tree[u].p + tree[u].r >> 1;
	tree[u << 1].p = tree[u].p;
	tree[u << 1].r = tree[u].m;
	Build_A_Tree(u << 1);
	tree[u << 1 | 1].p = tree[u].m;
	tree[u << 1 | 1].r = tree[u].r;
	Build_A_Tree(u << 1 | 1);
	tree[u].a.clean();
	return ;
}

void modify(int u, int l, int r, KSM x)
{
	if (tree[u].p == l && tree[u].r == r)
	{
		tree[u].a = multiply(tree[u].a, x);
		return ;
	}
	Push_Down(u);
	if (r <= tree[u].m) modify(u << 1, l, r, x);
	else if (tree[u].m <= l) modify(u << 1 | 1, l, r, x);
	else
	{
		modify(u << 1, l, tree[u].m, x);
		modify(u << 1 | 1, tree[u].m, r, x);
	}
	return ;
}

long long query(int u, int x)
{
	if (tree[u].p + 1 == tree[u].r) return tree[u].a.m[0][0];
	Push_Down(u);
	if (x < tree[u].m) return query(u << 1, x);
	else return query(u << 1 | 1, x);
}

long long big_query(int u)
{
	if (tree[u].p + 1 == tree[u].r) return tree[u].a.m[0][0];
	Push_Down(u);
	return (big_query(u << 1) + big_query(u << 1 | 1)) % MOD;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return ;
}

int main()
{
	memset(head, -1, sizeof head);
	read(n);
	read(T);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i < n; i++)
	{
		read(u);
		read(v);
		add(u, v);
	}
	dfs(1, 1);
	tree[1].p = 1;
	tree[1].r = n + 1;
	Build_A_Tree(1);
	while (T--)
	{
		read(u);
		read(v);
		read(k);
		getset(query(1, in[v]), k);
		modify(1, in[u], out[u], ans);
	}
	printf("%lld\n", big_query(1));
	return 0;
}
