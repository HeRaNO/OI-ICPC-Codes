#include <cstdio>
using namespace std;

int n;

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
	scanf("%d", &n);
	printf("%lld\n", phi(n));
	return 0;
}
