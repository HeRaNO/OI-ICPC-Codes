//Code By HeRaNO
#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	int c;
	double a, b;
	scanf("%lf%lf", &a, &b);
	c = log10(b) / log10(a);
	printf("%d\n", c);
	return 0;
}
