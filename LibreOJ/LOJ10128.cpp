#include <cmath>
#include <cstdio>
#define MAXN 100010
using namespace std;

struct SegmentTree
{
	int p, r, m;
	long long x, mx;
};

SegmentTree tree[1 << 18 | 1];
int n, T, a[MAXN], opt, l, r;

long long max(long long a, long long b)
{
	return a > b ? a : b;
}
long long min(long long a, long long b)
{
	return a < b ? a : b;
}

void BuildTree(int u)
{
	if (tree[u].p + 1 == tree[u].r)
	{
		tree[u].x = tree[u].mx = a[tree[u].p];
		return ;
	}
	tree[u].m = tree[u].p + tree[u].r >> 1;
	tree[u << 1].p = tree[u].p;
	tree[u << 1].r = tree[u].m;
	BuildTree(u << 1);
	tree[u << 1 | 1].p = tree[u].m;
	tree[u << 1 | 1].r = tree[u].r;
	BuildTree(u << 1 | 1);
	tree[u].x = tree[u << 1].x + tree[u << 1 | 1].x;
	tree[u].mx = max(tree[u << 1].mx, tree[u << 1 | 1].mx);
	return ;
}

void modify(int u, int l, int r)
{
	if (tree[u].mx <= 1) return ;
	if (tree[u].p + 1 == tree[u].r)
	{
		tree[u].x = tree[u].mx = (long long)sqrt(tree[u].x);
		return ;
	}
	if (r <= tree[u].m) modify(u << 1, l, r);
	else if (tree[u].m <= l) modify(u << 1 | 1, l, r);
	else
	{
		modify(u << 1, l, tree[u].m);
		modify(u << 1 | 1, tree[u].m, r);
	}
	tree[u].x = tree[u << 1].x + tree[u << 1 | 1].x;
	tree[u].mx = max(tree[u << 1].mx, tree[u << 1 | 1].mx);
	return ;
}

long long query(int u, int l, int r)
{
	if (tree[u].p == l && tree[u].r == r) return tree[u].x;
	if (r <= tree[u].m) return query(u << 1, l, r);
	else if (tree[u].m <= l) return query(u << 1 | 1, l, r);
	else return query(u << 1, l, tree[u].m) + query(u << 1 | 1, tree[u].m, r);
}

void read(int &x)
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
	read(T);
	while (T--)
	{
		read(opt);
		read(l);
		read(r);
		if (opt == 1) printf("%lld\n", query(1, l, r + 1));
		else modify(1, l, r + 1);
	}
	return 0;
}