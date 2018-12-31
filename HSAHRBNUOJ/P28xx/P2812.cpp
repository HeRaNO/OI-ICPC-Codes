#include <cstdio>
using namespace std;

long long n, m, k, MOD, res;
long long mymin(long long a, long long b)
{
	return a < b ? a : b;
}

long long quick_MOD(long long a, long long k)
{
	long long res = 1, d = a;
	while (k)
	{
		if (k & 1LL) res = res * d % MOD;
		d = d * d % MOD;
		k >>= 1LL;
	}
	return res % MOD;
}

int main()
{
	//freopen("sesame.in","r",stdin);freopen("sesame.out","w",stdout);
	scanf("%lld %lld %lld", &n, &m, &k);
	MOD = n + m;
	res = (n * quick_MOD(2LL, k)) % MOD;
	printf("%lld\n", mymin(res, MOD - res));
	return 0;
}
