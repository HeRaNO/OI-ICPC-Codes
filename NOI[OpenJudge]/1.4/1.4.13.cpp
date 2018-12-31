//Code By HeRaNO
#include<stdio.h>
int main()
{
	double n, fx;
	scanf("%lf", &n);
	if (n >= 0 && n < 5) fx = 2.5 - n;
	if (n >= 5 && n < 10) fx = 2.0 - 1.5 * (n - 3) * (n - 3);
	if (n >= 10 && n < 20) fx = n / 2.0 - 1.5;
	printf("%0.3lf", fx);
	return 0;
}
