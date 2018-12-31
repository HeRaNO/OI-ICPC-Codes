//Code By HeRaNO
#include <stdio.h>
double f(double x)
{
	return x * x * x * x * x - 15 * x * x * x * x + 85 * x * x * x - 225 * x * x + 274 * x - 121;
}

int main()
{
	double left = 1.5, right = 2.4;
	while (right - left > 1e-9)
	{
		double mid = (right + left) / 2;
		if (f(mid) < 0) right = mid;
		else left = mid;
	}
	printf("%.6lf\n", left);
	return 0;
}
