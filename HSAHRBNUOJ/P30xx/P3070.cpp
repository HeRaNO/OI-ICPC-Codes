#include <cstdio>
#define MOD 1000
using namespace std;

int n, m;
long long ans;

long long KSM(int a, int b)
{
	long long res = 1, d = a;
	while (b)
	{
		if (b & 1) res = res * d % MOD;
		d = d * d % MOD;
		b >>= 1;
	}
	return res;
}

int main()
{
	scanf("%d %d", &n, &m);
	printf("%lld\n", KSM(n, m));
	return 0;
}
