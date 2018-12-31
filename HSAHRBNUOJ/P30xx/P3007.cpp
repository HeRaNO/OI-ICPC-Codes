#include <math.h>
#include <stdio.h>
double a, b, c, p, s;
int main()
{
	scanf("%lf %lf %lf", &a, &b, &c);
	p = (a + b + c) / 2.0;
	s = sqrt(p * (p - a) * (p - b) * (p - c));
	printf("%.3lf\n", s);
	return 0;
}
