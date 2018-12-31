#include <cstdio>
#define MAXN 200010
#define MOD 1000000007LL
using namespace std;

struct Linear_Function
{
	long long k, b;
	Linear_Function() {}
	Linear_Function(int _k, int _b): k(_k), b(_b) {}

} res;

struct SegmentTree
{
	int p, r, m;
	Linear_Function f;
};

int n, T, l, r, x, opt;
Linear_Function a[MAXN];
SegmentTree tree[1 << 19];

inline Linear_Function Merge(Linear_Function l, Linear_Function r)
{
	return Linear_Function(l.k * r.k % MOD, ((r.k * l.b) % MOD + r.b) % MOD);
}

inline void Build_A_Tree(int u)
{
	if (tree[u].p + 1 == tree[u].r)
	{
		tree[u].f = a[tree[u].p];
		return ;
	}
	tree[u].m = tree[u].p + tree[u].r >> 1;
	tree[u << 1].p = tree[u].p;
	tree[u << 1].r = tree[u].m;
	Build_A_Tree(u << 1);
	tree[u << 1 | 1].p = tree[u].m;
	tree[u << 1 | 1].r = tree[u].r;
	Build_A_Tree(u << 1 | 1);
	tree[u].f = Merge(tree[u << 1].f, tree[u << 1 | 1].f);
}

inline void modify(int u, int x, Linear_Function v)
{
	if (tree[u].p + 1 == tree[u].r)
	{
		tree[u].f = v;
		return ;
	}
	if (x < tree[u].m) modify(u << 1, x, v);
	else modify(u << 1 | 1, x, v);
	tree[u].f = Merge(tree[u << 1].f, tree[u << 1 | 1].f);
	return ;
}

inline Linear_Function query(int u, int l, int r)
{
	if (tree[u].p == l && tree[u].r == r) return tree[u].f;
	if (r <= tree[u].m) return query(u << 1, l, r);
	else if (tree[u].m <= l) return query(u << 1 | 1, l, r);
	else return Merge(query(u << 1, l, tree[u].m), query(u << 1 | 1, tree[u].m, r));
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == 'M')
		{
			x = 0;
			return ;
		}
		if (ch == 'Q')
		{
			x = 1;
			return ;
		}
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return ;
}

inline void read(long long &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10LL + ch - '0', ch = getchar();
	return ;
}

int main()
{
	read(n);
	read(T);
	for (int i = 1; i <= n; i++) read(a[i].k), read(a[i].b);
	tree[1].p = 1;
	tree[1].r = n + 1;
	Build_A_Tree(1);
	while (T--)
	{
		read(opt);
		read(l);
		read(r);
		read(x);
		if (!opt) modify(1, l, Linear_Function(r, x));
		else
		{
			res = query(1, l, r + 1);
			printf("%d\n", (res.k * (long long)x % MOD + res.b) % MOD);
		}
	}
	return 0;
}