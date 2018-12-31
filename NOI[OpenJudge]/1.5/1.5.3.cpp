//Code By HeRaNO
#include <stdio.h>
double a, sum = 0.0;
int n;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lf", &a);
		sum += a;
	}
	printf("%.4lf", sum / double(n));
	return 0;
}

