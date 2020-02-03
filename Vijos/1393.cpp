#include <stdio.h>
#include <math.h>
double m, n, r;
int main()
{
	scanf("%lf %lf %lf", &m, &n, &r);
	if (m - n > 0)
		printf("%.3f", sqrt(r * r + (m - n) * (m - n)));
	else printf("%.3f", r);
	return 0;
}
