#include <cstdio>
#define MAXN 40
long long f[MAXN];
int n;
int main()
{
	scanf("%d", &n);
	f[0] = f[1] = 1LL;
	for (int i = 2; i <= n; i++) f[i] = f[i - 1] + f[i - 2];
	printf("%lld\n", f[n]);
	return 0;
}
