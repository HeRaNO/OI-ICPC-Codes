#include <cstdio>
#define MAXN 100010
using namespace std;

struct SegmentTree
{
	int l, r, m;
	long long sum, add, mul;
};

SegmentTree tree[1 << 18];
int n, T, a[MAXN], opt, l, r;
long long p, c;

void Build_A_Tree(int u)
{
	tree[u].mul = 1;
	if (tree[u].l + 1 == tree[u].r)
	{
		tree[u].sum = a[tree[u].l] % p;
		return ;
	}
	tree[u].m = tree[u].l + tree[u].r >> 1;
	tree[u << 1].l = tree[u].l;
	tree[u << 1].r = tree[u].m;
	Build_A_Tree(u << 1);
	tree[u << 1 | 1].l = tree[u].m;
	tree[u << 1 | 1].r = tree[u].r;
	Build_A_Tree(u << 1 | 1);
	tree[u].sum = (tree[u << 1].sum + tree[u << 1 | 1].sum) % p;
	return ;
}

inline void lazy(int u)
{
	if (tree[u].mul == 1 && !tree[u].add) return;
	tree[u << 1].add = (tree[u << 1].add * tree[u].mul + tree[u].add) % p;
	tree[u << 1 | 1].add = (tree[u << 1 | 1].add * tree[u].mul + tree[u].add) % p;
	tree[u << 1].mul = (tree[u << 1].mul * tree[u].mul) % p;
	tree[u << 1 | 1].mul = (tree[u << 1 | 1].mul * tree[u].mul) % p;
	tree[u << 1].sum = (tree[u << 1].sum * tree[u].mul + (tree[u << 1].r - tree[u << 1].l) * tree[u].add) % p;
	tree[u << 1 | 1].sum = (tree[u << 1 | 1].sum * tree[u].mul + (tree[u << 1 | 1].r - tree[u << 1 | 1].l) * tree[u].add) % p;
	tree[u].add = 0;
	tree[u].mul = 1;
	return ;
}

void modify_add(int u, int l, int r, long long x)
{
	if (tree[u].l == l && tree[u].r == r)
	{
		tree[u].add = (tree[u].add + x) % p;
		tree[u].sum = (tree[u].sum + (tree[u].r - tree[u].l) * x) % p;
		return ;
	}
	lazy(u);
	if (r <= tree[u].m) modify_add(u << 1, l, r, x);
	else if (tree[u].m <= l) modify_add(u << 1 | 1, l, r, x);
	else
	{
		modify_add(u << 1, l, tree[u].m, x);
		modify_add(u << 1 | 1, tree[u].m, r, x);
	}
	tree[u].sum = (tree[u << 1].sum + tree[u << 1 | 1].sum) % p;
	return ;
}

void modify_mul(int u, int l, int r, long long x)
{
	if (tree[u].l == l && tree[u].r == r)
	{
		tree[u].add = (tree[u].add * x) % p;
		tree[u].mul = (tree[u].mul * x) % p;
		tree[u].sum = (tree[u].sum * x) % p;
		return;
	}
	lazy(u);
	if (r <= tree[u].m) modify_mul(u << 1, l, r, x);
	else if (tree[u].m <= l) modify_mul(u << 1 | 1, l, r, x);
	else
	{
		modify_mul(u << 1, l, tree[u].m, x);
		modify_mul(u << 1 | 1, tree[u].m, r, x);
	}
	tree[u].sum = (tree[u << 1].sum + tree[u << 1 | 1].sum) % p;
	return;
}

long long query(int u, int l, int r)
{
	if (tree[u].l == l && tree[u].r == r) return tree[u].sum % p;
	lazy(u);
	if (r <= tree[u].m) return query(u << 1, l, r);
	else if (tree[u].m <= l) return query(u << 1 | 1, l, r);
	else return (query(u << 1, l, tree[u].m) + query(u << 1 | 1, tree[u].m, r)) % p;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return ;
}

inline void read(long long &x)
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
	read(p);
	for (int i = 1; i <= n; i++) read(a[i]);
	tree[1].l = 1;
	tree[1].r = n + 1;
	Build_A_Tree(1);
	read(T);
	while (T--)
	{
		read(opt);
		read(l);
		read(r);
		opt -= 2;
		if ((!~opt) || (!opt))
		{
			read(c);
			if (!~opt) modify_mul(1, l, r + 1, c % p);
			else modify_add(1, l, r + 1, c % p);
		}
		else printf("%lld\n", query(1, l, r + 1) % p);
	}
	return 0;
}