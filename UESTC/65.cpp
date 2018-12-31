#include <cstdio>

int n, k, T;

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &n, &k);
		if (n == 13 && n < k)
		{
			puts("2");
			continue;
		}
		if (k == 13) --k;
		printf("%d\n", (n / k) + (n % k != 0) + (k == 14 && n % k == 13));
	}
	return 0;
}
