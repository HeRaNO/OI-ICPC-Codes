#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
using namespace std;

struct link
{
	int to;
	int nxt;
};

struct SegmentTree
{
	int p, r, m;
	int sum, lazy;
};

link e[MAXN << 1];
SegmentTree tree[MAXN << 2];
int edge_num[MAXN], cnt;
int pos[MAXN], top[MAXN], father[MAXN];
int dep[MAXN], siz[MAXN], maxx[MAXN];
int n, T, R, opt, u, v;

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
		if (e[i].to != father[node])
		{
			dep[e[i].to] = dep[node] + 1;
			father[e[i].to] = node;
			dfs1(e[i].to);
			siz[node] += siz[e[i].to];
			if (!~maxx[node] || siz[e[i].to] > siz[maxx[node]]) maxx[node] = e[i].to;
		}
	return ;
}

inline void dfs2(int node, int t)
{
	top[node] = t;
	pos[node] = ++R;
	if (~maxx[node]) dfs2(maxx[node], t);
	for (int i = edge_num[node]; ~i; i = e[i].nxt)
		if (e[i].to != maxx[node] && e[i].to != father[node]) dfs2(e[i].to, e[i].to);
	return ;
}

inline void Push_Down(int u)
{
	if (!tree[u].lazy) return ;
	tree[u << 1].sum += (tree[u << 1].r - tree[u << 1].p) * tree[u].lazy;
	tree[u << 1].lazy += tree[u].lazy;
	tree[u << 1 | 1].sum += (tree[u << 1 | 1].r - tree[u << 1 | 1].p) * tree[u].lazy;
	tree[u << 1 | 1].lazy += tree[u].lazy;
	tree[u].lazy = 0;
	return ;
}

inline void Push_Up(int u)
{
	tree[u].sum = tree[u << 1].sum + tree[u << 1 | 1].sum;
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

inline void modify(int u, int l, int r)
{
	if (tree[u].p == l && tree[u].r == r)
	{
		tree[u].sum += r - l;
		tree[u].lazy++;
		return ;
	}
	Push_Down(u);
	if (r <= tree[u].m) modify(u << 1, l, r);
	else if (l >= tree[u].m) modify(u << 1 | 1, l, r);
	else
	{
		modify(u << 1, l, tree[u].m);
		modify(u << 1 | 1, tree[u].m, r);
	}
	Push_Up(u);
	return ;
}

inline int query(int u, int l, int r)
{
	if (tree[u].p == l && tree[u].r == r) return tree[u].sum;
	Push_Down(u);
	if (r <= tree[u].m) return query(u << 1, l, r);
	else if (l >= tree[u].m) return query(u << 1 | 1, l, r);
	else return query(u << 1, l, tree[u].m) + query(u << 1 | 1, tree[u].m, r);
}

inline void Plant(int l, int r)
{
	while (top[l] != top[r])
	{
		if (dep[top[l]] < dep[top[r]]) swap(l, r);
		modify(1, pos[top[l]], pos[l] + 1);
		l = father[top[l]];
	}
	if (pos[l] > pos[r]) swap(l, r);
	if (pos[l] != pos[r]) modify(1, pos[l] + 1, pos[r] + 1);
	return ;
}

inline int Query(int l, int r)
{
	int res = 0;
	while (top[l] != top[r])
	{
		if (dep[top[l]] < dep[top[r]]) swap(l, r);
		if (pos[top[l]] == pos[l]) res += query(1, pos[top[l]], pos[l] + 1);
		else res += query(1, pos[top[l]], pos[l]);
		l = father[top[l]];
	}
	if (pos[l] > pos[r]) swap(l, r);
	if (pos[l] != pos[r]) res += query(1, pos[l] + 1, pos[r] + 1);
	return res;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == 'P') return ;
		else if (ch == 'Q')
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
	//freopen("grassplant.in","r",stdin);freopen("grassplant.out","w",stdout);
	memset(edge_num, -1, sizeof edge_num);
	read(n);
	read(T);
	for (int i = 1; i < n; i++)
	{
		read(u);
		read(v);
		add(u, v);
	}
	dep[1] = 1;
	dfs1(1);
	dfs2(1, 1);
	tree[1].p = 1;
	tree[1].r = n + 1;
	Build_A_Tree(1);
	while (T--)
	{
		read(opt);
		read(u);
		read(v);
		if (!opt) Plant(u, v);
		else printf("%d\n", Query(u, v));
	}
	return 0;
}
