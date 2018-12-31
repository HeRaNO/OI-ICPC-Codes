#include <cstdio>
#define MOD 1000000007LL
using namespace std;

long long n, k;

long long quick_pow(long long n, long long k)
{
	long long res = 1LL, d = n;
	while (k)
	{
		if (k & 1LL) res = (res * d) % MOD;
		d = (d * d) % MOD;
		k >>= 1LL;
	}
	return res % MOD;
}

int main()
{
	scanf("%lld %lld", &n, &k);
	printf("%lld\n", quick_pow(k, k - 1)*quick_pow((n - k) % MOD, n - k) % MOD);
	return 0;
}
