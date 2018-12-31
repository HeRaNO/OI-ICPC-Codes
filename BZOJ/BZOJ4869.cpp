#include <cstdio>
#define MAXN 50010
#define logP 32
#define mymin(a,b) (a)<(b)?(a):(b)
using namespace std;

struct SegmentTree
{
	int p, r, m, updcnt, sum;
};

SegmentTree tree[1 << 17];
int n, T, c, MOD, opt, l, r;
int p[logP], cnt, a[MAXN];
int table[logP][1 << 14][2];

inline int Quick_Mod(long long a, long long b, long long p)
{
	long long res = 1;
	while (b)
	{
		if (b & 1LL) res = res * a % p;
		a = a * a % p;
		b >>= 1LL;
	}
	return res;
}

inline int phi(int x)
{
	int res = x;
	for (int i = 2; i * i <= x; i++)
		if (!(x % i))
		{
			res /= i;
			res *= (i - 1);
			while (!(x % i)) x /= i;
		}
	if (x != 1) res /= x, res *= (x - 1);
	return res;
}

inline int Power(int a, int b)
{
	return 1LL * table[b][a & 16383][0] * table[b][a >> 14][1] % p[b];
}

inline int Calc(int x, int t)
{
	int res = x;
	if (res >= p[t]) res = res % p[t] + p[t];
	while (t--)
	{
		x = res;
		res = Power(x, t);
		if (t && !res) res += p[t];
	}
	return res % MOD;
}

inline void Push_Up(int u)
{
	tree[u].updcnt = mymin(tree[u << 1].updcnt, tree[u << 1 | 1].updcnt);
	tree[u].sum = (tree[u << 1].sum + tree[u << 1 | 1].sum) % MOD;
	return ;
}

inline void Build_A_Tree(int u)
{
	if (tree[u].p + 1 == tree[u].r)
	{
		tree[u].sum = a[tree[u].p];
		return ;
	}
	tree[u].m = tree[u].p + tree[u].r >> 1;
	tree[u << 1].p = tree[u].p;
	tree[u << 1].r = tree[u].m;
	Build_A_Tree(u << 1);
	tree[u << 1 | 1].p = tree[u].m;
	tree[u << 1 | 1].r = tree[u].r;
	Build_A_Tree(u << 1 | 1);
	Push_Up(u);
	return ;
}

inline void modify(int u, int l, int r)
{
	if (tree[u].updcnt >= cnt) return ;
	if (tree[u].p + 1 == tree[u].r)
	{
		tree[u].sum = Calc(a[l], ++tree[u].updcnt);
		return ;
	}
	if (r <= tree[u].m) modify(u << 1, l, r);
	else if (tree[u].m <= l) modify(u << 1 | 1, l, r);
	else
	{
		modify(u << 1, l, tree[u].m);
		modify(u << 1 | 1, tree[u].m, r);
	}
	Push_Up(u);
	return ;
}

inline int query(int u, int l, int r)
{
	if (tree[u].p == l && tree[u].r == r) return tree[u].sum % MOD;
	if (r <= tree[u].m) return query(u << 1, l, r);
	else if (tree[u].m <= l) return query(u << 1 | 1, l, r);
	else return (query(u << 1, l, tree[u].m) + query(u << 1 | 1, tree[u].m, r)) % MOD;
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
	//freopen("verbinden.in","r",stdin);freopen("verbinden.out","w",stdout);
	read(n);
	read(T);
	read(MOD);
	read(c);
	for (int i = 1; i <= n; i++) read(a[i]), a[i] %= MOD;
	p[0] = MOD;
	while (p[cnt] != 1) p[cnt + 1] = phi(p[cnt]), cnt++;
	p[++cnt] = 1;
	for (int i = 0; i <= cnt; i++)
	{
		r = Quick_Mod(c, 1 << 14, p[i]);
		table[i][0][0] = table[i][0][1] = 1;
		for (int j = 1; j < (1 << 14); j++)
		{
			table[i][j][0] = 1LL * table[i][j - 1][0] * c % p[i];
			table[i][j][1] = 1LL * table[i][j - 1][1] * r % p[i];
		}
	}
	tree[1].p = 1;
	tree[1].r = n + 1;
	Build_A_Tree(1);
	while (T--)
	{
		read(opt);
		read(l);
		read(r);
		if (!opt) modify(1, l, r + 1);
		else printf("%d\n", query(1, l, r + 1));
	}
	return 0;
}