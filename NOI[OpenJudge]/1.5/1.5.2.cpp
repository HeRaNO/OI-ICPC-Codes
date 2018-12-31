//Code By HeRaNO
#include <stdio.h>
double a, sum = 0.0;
int main()
{
	for (int i = 1; i <= 12; i++)
	{
		scanf("%lf", &a);
		sum += a;
	}
	printf("$%.2lf", sum / 12.0);
	return 0;
}
