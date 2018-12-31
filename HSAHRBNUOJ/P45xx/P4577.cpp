#include <cstdio>
#include <cstring>
#define MAXN 100010
using namespace std;

struct SegmentTree
{
	int p, r, m, x;
};

struct link
{
	int to, nxt;
};

link e[MAXN << 1];
SegmentTree tree[1 << 18];
int head[MAXN], cnt;
int n, T, R = 1, opt, u, v, in[MAXN], out[MAXN];

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

inline void dfs(int x, int father)
{
	in[x] = R++;
	for (int i = head[x]; ~i; i = e[i].nxt)
		if (e[i].to != father) dfs(e[i].to, x);
	out[x] = R;
	return ;
}

inline void Build_Tree(int u)
{
	if (tree[u].p + 1 == tree[u].r)
	{
		tree[u].x = 1;
		return ;
	}
	tree[u].m = tree[u].p + tree[u].r >> 1;
	tree[u << 1].p = tree[u].p;
	tree[u << 1].r = tree[u].m;
	Build_Tree(u << 1);
	tree[u << 1 | 1].p = tree[u].m;
	tree[u << 1 | 1].r = tree[u].r;
	Build_Tree(u << 1 | 1);
	tree[u].x = tree[u << 1].x + tree[u << 1 | 1].x;
	return ;
}

inline void modify(int u, int x)
{
	if (tree[u].p + 1 == tree[u].r)
	{
		tree[u].x ^= 1;
		return ;
	}
	if (x < tree[u].m) modify(u << 1, x);
	else modify(u << 1 | 1, x);
	tree[u].x = tree[u << 1].x + tree[u << 1 | 1].x;
	return ;
}

inline int query(int u, int l, int r)
{
	if (tree[u].p == l && tree[u].r == r) return tree[u].x;
	if (r <= tree[u].m) query(u << 1, l, r);
	else if (tree[u].m <= l) query(u << 1 | 1, l, r);
	else return query(u << 1, l, tree[u].m) + query(u << 1 | 1, tree[u].m, r);
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == 'C') return ;
		if (ch == 'Q')
		{
			x = 1;
			return ;
		}
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return ;
}

int main()
{
	memset(head, -1, sizeof head);
	read(n);
	for (int i = 1; i < n; i++)
	{
		read(u);
		read(v);
		add(u, v);
	}
	dfs(1, -1);
	tree[1].p = 1;
	tree[1].r = n + 1;
	Build_Tree(1);
	read(T);
	while (T--)
	{
		read(opt);
		read(u);
		if (!opt) modify(1, in[u]);
		else printf("%d\n", query(1, in[u], out[u]));
	}
	return 0;
}