#include <cstdio>
long long n, i;
int main()
{
	scanf("%lld", &n);
	for (i = 2;; i++)
	{
		if (n % i == 0)
		{
			printf("%d", n / i);
			return 0;
		}
	}
	return 0;
}
