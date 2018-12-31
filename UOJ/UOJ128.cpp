#include <cstdio>
#include <cstring>
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
	int sum, setit;
};

link e[MAXN << 1];
SegmentTree tree[MAXN << 1];
int edge_num[MAXN], cnt;
int pos[MAXN], top[MAXN], father[MAXN];
int in[MAXN], out[MAXN], dep[MAXN], siz[MAXN], maxx[MAXN];
int n, T, R, opt, x, cnt1, cnt2 = 1;

inline void add(int u, int v)
{
	e[cnt] = (link)
	{
		v, edge_num[u]
	};
	edge_num[u] = cnt++;
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
	pos[node] = in[node] = R++;
	if (~maxx[node]) dfs2(maxx[node], t);
	for (int i = edge_num[node]; ~i; i = e[i].nxt)
		if (e[i].to != maxx[node]) dfs2(e[i].to, e[i].to);
	out[node] = R;
	return ;
}

inline void Build_A_Tree(int u)
{
	tree[u].sum = 0;
	tree[u].setit = -1;
	if (tree[u].p + 1 == tree[u].r) return ;
	tree[u].m = tree[u].p + tree[u].r >> 1;
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

inline void Push_Up(int u)
{
	tree[u].sum = tree[tree[u].left].sum + tree[tree[u].right].sum;
	return ;
}

inline void Push_Down(int u)
{
	if (!~tree[u].setit) return ;
	int np = tree[u].left;
	tree[np].setit = tree[u].setit;
	tree[np].sum = (tree[np].r - tree[np].p) * tree[u].setit;
	np = tree[u].right;
	tree[np].setit = tree[u].setit;
	tree[np].sum = (tree[np].r - tree[np].p) * tree[u].setit;
	tree[u].setit = -1;
	return ;
}

inline void modify(int u, int l, int r, int v)
{
	if (tree[u].p == l && tree[u].r == r)
	{
		tree[u].setit = v;
		tree[u].sum = (tree[u].r - tree[u].p) * v;
		return ;
	}
	Push_Down(u);
	if (r <= tree[u].m) modify(tree[u].left, l, r, v);
	else if (l >= tree[u].m) modify(tree[u].right, l, r, v);
	else
	{
		modify(tree[u].left, l, tree[u].m, v);
		modify(tree[u].right, tree[u].m, r, v);
	}
	Push_Up(u);
	return ;
}

inline int query(int u, int l, int r)
{
	if (tree[u].p == l && tree[u].r == r) return tree[u].sum;
	Push_Down(u);
	if (r <= tree[u].m) return query(tree[u].left, l, r);
	else if (l >= tree[u].m) return query(tree[u].right, l, r);
	else return query(tree[u].left, l, tree[u].m) + query(tree[u].right, tree[u].m, r);
}

inline void modify_link(int x)
{
	while (top[x])
	{
		modify(1, pos[top[x]], pos[x] + 1, 1);
		x = father[top[x]];
	}
	modify(1, pos[0], pos[x] + 1, 1);
	return ;
}

inline int query_link(int x)
{
	int res = 0;
	while (top[x])
	{
		res += query(1, pos[top[x]], pos[x] + 1);
		x = father[top[x]];
	}
	res += query(1, pos[0], pos[x] + 1);
	return res;
}

inline void modify_tree(int x)
{
	modify(1, in[x], out[x], 0);
	return ;
}

inline int query_tree(int x)
{
	return query(1, in[x], out[x]);
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == 'i')
		{
			x = 0;
			return ;
		}
		if (ch == 'u')
		{
			x = 1;
			getchar();
			getchar();
			return ;
		}
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return ;
}

int main()
{
	//freopen("manager.in","r",stdin);freopen("manager.out","w",stdout);
	memset(edge_num, -1, sizeof edge_num);
	read(n);
	for (int i = 1; i < n; i++) read(x), add(x, i);
	dep[0] = 1;
	dfs1(0);
	dfs2(0, 0);
	tree[1].p = 0;
	tree[1].r = n;
	Build_A_Tree(1);
	read(T);
	while (T--)
	{
		read(opt);
		read(x);
		if (!opt) printf("%d\n", dep[x] - query_link(x)), modify_link(x);
		else printf("%d\n", query_tree(x)), modify_tree(x);
	}
	return 0;
}
