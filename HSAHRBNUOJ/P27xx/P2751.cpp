#include <cstdio>
#define MAXN 300010
using namespace std;

struct SegmentTree
{
	int p, r, m, x;
};

SegmentTree tree[1 << 20];
int n, L, R;
int ice[MAXN], dp[MAXN];

inline int mymax(int a, int b)
{
	return a > b ? a : b;
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

inline void modify(int u, int x, int v)
{
	if (tree[u].p + 1 == tree[u].r)
	{
		tree[u].x = v;
		return ;
	}
	if (x < tree[u].m) modify(u << 1, x, v);
	else modify(u << 1 | 1, x, v);
	tree[u].x = mymax(tree[u << 1].x, tree[u << 1 | 1].x);
	return ;
}

inline int query(int u, int l, int r)
{
	if (tree[u].p == l && tree[u].r == r) return tree[u].x;
	if (r <= tree[u].m) return query(u << 1, l, r);
	else if (tree[u].m <= l) return query(u << 1 | 1, l, r);
	else return mymax(query(u << 1, l, tree[u].m), query(u << 1 | 1, tree[u].m, r));
}

inline void read(int &x)
{
	x = 0;
	int f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	x *= f;
	return ;
}

int main()
{
	read(n);
	read(L);
	read(R);
	for (int i = 0; i <= n; i++) read(ice[i]);
	tree[1].p = 0;
	tree[1].r = n + R + 1;
	Build_A_Tree(1);
	for (int i = L; i <= n + R; i++)
	{
		dp[i] = query(1, mymax(0, i - R), i - L + 1) + ice[i];
		modify(1, i, dp[i]);
	}
	printf("%d\n", query(1, n + 1, n + R + 1));
	return 0;
}
