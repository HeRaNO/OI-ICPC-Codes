#include <cstdio>

long long a = 1, b = 1, c = 1;
int n, k;

int main()
{
	scanf("%d %d", &n, &k);
	for (long long i = 1; i <= n; i++)
	{
		a *= i;
		if (i == n - k) b = a;
		if (i == k) c = a;
	}
	printf("%lld\n", (a / b) / c * (a / b));
	return 0;
}