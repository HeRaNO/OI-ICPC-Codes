//Code By HeRaNO
#include<stdio.h>
#define P 3.14159
int main()
{
	double r;
	scanf("%lf", &r);
	printf("%0.4f %0.4f %0.4f", 2 * r, 2 * P * r, P * r * r);
	return 0;
}