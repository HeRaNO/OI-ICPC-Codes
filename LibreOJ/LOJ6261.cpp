#include <cstdio>
#include <algorithm>
#define MAXN 1<<18
using namespace std;

const long long MOD = 998244353LL;
const long long g = 3LL;

int n, m, L, rev[MAXN];
long long a[MAXN], c[MAXN], inv[MAXN], x = 1LL, invn, k;

inline long long Pow(long long a, long long b)
{
	long long r = 1, t = a;
	while (b)
	{
		if (b & 1) r = (r * t) % MOD;
		t = (t * t) % MOD;
		b >>= 1;
	}
	return r;
}

inline void NTT(long long c[], int n, int f)
{
	long long w, wn, x, y;
	for (int i = 0; i < n; i++)
		if (i < rev[i]) swap(c[i], c[rev[i]]);
	for (int i = 1; i < n; i <<= 1)
	{
		wn = Pow(g, (MOD - 1) / (i << 1));
		if (!~f) wn = Pow(wn, MOD - 2);
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

inline long long read()
{
	long long x = 0LL;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3LL) + (x << 1LL) + ch - '0', ch = getchar();
	return x;
}

int main()
{
	//freopen("one.in","r",stdin);freopen("one.out","w",stdout);
	n = read();
	k = read();
	inv[1] = 1LL;
	k %= MOD;
	for (m = 1, L = 0; m < (n << 1); L++, m <<= 1);
	invn = Pow(m, MOD - 2);
	for (int i = 0; i < m; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (L - 1));
	for (int i = 0; i < n; i++) a[i] = read();
	for (int i = 2; i <= n; i++) inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
	for (int i = 1; i <= n; i++)
	{
		c[i] = x;
		(x *= (i + k - 1)) %= MOD;
		x = x * inv[i] % MOD;
	}
	for (int i = 1; i <= n; i++) c[i - 1] = c[i];
	c[n] = 0LL;
	NTT(a, m, 1);
	NTT(c, m, 1);
	for (int i = 0; i < m; i++) a[i] = (a[i] * c[i]) % MOD;
	NTT(a, m, -1);
	for (int i = 0; i < n; i++) printf("%lld\n", a[i]);
	return 0;
}