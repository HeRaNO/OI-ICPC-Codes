#include <stdio.h>
#include <string.h>
#define MAXN 100010

struct link
{
	int to, nxt;
};
struct SegmentTree
{
	int p, r, m, x, l;
};

SegmentTree tree[1 << 18];
link e[MAXN << 1];
int head[MAXN], cnt;
int n, m, R = 1, rt, u, v, w, k;
int pos[MAXN], top[MAXN], fa[MAXN];
int in[MAXN], out[MAXN], dep[MAXN], siz[MAXN], maxx[MAXN];

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

inline void dfs1(int x)
{
	siz[x] = 1;
	maxx[x] = -1;
	for (int i = head[x]; ~i; i = e[i].nxt)
		if (e[i].to != fa[x])
		{
			dep[e[i].to] = dep[x] + 1;
			fa[e[i].to] = x;
			dfs1(e[i].to);
			siz[x] += siz[e[i].to];
			if (!~maxx[x] || siz[e[i].to] > siz[maxx[x]]) maxx[x] = e[i].to;
		}
	return ;
}

inline void dfs2(int x, int t)
{
	top[x] = t;
	in[x] = pos[x] = R++;
	if (~maxx[x]) dfs2(maxx[x], t);
	for (int i = head[x]; ~i; i = e[i].nxt)
		if (e[i].to != maxx[x] && e[i].to != fa[x]) dfs2(e[i].to, e[i].to);
	out[x] = R;
	return ;
}

inline void BuildTree(int u)
{
	if (tree[u].p + 1 == tree[u].r) return ;
	tree[u].m = tree[u].p + tree[u].r >> 1;
	tree[u << 1].p = tree[u].p;
	tree[u << 1].r = tree[u].m;
	BuildTree(u << 1);
	tree[u << 1 | 1].p = tree[u].m;
	tree[u << 1 | 1].r = tree[u].r;
	BuildTree(u << 1 | 1);
	return ;
}

inline void Push_Down(int u)
{
	if (!tree[u].l) return ;
	tree[u << 1].x += (tree[u << 1].r - tree[u << 1].p) * tree[u].l;
	tree[u << 1].l += tree[u].l;
	tree[u << 1 | 1].x += (tree[u << 1 | 1].r - tree[u << 1 | 1].p) * tree[u].l;
	tree[u << 1 | 1].l += tree[u].l;
	tree[u].l = 0;
	return ;
}

inline void modify(int u, int l, int r, int v)
{
	if (tree[u].p == l && tree[u].r == r)
	{
		tree[u].x += (r - l) * v;
		tree[u].l += v;
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
	return ;
}

inline int query(int x)
{
	int u = 1;
	while (tree[u].p + 1 != tree[u].r)
	{
		Push_Down(u);
		if (x < tree[u].m) u <<= 1;
		else u = u << 1 | 1;
	}
	return tree[u].x;
}

inline void modify_link(int l, int r, int w)
{
	while (top[l] != top[r])
	{
		if (dep[top[l]] < dep[top[r]])
		{
			int t = l;
			l = r;
			r = t;
		}
		modify(1, pos[top[l]], pos[l] + 1, w);
		l = fa[top[l]];
	}
	if (pos[l] > pos[r])
	{
		int t = l;
		l = r;
		r = t;
	}
	modify(1, pos[l], pos[r] + 1, w);
	return ;
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
	read(m);
	read(rt);
	for (int i = 1; i < n; i++)
	{
		read(u);
		read(v);
		add(u, v);
	}
	dfs1(rt);
	dfs2(rt, rt);
	tree[1].p = 1;
	tree[1].r = n + 1;
	BuildTree(1);
	while (m--)
	{
		read(k);
		if (k == 1)
		{
			read(u);
			read(v);
			modify(1, in[u], out[u], v);
		}
		else if (k == 2)
		{
			read(u);
			read(v);
			read(w);
			modify_link(u, v, w);
		}
		else
		{
			read(u);
			printf("%d\n", query(pos[u]));
		}
	}
	return 0;
}