#include <cstdio>
#define MAXN 300010
#define MOD 998244353LL
using namespace std;

struct SegmentTree
{
	int p, r, m, len;
	long long pos, neg;
};

SegmentTree tree[1 << 20];
int n, T, h, mxl;
long long _2pow[MAXN];

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}
inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

inline void Build_A_Tree(int u)
{
	tree[u].len = tree[u].r - tree[u].p;
	tree[u].neg = tree[u].pos = 0;
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

inline void modify(int u, int x)
{
	if (tree[u].p + 1 == tree[u].r)
	{
		tree[u].pos = tree[u].neg = 1LL;
		return ;
	}
	if (x < tree[u].m) modify(u << 1, x);
	else modify(u << 1 | 1, x);
	tree[u].pos = (tree[u << 1].pos * _2pow[tree[u << 1 | 1].len] % MOD + tree[u << 1 | 1].pos) % MOD;
	tree[u].neg = (tree[u << 1 | 1].neg * _2pow[tree[u << 1].len] % MOD + tree[u << 1].neg) % MOD;
	return ;
}

inline long long query_pos(int u, int l, int r)
{
	if (tree[u].p == l && tree[u].r == r) return tree[u].pos;
	if (r <= tree[u].m) return query_pos(u << 1, l, r);
	else if (tree[u].m <= l) return query_pos(u << 1 | 1, l, r);
	else
		return (query_pos(u << 1, l, tree[u].m) * _2pow[r - tree[u].m] % MOD + query_pos(u << 1 | 1, tree[u].m, r)) % MOD;
}

inline long long query_neg(int u, int l, int r)
{
	if (tree[u].p == l && tree[u].r == r) return tree[u].neg;
	if (r <= tree[u].m) return query_neg(u << 1, l, r);
	else if (tree[u].m <= l) return query_neg(u << 1 | 1, l, r);
	else
		return (query_neg(u << 1, l, tree[u].m) + query_neg(u << 1 | 1, tree[u].m, r) * _2pow[tree[u].m - l] % MOD) % MOD;
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
	_2pow[0] = 1LL;
	for (int i = 1; i < MAXN; i++) _2pow[i] = (_2pow[i - 1] << 1) % MOD;
	read(n);
	tree[1].p = 1;
	tree[1].r = n + 1;
	Build_A_Tree(1);
	for (int i = 1; i <= n; i++)
	{
		read(h);
		modify(1, h);
		mxl = mymin(h, n - h + 1);
		if (query_pos(1, h - mxl + 1, h + 1) != query_neg(1, h, h + mxl))
		{
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}