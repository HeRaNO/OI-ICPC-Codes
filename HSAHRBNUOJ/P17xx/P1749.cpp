#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 10010
using namespace std;

struct edge
{
	int x, y, val;
};

struct SegmentTree
{
	int p, r, m, x;
};

SegmentTree tree[1 << 15];
edge e[MAXN << 1], f[MAXN];
int head[MAXN], cnt;
int n, T, u, v, w, opt;
int pos[MAXN], top[MAXN], father[MAXN];
int siz[MAXN], dep[MAXN], maxx[MAXN];

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

inline void add(int u, int v)
{
	e[cnt] = (edge)
	{
		v, head[u], 0
	};
	head[u] = cnt++;
	e[cnt] = (edge)
	{
		u, head[v], 0
	};
	head[v] = cnt++;
}

inline void dfs1(int x)
{
	siz[x] = 1;
	maxx[x] = -1;
	for (int i = head[x]; ~i; i = e[i].y)
		if (e[i].x != father[x])
		{
			dep[e[i].x] = dep[x] + 1;
			father[e[i].x] = x;
			dfs1(e[i].x);
			siz[x] += siz[e[i].x];
			if (!~maxx[x] || siz[e[i].x] > siz[maxx[x]]) maxx[x] = e[i].x;
		}
	return ;
}

inline void dfs2(int x, int t)
{
	top[x] = t;
	pos[x] = ++T;
	if (~maxx[x]) dfs2(maxx[x], t);
	for (int i = head[x]; ~i; i = e[i].y)
		if (e[i].x != maxx[x] && e[i].x != father[x]) dfs2(e[i].x, e[i].x);
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
		tree[u].x = v;
		return ;
	}
	if (r <= tree[u].m) modify(u << 1, l, r, v);
	else if (tree[u].m <= l) modify(u << 1 | 1, l, r, v);
	else
	{
		modify(u << 1, l, tree[u].m, v);
		modify(u << 1 | 1, tree[u].m, r, v);
	}
	tree[u].x = mymax(tree[u << 1].x, tree[u << 1 | 1].x);
	return ;
}

inline int query(int u, int l, int r)
{
	if (tree[u].p == l && tree[u].r == r) return tree[u].x;
	if (r <= tree[u].m) return query(u << 1, l, r);
	else if (tree[u].m <= l) return query(u << 1 | 1, l, r);
	else return mymax(query(u << 1, l, tree[u].m), query(u << 1 | 1, tree[u].m, r));
}

inline void C(int l, int r, int v)
{
	while (top[l] != top[r])
	{
		if (dep[top[l]] < dep[top[r]]) swap(l, r);
		modify(1, pos[top[l]], pos[l] + 1, v);
		l = father[top[l]];
	}
	if (pos[l] > pos[r]) swap(l, r);
	if (pos[l] != pos[r]) modify(1, pos[l] + 1, pos[r] + 1, v);
	return ;
}

inline int Q(int l, int r)
{
	int res = (1 << 31) + 1;
	while (top[l] != top[r])
	{
		if (dep[top[l]] < dep[top[r]]) swap(l, r);
		res = mymax(res, query(1, pos[top[l]], pos[l] + 1));
		l = father[top[l]];
	}
	if (pos[l] > pos[r]) swap(l, r);
	if (pos[l] != pos[r]) res = mymax(res, query(1, pos[l] + 1, pos[r] + 1));
	return res;
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
		if (ch == 'D')
		{
			x = 2;
			return ;
		}
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return ;
}

int main()
{
	//freopen("test.in","r",stdin);freopen("test.out","w",stdout);
	memset(head, -1, sizeof head);
	read(n);
	for (int i = 1; i < n; i++)
	{
		read(u);
		read(v);
		read(w);
		add(u, v);
		f[i] = (edge)
		{
			u, v, w
		};
	}
	dfs1(1);
	dfs2(1, 1);
	tree[1].p = 1;
	tree[1].r = n + 1;
	Build_A_Tree(1);
	for (int i = 1; i < n; i++) C(f[i].x, f[i].y, f[i].val);
	while (true)
	{
		read(opt);
		opt--;
		if (!~opt)
		{
			read(u);
			read(v);
			if (u < n && f[u].val != v)
			{
				C(f[u].x, f[u].y, v);
				f[u].val = v;
			}
		}
		else if (!opt)
		{
			read(u);
			read(v);
			printf("%d\n", Q(u, v));
		}
		else break;
	}
	return 0;
}
