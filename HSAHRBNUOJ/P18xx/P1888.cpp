#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
#define MAXN 30100
using namespace std;

struct link
{
	int to;
	int nxt;
};

struct SegmentTree
{
	int p, r, m;
	int left, right;
	int sum, maxx;
};

link e[2 * MAXN];
SegmentTree tree[MAXN * 2];
int pos[MAXN], val[MAXN], top[MAXN], father[MAXN];
int dep[MAXN], siz[MAXN], edge_num[MAXN];
int n, T, u, v, cnt1, cnt2 = 1, cnt3;
char opt[10];

int mymax(int a, int b)
{
	return a > b ? a : b;
}

void add(int u, int v)
{
	e[cnt1] = (link)
	{
		v, edge_num[u]
	};
	edge_num[u] = cnt1++;
	e[cnt1] = (link)
	{
		u, edge_num[v]
	};
	edge_num[v] = cnt1++;
}

void dfs1(int node)
{
	siz[node] = 1;
	for (int i = edge_num[node]; ~i; i = e[i].nxt)
		if (e[i].to != father[node])
		{
			dep[e[i].to] = dep[node] + 1;
			father[e[i].to] = node;
			dfs1(e[i].to);
			siz[node] += siz[e[i].to];
		}
	return ;
}

void dfs2(int node, int t)
{
	int heavy = 0;
	pos[node] = ++cnt3;
	top[node] = t;
	for (int i = edge_num[node]; ~i; i = e[i].nxt)
		if (e[i].to != father[node] && siz[e[i].to] > siz[heavy])
			heavy = e[i].to;
	if (!heavy) return ;
	dfs2(heavy, t);
	for (int i = edge_num[node]; ~i; i = e[i].nxt)
		if (e[i].to != father[node] && heavy != e[i].to)
			dfs2(e[i].to, e[i].to);
	return ;
}

void Build_A_Tree(int u)
{
	if (tree[u].p + 1 == tree[u].r) return ;
	tree[u].m = (tree[u].p + tree[u].r) >> 1;
	cnt2++;
	tree[u].left = cnt2;
	tree[cnt2].p = tree[u].p;
	tree[cnt2].r = tree[u].m;
	Build_A_Tree(cnt2);
	cnt2++;
	tree[u].right = cnt2;
	tree[cnt2].p = tree[u].m;
	tree[cnt2].r = tree[u].r;
	Build_A_Tree(cnt2);
	return ;
}

void modify(int u, int x, int delta)
{
	if (tree[u].p + 1 == tree[u].r)
	{
		tree[u].maxx = tree[u].sum = delta;
		return ;
	}
	if (x < tree[u].m) modify(tree[u].left, x, delta);
	else modify(tree[u].right, x, delta);
	tree[u].sum = tree[tree[u].left].sum + tree[tree[u].right].sum;
	tree[u].maxx = mymax(tree[tree[u].left].maxx, tree[tree[u].right].maxx);
	return ;
}

int query_sum(int u, int l, int r)
{
	if (tree[u].p == l && tree[u].r == r) return tree[u].sum;
	if (r <= tree[u].m) return query_sum(tree[u].left, l, r);
	else if (l >= tree[u].m) return query_sum(tree[u].right, l, r);
	else return query_sum(tree[u].left, l, tree[u].m) + query_sum(tree[u].right, tree[u].m, r);
}

int query_max(int u, int l, int r)
{
	if (tree[u].p == l && tree[u].r == r) return tree[u].maxx;
	if (r <= tree[u].m) return query_max(tree[u].left, l, r);
	else if (l >= tree[u].m) return query_max(tree[u].right, l, r);
	else return mymax(query_max(tree[u].left, l, tree[u].m), query_max(tree[u].right, tree[u].m, r));
}

int solve_sum(int l, int r)
{
	int sum = 0;
	while (top[l] != top[r])
	{
		if (dep[top[l]] < dep[top[r]]) swap(l, r);
		sum += query_sum(1, pos[top[l]], pos[l] + 1);
		l = father[top[l]];
	}
	if (pos[l] > pos[r]) swap(l, r);
	sum += query_sum(1, pos[l], pos[r] + 1);
	return sum;
}

int solve_max(int l, int r)
{
	int res = INT_MIN;
	while (top[l] != top[r])
	{
		if (dep[top[l]] < dep[top[r]]) swap(l, r);
		res = mymax(query_max(1, pos[top[l]], pos[l] + 1), res);
		l = father[top[l]];
	}
	if (pos[l] > pos[r]) swap(l, r);
	res = mymax(res, query_max(1, pos[l], pos[r] + 1));
	return res;
}

int main()
{
	memset(edge_num, -1, sizeof(edge_num));
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		scanf("%d %d", &u, &v);
		add(u, v);
	}
	for (int i = 1; i <= n; i++) scanf("%d", &val[i]);
	dfs1(1);
	dfs2(1, 1);
	tree[1].p = 1;
	tree[1].r = n + 1;
	Build_A_Tree(1);
	for (int i = 1; i <= n; i++) modify(1, pos[i], val[i]);
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s %d %d", opt, &u, &v);
		if (opt[0] == 'C') modify(1, pos[u], v);
		else
		{
			if (opt[1] == 'M') printf("%d\n", solve_max(u, v));
			else printf("%d\n", solve_sum(u, v));
		}
	}
	return 0;
}
