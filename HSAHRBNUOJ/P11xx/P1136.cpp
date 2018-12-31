#include <cstdio>

long long n, m;

int main()
{
	scanf("%lld %lld", &n, &m);
	if (m == 1 && n == 1)
	{
		puts("1");
		return 0;
	}
	if (n == m)
	{
		printf("%lld\n", n + m - 2);
		return 0;
	}
	if (m & 1)
	{
		printf("%lld\n", m + n - 1);
		return 0;
	}
	else
	{
		if (n & 1) n++;
		printf("%lld\n", n + m - 2);
	}
	return 0;
}