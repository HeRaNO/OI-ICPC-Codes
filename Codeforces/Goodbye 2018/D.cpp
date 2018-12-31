#include <cstdio>
#define MAXN 1000010
using namespace std;

const long long M = 998244353LL;

int n;
long long fac[MAXN], inv[MAXN], invfac[MAXN], ans;

long long A(int n, int i)
{
	return fac[n] * invfac[i] % M;
}

int main()
{
	scanf("%d", &n);
	fac[0] = 1;
	inv[1] = 1;
	invfac[0] = 1;
	for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % M;
	for (int i = 2; i <= n; i++) inv[i] = (M - M / i) * inv[M % i] % M;
	for (int i = 1; i <= n; i++) invfac[i] = invfac[i - 1] * inv[i] % M;
	for (int i = 2; i <= n; i++)
		ans = (ans + A(n, i) * (fac[i] - 1) % M) % M;
	printf("%I64d\n", (ans + 1) % M);
	return 0;
}