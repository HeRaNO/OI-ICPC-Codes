#include <cstdio>
int main()
{
	long long a, b, MOD, ans = 0;
	scanf("%lld %lld %lld", &a, &b, &MOD);
	a %= MOD;
	b %= MOD;
	if (a < b)
	{
		int t = a;
		a = b;
		b = t;
	}
	for (; b; (a <<= 1LL) %= MOD, b >>= 1LL) if (b & 1)(ans += a) %= MOD;
	printf("%lld\n", ans);
	return 0;
}