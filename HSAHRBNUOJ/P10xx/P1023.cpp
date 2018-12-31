#include <cstdio>
#define MAXN 20
using namespace std;

int n;
long long fac[MAXN], f[MAXN];

inline long long C(int n, int m)
{
	return fac[n] / (fac[m] * fac[n - m]);
}

int main()
{
	scanf("%d", &n);
	fac[0] = f[0] = 1;
	for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			f[i] += C(i, j) * f[i - j];
	printf("%lld\n", f[n]);
	return 0;
}