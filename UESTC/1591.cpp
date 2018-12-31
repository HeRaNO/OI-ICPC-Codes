#include <cstdio>
#include <algorithm>
#define fi first
#define se second
#define mp make_pair
using namespace std;

struct SegmentTree
{
	int p, r, m, mx, mn;
};

SegmentTree tree[1 << 17];
int n, T, l, r, a[50010];

inline int max(int a, int b)
{
	return a > b ? a : b;
}
inline int min(int a, int b)
{
	return a < b ? a : b;
}

inline void BuildTree(int u)
{
	if (tree[u].p + 1 == tree[u].r)
	{
		tree[u].mx = tree[u].mn = a[tree[u].p];
		return ;
	}
	tree[u].m = tree[u].p + tree[u].r >> 1;
	tree[u << 1].p = tree[u].p;
	tree[u << 1].r = tree[u].m;
	BuildTree(u << 1);
	tree[u << 1 | 1].p = tree[u].m;
	tree[u << 1 | 1].r = tree[u].r;
	BuildTree(u << 1 | 1);
	tree[u].mx = max(tree[u << 1].mx, tree[u << 1 | 1].mx);
	tree[u].mn = min(tree[u << 1].mn, tree[u << 1 | 1].mn);
	return ;
}

inline pair<int, int> query(int u, int l, int r)
{
	if (tree[u].p == l && tree[u].r == r) return mp(tree[u].mx, tree[u].mn);
	if (r <= tree[u].m) return query(u << 1, l, r);
	else if (tree[u].m <= l) return query(u << 1 | 1, l, r);
	else
	{
		pair <int, int> a, b;
		a = query(u << 1, l, tree[u].m);
		b = query(u << 1 | 1, tree[u].m, r);
		return mp(max(a.fi, b.fi), min(a.se, b.se));
	}
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
	read(T);
	for (int i = 1; i <= n; i++) read(a[i]);
	tree[1].p = 1;
	tree[1].r = n + 1;
	BuildTree(1);
	while (T--)
	{
		read(l);
		read(r);
		pair <int, int> p = query(1, l, r + 1);
		printf("%d\n", p.fi - p.se);
	}
	return 0;
}