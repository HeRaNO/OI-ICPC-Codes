#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
using namespace std;

long long x[1 << 18], lazy[1 << 18];
int rev[MAXN], top[MAXN], fa[MAXN];
int in[MAXN], out[MAXN], dep[MAXN], siz[MAXN], mx[MAXN];
int n, T, R = 1, opt, u, v;
vector <int> g[MAXN];

inline void dfs1(int x)
{
	siz[x] = 1; mx[x] = -1;
	for (auto v : g[x])
		if (v != fa[x])
		{
			dep[v] = dep[x] + 1; fa[v] = x;
			dfs1(v);
			siz[x] += siz[v];
			if (!~mx[x] || siz[v] > siz[mx[x]]) mx[x] = v;
		}
	return ;
}

inline void dfs2(int x, int t)
{
	top[x] = t; rev[R] = x; in[x] = R++;
	if (~mx[x]) dfs2(mx[x], t);
	for (auto v : g[x])
		if (v != mx[x] && v != fa[x]) dfs2(v, v);
	out[x] = R;
	return ;
}

inline void add(int u, int l, int r, long long v)
{
	x[u] += (r - l) * v; lazy[u] += v;
	return ;
}

inline void PushDown(int u, int l, int r)
{
	if (!lazy[u]) return ;
	int m = l + r >> 1;
	add(u << 1, l, m, lazy[u]); add(u << 1 | 1, m, r, lazy[u]);
	lazy[u] = 0;
	return ;
}

inline void BuildTree(int u, int l, int r)
{
	if (tree[u].p + 1 == tree[u].r) { x[u] = a[rev[l]]; return ; }
	int m = l + r >> 1; BuildTree(u << 1, l, m); BuildTree(u << 1 | 1, m, r);
	x[u] = x[u << 1] + x[u << 1 | 1];
	return ;
}

inline void modify(int u, int l, int r, int v, int pl, int pr)
{
	if (pl == l && pr == r)
	{
		add(u, v);
		return ;
	}
	PushDown(u, pl, pr); int m = pl + pr >> 1;
	if (r <= m) modify(u << 1, l, r, v, pl, m);
	else if (m <= l) modify(u << 1 | 1, l, r, v, m, pr);
	else
	{
		modify(u << 1, l, m, v, pl, m);
		modify(u << 1 | 1, m, r, v, m, pr);
	}
	x[u] = x[u << 1] + x[u << 1 | 1];
	return ;
}

inline long long query(int u, int l, int r, int pl, int pr)
{
	if (pl == l && pr == r) return x[u];
	PushDown(u, pl, pr); int m = pl + pr >> 1;
	if (r <= m) return query(u << 1, l, r, pl, m);
	else if (m <= l) return query(u << 1 | 1, l, r, m, pr);
	else return query(u << 1, l, m, pl, m) + query(u << 1 | 1, m, r, m, pr);
}

inline void modify_link(int l, int r, int v)
{
	while (top[l] != top[r])
	{
		if (dep[top[l]] < dep[top[r]]) swap(l, r);
		modify(1, in[top[l]], in[l] + 1, v, 1, n + 1);
		l = fa[top[l]];
	}
	if (in[l] > in[r]) swap(l, r);
	modify(1, in[l], in[r] + 1, v, 1, n + 1); // Weight on vertex
	// if (in[l] < in[r]) modify(1, in[l] + 1, in[r] + 1, v, 1, n + 1) // Weight on edge
	return ;
}

inline int query_link(int l, int r)
{
	int res = 0;
	while (top[l] != top[r])
	{
		if (dep[top[l]] < dep[top[r]]) swap(l, r);
		res += query(1, in[top[l]], in[l] + 1, 1, n + 1);
		l = fa[top[l]];
	}
	if (in[l] > in[r]) swap(l, r);
	res += query(1, in[l], in[r] + 1, 1, n + 1);
	// if (in[l] < in[r]) res += query(1, in[l] + 1, in[r] + 1, 1, n + 1) // Weight on edge
	return res;
}

inline void modify_tree(int x, int v)
{
	modify(1, in[x], out[x], v);
	return ;
}

inline int query_tree(int x)
{
	return query(1, in[x], out[x]);
}

int main()
{
	return 0;
}
