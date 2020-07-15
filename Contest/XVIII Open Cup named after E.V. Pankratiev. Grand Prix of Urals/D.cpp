#include <bits/stdc++.h>
#define MAXN 10000005
using namespace std;

const long long M = 1e9 + 7;

int n;
long long fac[MAXN], inv[MAXN], invfac[MAXN];

inline void fadd(long long &x, long long y)
{
	x += y;
	if (x >= M)
		x -= M;
}

inline long long fpow(long long a, long long b)
{
	long long r = 1;
	for (; b; b >>= 1, (a *= a) %= M)
		if (b & 1)
			(r *= a) %= M;
	return r;
}

inline void init(int n)
{
	fac[0] = invfac[0] = inv[1] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = fac[i - 1] * i % M;
	for (int i = 2; i <= n; i++)
		inv[i] = (M - M / i) * inv[M % i] % M;
	for (int i = 1; i <= n; i++)
		invfac[i] = invfac[i - 1] * inv[i] % M;
	return;
}

inline long long C(int n, int m)
{
	if (n < m)
		return 0;
	return fac[n] * invfac[m] % M * invfac[n - m] % M;
}
int m;
inline long long Calc(int c)
{
	long long ans = 0;
	for (int k = 0; k <= m; k++)
	{
		long long t = C(m, k);
		(t *= C(c + m - 1 - 10 * k, m - 1)) %= M;
		if (k & 1)
			t = M - t;
		fadd(ans, t);
	}
	return ans;
}

int main()
{
	scanf("%d", &n);
	if (!(n & 1))
		return printf("%lld\n", fpow(10, n >> 1)), 0;
	init(10000000);
	long long ans = 0;
	int ou = n / 2, ji = n - n / 2;
	int c = ou * 9;
	(((n + 1) / 2) & 1) ? ji-- : ou--;
	m = (ji / 2 + ou / 2);
	for (int i = 0; i <= 9; i++)
	{
		if (c - i < 0 || ((c - i) & 1))
			continue;
		long long tmp = Calc((c - i) >> 1);
		fadd(ans, tmp);
	}
	printf("%lld\n", ans);
	// system("pause");
	return 0;
}