#include <cstdio>
#include <algorithm>
#define MAXN 50010
using namespace std;

long long MOD;

struct matrix
{
	long long m[2][2];
	matrix operator * (const matrix &a) const
	{
		matrix res;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
			{
				res.m[i][j] = 0;
				for (int k = 0; k < 2; k++)
					res.m[i][j] = (res.m[i][j] + m[i][k] * a.m[k][j]) % MOD;
			}
		return res;
	}
};

struct SegmentTree
{
	int p, r, m;
	matrix mul;
};

SegmentTree tree[1 << 17];
long long k, pos;
int n, T;
long long a[MAXN];
pair <long long, long long> c[MAXN];
matrix ans, E, t;

matrix KSM(matrix x, long long k)
{
	matrix ans = E;
	while (k)
	{
		if (k & 1) ans = ans * x;
		x = x * x;
		k >>= 1LL;
	}
	return ans;
}

inline void Build_A_Tree(int u)
{
	if (tree[u].p + 1 == tree[u].r)
	{
		tree[u].mul.m[0][0] = 0;
		tree[u].mul.m[0][1] = a[tree[u].p];
		tree[u].mul.m[1][0] = 1;
		tree[u].mul.m[1][1] = a[tree[u].r];
		return ;
	}
	tree[u].m = tree[u].p + tree[u].r >> 1;
	tree[u << 1].p = tree[u].p;
	tree[u << 1].r = tree[u].m;
	Build_A_Tree(u << 1);
	tree[u << 1 | 1].p = tree[u].m;
	tree[u << 1 | 1].r = tree[u].r;
	Build_A_Tree(u << 1 | 1);
	tree[u].mul = tree[u << 1].mul * tree[u << 1 | 1].mul;
	return ;
}

inline matrix query(int u, int l, int r)
{
	if (tree[u].p == l && tree[u].r == r) return tree[u].mul;
	if (tree[u].m >= r) return query(u << 1, l, r);
	else if (tree[u].m <= l) return query(u << 1 | 1, l, r);
	else return query(u << 1, l, tree[u].m) * query(u << 1 | 1, tree[u].m, r);
}

inline matrix make_matrix(long long l, long long r)
{
	if (l == r) return E;
	long long blockl = l / n, blockr = r / n;
	int tl = l % n, tr = r % n;
	if (!tr) tr = n, blockr--;
	if (blockl == blockr) return query(1, tl, tr);
	return query(1, tl, n) * KSM(tree[1].mul, blockr - blockl - 1) * query(1, 0, tr);
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
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
	//freopen("sequence.in","r",stdin);freopen("sequence.out","w",stdout);
	E.m[0][0] = E.m[1][1] = 1;
	ans.m[0][1] = 1;
	read(k);
	read(MOD);
	read(n);
	for (int i = 0; i < n; i++) read(a[i]);
	a[n] = a[0];
	read(T);
	for (int i = 1; i <= T; i++) read(c[i].first), read(c[i].second);
	sort(c + 1, c + T + 1);
	tree[1].p = 0;
	tree[1].r = n;
	Build_A_Tree(1);
	for (int i = 1; i <= T;)
	{
		if (c[i].first > k) break;
		ans = ans * make_matrix(pos, c[i].first - 1);
		pos = c[i].first;
		t.m[0][0] = 0;
		t.m[0][1] = a[(c[i].first - 1) % n];
		t.m[1][0] = 1;
		t.m[1][1] = c[i].second;
		ans = ans * t;
		i++;
		while (i <= T && c[i].first == c[i - 1].first + 1)
		{
			t.m[0][1] = t.m[1][1];
			t.m[1][1] = c[i].second;
			ans = ans * t;
			i++;
			pos++;
		}
		if (pos == k - 1) break;
		t.m[0][1] = t.m[1][1];
		t.m[1][1] = a[(pos + 1) % n];
		ans = ans * t;
		pos++;
	}
	ans = ans * make_matrix(pos, k - 1);
	printf("%lld\n", ans.m[0][1]);
	return 0;
}
