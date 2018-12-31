//Code By HeRaNO
#include <stdio.h>
int a, sum, n;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		sum += a;
	}
	printf("%d %.5lf", sum, double(sum) / double(n));
	return 0;
}
