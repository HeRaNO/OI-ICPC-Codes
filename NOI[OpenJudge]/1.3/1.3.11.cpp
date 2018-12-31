//Code By HeRaNO
#include<stdio.h>
int main()
{
	double a, b, r;
	int k;
	scanf("%lf %lf", &a, &b);
	k = a / b;
	r = a - (b * k);
	printf("%g", r);
	return 0;
}