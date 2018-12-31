#include <cstdio>
#define MAXN 1000010
#define MOD 1000000007
using namespace std;

int n, m;
long long inv[MAXN], fac[MAXN];
int sum;

inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) sum += read();
	if (n - sum - m < 0)
	{
		printf("0\n");
		return 0;
	}
	inv[0] = inv[1] = 1;
	fac[0] = fac[1] = 1;
	for (int i = 2; i <= n - sum - 1; i++) inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
	for (int i = 2; i <= n - sum - 1; i++) inv[i] = (inv[i - 1] * inv[i]) % MOD;
	for (int i = 2; i <= n - sum - 1; i++) fac[i] = (fac[i - 1] * i) % MOD;
	printf("%lld\n", ((fac[n - sum - 1]*inv[m - 1]) % MOD)*inv[n - sum - m] % MOD);
	return 0;
}
