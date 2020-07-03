#include <bits/stdc++.h>
#define MAXN 1<<17
using namespace std;

const long long MOD = 998244353LL;
const long long G = 3LL;

long long a[MAXN], b[MAXN], invn;
int n, m, L, rev[MAXN];
long long f[MAXN][2][2], g[MAXN], h[MAXN][2], ans;

inline long long fpow(long long a, long long b)
{
	long long r = 1;
	for (; b; b >>= 1, (a *= a) %= MOD) if (b & 1) (r *= a) %= MOD;
	return r;
}

inline void NTT(long long c[], int n, int f)
{
	long long w, wn, x, y;
	for (int i = 0; i < n; i++)
		if (i < rev[i]) swap(c[i], c[rev[i]]);
	for (int i = 1; i < n; i <<= 1)
	{
		wn = fpow(G, (MOD - 1) / (i << 1));
		if (!~f) wn = fpow(wn, MOD - 2);
		for (int p = i << 1, j = 0; j < n; j += p)
		{
			w = 1LL;
			for (int k = 0; k < i; k++, w = w * wn % MOD)
			{
				x = c[j + k];
				y = c[j + k + i] * w % MOD;
				c[j + k] = (x + y) % MOD;
				c[j + k + i] = (x - y + MOD) % MOD;
			}
		}
	}
	if (!~f)
		for (int i = 0; i < n; i++) c[i] = c[i] * invn % MOD;
	return ;
}

inline void NTT_Prepare(int n)
{
	for (m = 1, L = 0; m <= (n << 1); L++, m <<= 1);
	for (int i = 0; i < m; i++) a[i] = b[i] = 0;
	invn = fpow(m, MOD - 2);
	for (int i = 0; i < m; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (L - 1));
	return ;
}

inline void NTT_Work()
{
	NTT(a, m, 1); NTT(b, m, 1);
	for (int i = 0; i < m; i++) a[i] = (a[i] * b[i]) % MOD;
	NTT(a, m, -1);
	return ;
}

void DP(int l, int r, int m, int x, int y)
{
	NTT_Prepare(r - l + 1);
	for (int i = l; i <= m; i++) a[i - l] = h[i][x];
	for (int i = 0; i <= r - l; i++) b[i] = f[i][x][y];
	NTT_Work();
	for (int i = m + 1; i <= r; i++) h[i][y] = (h[i][y] + a[i - l]) % MOD;
	return ;
}

inline void DC(int l, int r)
{
	if (l == r) return ;
	int m = l + r >> 1;
	DC(l, m);
	for (int i = 0; i <= 1; i++)
		for (int j = 0; j <= 1; j++)
			DP(l, r, m, i, j);
	DC(m + 1, r);
	return ;
}

int main()
{
	scanf("%d", &n);
	g[0] = 1;
	for (int i = 1; i <= n; i++) g[i] = ((i < 2 ? 0 : g[i - 2]) + (i < 4 ? 0 : g[i - 4])) % MOD;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= 1; j++)
			for (int k = 0; k <= 1; k++)
				f[i][j][k] = (i - 1 - j - k >= 0) ? g[i - 1 - j - k] * (i - 1) % MOD * (i - 1) % MOD: 0;
	h[0][0] = 1;
	DC(0, n - 1);
	for (int i = 0; i < n; i++)
		for (int v = 0; v <= 1; v++)
			ans = (ans + h[i][v] * f[n - i][v][0] % MOD * (n - i)) % MOD;
	memset(h, 0, sizeof h);
	h[0][1] = 1;
	DC(0, n - 1);
	for (int i = 0; i < n; i++)
		for (int v = 0; v <= 1; v++)
			ans = (ans + h[i][v] * f[n - i][v][1] % MOD * (n - i)) % MOD;
	printf("%lld\n", ans);
	return 0;
}