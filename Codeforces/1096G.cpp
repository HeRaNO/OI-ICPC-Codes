#include <bits/stdc++.h>
#define MAXN 1<<21
using namespace std;

namespace numberTheoryTransform
{
	inline long long Quick_MOD(long long a, long long b, long long MOD)
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

	long long a[MAXN];
	int n, m, L, rev[MAXN];
	long long g = 3, invn, MOD = 998244353LL;

	inline void NTT(long long c[], int n, int f)
	{
		long long w, wn, x, y;
		for (int i = 0; i < n; i++)
			if (i < rev[i]) swap(c[i], c[rev[i]]);
		for (int i = 1; i < n; i <<= 1)
		{
			wn = Quick_MOD(g, (MOD - 1) / (i << 1), MOD);
			if (!~f) wn = Quick_MOD(wn, MOD - 2, MOD);
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
		for (m = 1, L = 0; m < (n << 1); L++, m <<= 1);
		invn = Quick_MOD(m, MOD - 2, MOD);
		for (int i = 0; i < m; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (L - 1));
		return ;
	}

	inline void NTT_Work()
	{
		NTT(a, m, 1);
		for (int i = 0; i < m; i++) a[i] = Quick_MOD(a[i], n, MOD);
		NTT(a, m, -1);
		return ;
	}
}

int N, k, x;
long long ans;

int main()
{
	using namespace numberTheoryTransform;
	scanf("%d %d", &N, &k);
	for (int i = 1; i <= k; i++) scanf("%d", &x), a[x] = 1LL;
	NTT_Prepare(N * 5 + 1); n = N >> 1;
	NTT_Work();
	for (int i = 0; i < m; i++) ans = (ans + a[i] * a[i] % MOD) % MOD;
	printf("%lld\n", ans);
	return 0;
}