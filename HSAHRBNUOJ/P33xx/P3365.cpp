#include <cstdio>
#define MOD 1000000007LL
#define MAXN 50010
using namespace std;

int n, m;
long long ans, ans1;
long long inv[MAXN];

long long KSM(int t)
{
	long long res = 1, d = t;
	int tt = m + 1;
	while (tt)
	{
		if (tt & 1) res = (res * d) % MOD;
		d = (d * d) % MOD;
		tt >>= 1;
	}
	return res;
}

int main()
{
	//freopen("sum.in","r",stdin);freopen("sum.out","w",stdout);
	scanf("%d %d", &n, &m);
	ans = m;
	inv[1] = 1LL;
	for (int i = 2; i <= n; i++) inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
	for (int q = 2; q <= n; q++)
	{
		ans1 = 1;
		ans1 = ans1 * KSM(q) % MOD;
		ans1 -= q;
		ans1 = ans1 * inv[q - 1] % MOD;
		ans = (ans + ans1) % MOD;
	}
	printf("%lld\n", ans % MOD);
	return 0;
}
