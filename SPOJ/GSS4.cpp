#include <cmath>
#include <cstdio>
#include <algorithm>
#define MAXN 100010
using namespace std;

struct SegmentTree
{
	int p, r, m;
	int left, right;
	long long sum, mx;
};

SegmentTree tree[MAXN * 2];
int n, T, top, opt, u, v, cas;
long long a[MAXN];

inline long long read()
{
	long long x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10LL + ch - '0', ch = getchar();
	return x * f;
}

inline long long mymax(long long a, long long b)
{
	return a > b ? a : b;
}

void Build_A_Tree(int u)
{
	tree[u].sum = tree[u].mx = 0LL;
	if (tree[u].p + 1 == tree[u].r)
	{
		tree[u].mx = tree[u].sum = a[tree[u].p];
		return ;
	}
	tree[u].m = (tree[u].p + tree[u].r) >> 1;
	top++;
	tree[u].left = top;
	tree[top].p = tree[u].p;
	tree[top].r = tree[u].m;
	Build_A_Tree(top);
	top++;
	tree[u].right = top;
	tree[top].p = tree[u].m;
	tree[top].r = tree[u].r;
	Build_A_Tree(top);
	tree[u].sum = tree[tree[u].left].sum + tree[tree[u].right].sum;
	tree[u].mx = mymax(tree[tree[u].left].mx, tree[tree[u].right].mx);
	return ;
}

void modify(int u, int l, int r)
{
	if (tree[u].mx == 1) return ;
	if (tree[u].p + 1 == tree[u].r)
	{
		tree[u].sum = tree[u].mx = (int)sqrt(tree[u].sum);
		return ;
	}
	if (tree[u].m >= r) modify(tree[u].left, l, r);
	else if (tree[u].m <= l) modify(tree[u].right, l, r);
	else
	{
		modify(tree[u].left, l, tree[u].m);
		modify(tree[u].right, tree[u].m, r);
	}
	tree[u].mx = mymax(tree[tree[u].left].mx, tree[tree[u].right].mx);
	tree[u].sum = tree[tree[u].left].sum + tree[tree[u].right].sum;
	return ;
}

long long query(int u, int l, int r)
{
	if (tree[u].p == l && tree[u].r == r) return tree[u].sum;
	if (tree[u].m >= r) return query(tree[u].left, l, r);
	else if (tree[u].m <= l) return query(tree[u].right, l, r);
	else return query(tree[u].left, l, tree[u].m) + query(tree[u].right, tree[u].m, r);
}

int main()
{
	while (~scanf("%d", &n))
	{
		printf("Case #%d:\n", ++cas);
		for (int i = 1; i <= n; i++) a[i] = read();
		tree[1].p = 1;
		tree[1].r = n + 1;
		top = 1;
		Build_A_Tree(1);
		T = read();
		while (T--)
		{
			opt = read();
			u = read();
			v = read();
			if (u > v) swap(u, v);
			if (opt) printf("%lld\n", query(1, u, v + 1));
			else modify(1, u, v + 1);
		}
		printf("\n");
	}
	return 0;
}
