#include <cstdio>
#define MOD 1000000007LL
using namespace std;

int n;
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
	//freopen("xvii.in","r",stdin);freopen("xvii.out","w",stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) ans = (ans + ((KSM(2, i - 1) - 1) % MOD) * KSM(i, MOD - 2) % MOD) % MOD;
	printf("%lld\n", ans);
	return 0;
}
