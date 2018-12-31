#include <cstdio>
#define MAXN 10000010
using namespace std;

unsigned long long ans;
long long n, m;
long long f[10010];

void fenjie(long long x)
{
	long long i;
	for (i = 1; i * i < n; i++)
		if (x % i == 0)
			f[++f[0]] = i, f[++f[0]] = x / i;
	if (i * i == x)
		f[++f[0]] = i;
}

long long phi(long long x)
{
	long long res = x;
	for (long long i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
		{
			res /= i;
			res *= (i - 1);
			while (x % i == 0) x /= i;
		}
	}
	if (x != 1) res /= x, res *= (x - 1);
	return res;
}

int main()
{
	scanf("%lld", &n);
	fenjie(n);
	for (long long i = 1; i <= f[0]; i++)
		ans += phi(n / f[i]) * f[i];
	printf("%lld\n", ans);
	return 0;
}