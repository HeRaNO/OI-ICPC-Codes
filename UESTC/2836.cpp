#include <cstdio>
#define MAXN 10

long long exgcd(long long a, long long b, long long &x, long long &y)
{
	if (!b)
	{
		x = 1;
		y = 0;
		return a;
	}
	long long res = exgcd(b, a % b, y, x);
	y -= (a / b) * x;
	return res;
}

long long m[MAXN], a[MAXN];

long long exCRT(int n, long long &M)
{
	long long ans = a[0], x, y; M = m[0];
	for (int i = 1; i < n; i++)
	{
		long long g = exgcd(M, m[i], x, y);
		if ((a[i] - ans) % g) return -1LL;
		x = (a[i] - ans) / g * x % (m[i] / g);
		ans += x * M;
		M = M / g * m[i];
		ans %= M;
	}
	return (ans + M) % M;
}

int main()
{
	int R, n;
	scanf("%d %d", &R, &n);
	for (int i = 0; i < n; i++) scanf("%lld", &m[i]);
	for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
	long long M;
	long long x = exCRT(n, M);
	if (x == -1 || x > R)
		return puts("0"), 0;
	printf("%lld\n", (R - x) / M + (x != 0));
	return 0;
}