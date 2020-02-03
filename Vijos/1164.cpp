#include <cstdio>
#define MAXN 11
using namespace std;

long long a[MAXN], m[MAXN];
long long n;

void ex_gcd(long long a, long long b, long long &x, long long &y)
{
	if (!b)
	{
		x = 1;
		y = 0;
		return ;
	}
	else
	{
		ex_gcd(b, a % b, x, y);
		long long tmp = x;
		x = y;
		y = tmp - (a / b) * y;
	}
}

long long crt(long long n)
{
	long long M = 1, ans = 0;
	for (int i = 1; i <= n; i++) M *= m[i];
	for (int i = 1; i <= n; i++)
	{
		long long w = M / m[i];
		long long x, y;
		ex_gcd(w, m[i], x, y);
		ans = (ans + x * w * a[i]) % M;
	}
	return (ans + M) % M;
}

int main()
{
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lld %lld", &m[i], &a[i]);
	printf("%lld", crt(n));
	return 0;
}
