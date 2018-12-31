#include <cstdio>
#define MOD 1012LL

long long a, b;
int T;

long long KSM(long long a, long long k)
{
	long long res = 1, base = a;
	while (k)
	{
		if (k & 1) res = (res * base) % MOD;
		base = (base * base) % MOD;
		k >>= 1;
	}
	return res;
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lld %lld", &a, &b);
		printf("%lld\n", KSM(a % MOD, b));
	}
	return 0;
}
