#include <stdio.h>

struct SegmentTree
{
	int p, r, m;
	long long x, l;
};

SegmentTree tree[1 << 21];
int n, m, o, x, y, z;

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

inline void modify(int u, int l, int r, long long v)
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
	tree[u].x = tree[u << 1].x + tree[u << 1 | 1].x;
	return ;
}

inline long long query(int u, int l, int r)
{
	if (tree[u].p == l && tree[u].r == r) return tree[u].x;
	Push_Down(u);
	if (r <= tree[u].m) return query(u << 1, l, r);
	else if (tree[u].m <= l) return query(u << 1 | 1, l, r);
	else return query(u << 1, l, tree[u].m) + query(u << 1 | 1, tree[u].m, r);
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
		read(z);
		if (!o) modify(1, x, y + 1, z);
		else printf("%lld\n", query(1, x, y + 1));
	}
	return 0;
}