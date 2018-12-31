#include <stdio.h>

struct data
{
	long long mx, mn, x;
} w;

struct SegmentTree
{
	int p, r, m;
	data w;
	long long l;
};

SegmentTree tree[1 << 21];
int n, m, o, x, y;

inline long long max(long long a, long long b)
{
	return a > b ? a : b;
}
inline long long min(long long a, long long b)
{
	return a < b ? a : b;
}

inline data merge(data a, data b)
{
	data c;
	c.mx = max(a.mx, b.mx);
	c.mn = min(a.mn, b.mn);
	c.x = a.x + b.x;
	return c;
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

inline void modify(int u, int x, long long v)
{
	if (tree[u].p + 1 == tree[u].r)
	{
		tree[u].w.mx = tree[u].w.mn = tree[u].w.x = v;
		return ;
	}
	if (x < tree[u].m) modify(u << 1, x, v);
	else modify(u << 1 | 1, x, v);
	tree[u].w = merge(tree[u << 1].w, tree[u << 1 | 1].w);
	return ;
}

inline data query(int u, int l, int r)
{
	if (tree[u].p == l && tree[u].r == r) return tree[u].w;
	if (r <= tree[u].m) return query(u << 1, l, r);
	else if (tree[u].m <= l) return query(u << 1 | 1, l, r);
	else return merge(query(u << 1, l, tree[u].m), query(u << 1 | 1, tree[u].m, r));
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	bool f = false;
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = true;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	if (f) x = -x;
	return ;
}

int main()
{
	read(n);
	read(m);
	tree[1].p = 1;
	tree[1].r = n + 1;
	BuildTree(1);
	while (m--)
	{
		read(o);
		read(x);
		read(y);
		if (!o) modify(1, x, y);
		else
		{
			w = query(1, x, y + 1);
			printf("%lld\n", w.x - w.mx - w.mn);
		}
	}
	return 0;
}