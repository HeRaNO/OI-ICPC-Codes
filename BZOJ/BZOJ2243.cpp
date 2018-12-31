#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
using namespace std;

struct link
{
	int to, nxt;
};

struct data
{
	int lc, rc, cnt;
	data() {}
	data(int _lc, int _rc, int _cnt): lc(_lc), rc(_rc), cnt(_cnt) {}
};

struct SegmentTree
{
	int p, r, m, lazy;
	data w;
};

link e[MAXN << 1];
SegmentTree tree[1 << 18];
int head[MAXN], cnt;
int n, T, R, opt, u, v, w, c[MAXN];
int pos[MAXN], top[MAXN], father[MAXN];
int dep[MAXN], siz[MAXN], bel[MAXN], maxx[MAXN];

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
		if (e[i].to != father[x])
		{
			dep[e[i].to] = dep[x] + 1;
			father[e[i].to] = x;
			dfs1(e[i].to);
			siz[x] += siz[e[i].to];
			if (!~maxx[x] || siz[maxx[x]] < siz[e[i].to]) maxx[x] = e[i].to;
		}
	return ;
}

inline void dfs2(int x, int t)
{
	top[x] = t;
	bel[++R] = x;
	pos[x] = R;
	if (~maxx[x]) dfs2(maxx[x], t);
	for (int i = head[x]; ~i; i = e[i].nxt)
		if (e[i].to != maxx[x] && e[i].to != father[x]) dfs2(e[i].to, e[i].to);
	return ;
}

inline void Push_Up(int u)
{
	data a = tree[u << 1].w, b = tree[u << 1 | 1].w;
	tree[u].w = data(a.lc, b.rc, a.cnt + b.cnt - (a.rc == b.lc));
	return ;
}

inline void Push_Down(int u)
{
	if (~tree[u].lazy)
	{
		tree[u << 1].lazy = tree[u << 1 | 1].lazy = tree[u].lazy;
		tree[u << 1].w = tree[u << 1 | 1].w = data(tree[u].lazy, tree[u].lazy, 1);
		tree[u].lazy = -1;
	}
	return ;
}

inline void Build_A_Tree(int u)
{
	tree[u].lazy = -1;
	if (tree[u].p + 1 == tree[u].r)
	{
		tree[u].w = data(c[bel[tree[u].p]], c[bel[tree[u].p]], 1);
		return ;
	}
	tree[u].m = tree[u].p + tree[u].r >> 1;
	tree[u << 1].p = tree[u].p;
	tree[u << 1].r = tree[u].m;
	Build_A_Tree(u << 1);
	tree[u << 1 | 1].p = tree[u].m;
	tree[u << 1 | 1].r = tree[u].r;
	Build_A_Tree(u << 1 | 1);
	Push_Up(u);
	return ;
}

inline void modify(int u, int l, int r, int c)
{
	if (tree[u].p == l && tree[u].r == r)
	{
		tree[u].lazy = c;
		tree[u].w = data(c, c, 1);
		return ;
	}
	Push_Down(u);
	if (r <= tree[u].m) modify(u << 1, l, r, c);
	else if (tree[u].m <= l) modify(u << 1 | 1, l, r, c);
	else
	{
		modify(u << 1, l, tree[u].m, c);
		modify(u << 1 | 1, tree[u].m, r, c);
	}
	Push_Up(u);
	return ;
}

inline data query(int u, int l, int r)
{
	if (tree[u].p == l && tree[u].r == r) return tree[u].w;
	Push_Down(u);
	if (r <= tree[u].m) return query(u << 1, l, r);
	else if (tree[u].m <= l) return query(u << 1 | 1, l, r);
	else
	{
		data a = query(u << 1, l, tree[u].m), b = query(u << 1 | 1, tree[u].m, r);
		return data(a.lc, b.rc, a.cnt + b.cnt - (a.rc == b.lc));
	}
}

inline void C(int l, int r, int c)
{
	while (top[l] != top[r])
	{
		if (dep[top[l]] < dep[top[r]]) swap(l, r);
		modify(1, pos[top[l]], pos[l] + 1, c);
		l = father[top[l]];
	}
	if (pos[l] > pos[r]) swap(l, r);
	modify(1, pos[l], pos[r] + 1, c);
	return ;
}

inline int Q(int l, int r)
{
	int res = 0, lc = -1, rc = -1;
	data t;
	while (top[l] != top[r])
	{
		if (dep[top[l]] < dep[top[r]])
		{
			swap(l, r);
			swap(lc, rc);
		}
		t = query(1, pos[top[l]], pos[l] + 1);
		res += t.cnt - (t.rc == lc);
		lc = t.lc;
		l = father[top[l]];
	}
	if (pos[l] > pos[r])
	{
		swap(l, r);
		swap(lc, rc);
	}
	t = query(1, pos[l], pos[r] + 1);
	res += t.cnt - (t.rc == rc) - (t.lc == lc);
	return res;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == 'Q')
		{
			x = 1;
			return ;
		}
		if (ch == 'C')
		{
			x = 0;
			return ;
		}
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return ;
}

int main()
{
	//freopen("paint.in","r",stdin);freopen("paint.out","w",stdout);
	memset(head, -1, sizeof head);
	read(n);
	read(T);
	for (int i = 1; i <= n; i++) read(c[i]);
	for (int i = 1; i < n; i++)
	{
		read(u);
		read(v);
		add(u, v);
	}
	dfs1(1);
	dfs2(1, 1);
	tree[1].p = 1;
	tree[1].r = n + 1;
	Build_A_Tree(1);
	while (T--)
	{
		read(opt);
		if (!opt)
		{
			read(u);
			read(v);
			read(w);
			C(u, v, w);
		}
		else
		{
			read(u);
			read(v);
			printf("%d\n", Q(u, v));
		}
	}
	return 0;
}