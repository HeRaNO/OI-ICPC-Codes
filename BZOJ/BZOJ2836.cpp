#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
using namespace std;

struct link
{
	int to, nxt;
};

struct SegmentTree
{
	int p, r, m;
	long long sum, lazy;
};

link e[MAXN << 1];
SegmentTree tree[1 << 18];
int n, T, R = 1, u, v, opt, d;
int edge_num[MAXN], cnt;
int in[MAXN], out[MAXN];
int dep[MAXN], siz[MAXN], maxx[MAXN], father[MAXN], top[MAXN];

inline void add(int u, int v)
{
	e[cnt] = (link)
	{
		v, edge_num[u]
	};
	edge_num[u] = cnt++;
	e[cnt] = (link)
	{
		u, edge_num[v]
	};
	edge_num[v] = cnt++;
}

inline void dfs1(int node)
{
	siz[node] = 1;
	maxx[node] = -1;
	for (int i = edge_num[node]; ~i; i = e[i].nxt)
		if (father[node] != e[i].to)
		{
			dep[e[i].to] = dep[node] + 1;
			father[e[i].to] = node;
			dfs1(e[i].to);
			siz[node] += siz[e[i].to];
			if (!~maxx[node] || siz[maxx[node]] < siz[e[i].to]) maxx[node] = e[i].to;
		}
	return ;
}

inline void dfs2(int node, int t)
{
	top[node] = t;
	in[node] = R++;
	if (~maxx[node]) dfs2(maxx[node], t);
	for (int i = edge_num[node]; ~i; i = e[i].nxt)
		if (e[i].to != maxx[node] && e[i].to != father[node]) dfs2(e[i].to, e[i].to);
	out[node] = R;
	return ;
}

inline void Push_Up(int u)
{
	tree[u].sum = tree[u << 1].sum + tree[u << 1 | 1].sum;
	return ;
}

inline void Push_Down(int u)
{
	tree[u << 1].sum += (long long)(tree[u << 1].r - tree[u << 1].p) * tree[u].lazy;
	tree[u << 1].lazy += tree[u].lazy;
	tree[u << 1 | 1].sum += (long long)(tree[u << 1 | 1].r - tree[u << 1 | 1].p) * tree[u].lazy;
	tree[u << 1 | 1].lazy += tree[u].lazy;
	tree[u].lazy = 0LL;
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

inline void modify(int u, int l, int r, long long v)
{
	if (tree[u].p == l && tree[u].r == r)
	{
		tree[u].lazy += v;
		tree[u].sum += (long long)(tree[u].r - tree[u].p) * v;
		return ;
	}
	Push_Down(u);
	if (r <= tree[u].m) modify(u << 1, l, r, v);
	else if (l >= tree[u].m) modify(u << 1 | 1, l, r, v);
	else
	{
		modify(u << 1, l, tree[u].m, v);
		modify(u << 1 | 1, tree[u].m, r, v);
	}
	Push_Up(u);
	return ;
}

inline long long query(int u, int l, int r)
{
	if (tree[u].p == l && tree[u].r == r) return tree[u].sum;
	if (tree[u].lazy) Push_Down(u);
	if (r <= tree[u].m) return query(u << 1, l, r);
	else if (l >= tree[u].m) return query(u << 1 | 1, l, r);
	else return query(u << 1, l, tree[u].m) + query(u << 1 | 1, tree[u].m, r);
}

inline void modify_link(int l, int r, long long v)
{
	while (top[l] != top[r])
	{
		if (dep[top[l]] < dep[top[r]]) swap(l, r);
		modify(1, in[top[l]], in[l] + 1, v);
		l = father[top[l]];
	}
	if (in[l] > in[r]) swap(l, r);
	modify(1, in[l], in[r] + 1, v);
	return ;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == 'A')
		{
			x = 0;
			return ;
		}
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
	read(n);
	memset(edge_num, -1, sizeof edge_num);
	for (int i = 1; i < n; i++)
	{
		read(u);
		read(v);
		add(u, v);
	}
	dfs1(0);
	dfs2(0, 0);
	tree[1].p = 1;
	tree[1].r = n + 1;
	Build_A_Tree(1);
	read(T);
	while (T--)
	{
		read(opt);
		if (!opt)
		{
			read(u);
			read(v);
			read(d);
			modify_link(u, v, (long long)d);
		}
		else
		{
			read(u);
			printf("%lld\n", query(1, in[u], out[u]));
		}
	}
	return 0;
}
