#include <stdio.h>

struct data
{
	long long suf, pre, all, ans;
};
struct SegmentTree
{
	int p, r, m;
	data w;
};

SegmentTree tree[1 << 18];
int n, m, x, a[100010];

inline long long max(long long a, long long b)
{
	return a > b ? a : b;
}

inline data merge(data a, data b)
{
	data c;
	c.all = a.all + b.all;
	c.ans = max(a.suf + b.pre, max(a.ans, b.ans));
	c.pre = max(a.pre, a.all + b.pre);
	c.suf = max(b.suf, a.suf + b.all);
	return c;
}

inline void BuildTree(int u)
{
	if (tree[u].p + 1 == tree[u].r)
	{
		tree[u].w.all = tree[u].w.ans = tree[u].w.suf = tree[u].w.pre = a[tree[u].p];
		return ;
	}
	tree[u].m = tree[u].p + tree[u].r >> 1;
	tree[u << 1].p = tree[u].p;
	tree[u << 1].r = tree[u].m;
	BuildTree(u << 1);
	tree[u << 1 | 1].p = tree[u].m;
	tree[u << 1 | 1].r = tree[u].r;
	BuildTree(u << 1 | 1);
	tree[u].w = merge(tree[u << 1].w, tree[u << 1 | 1].w);
	return ;
}

inline void modify(int u, int x)
{
	if (tree[u].p + 1 == tree[u].r)
	{
		tree[u].w.all = tree[u].w.ans = tree[u].w.suf = tree[u].w.pre = -1e14;
		return ;
	}
	if (x < tree[u].m) modify(u << 1, x);
	else modify(u << 1 | 1, x);
	tree[u].w = merge(tree[u << 1].w, tree[u << 1 | 1].w);
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
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	tree[1].p = 1;
	tree[1].r = n + 1;
	BuildTree(1);
	for (int i = 1; i < n; i++)
	{
		read(x);
		modify(1, x);
		printf("%lld\n", tree[1].w.ans);
	}
	puts("0");
	return 0;
}