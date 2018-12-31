#include <cstdio>
using namespace std;

double a, b, c, d;
bool first = true;

inline double f(double x)
{
	return a * x * x * x + b * x * x + c * x + d;
}

inline double Binary(double l, double r)
{
	double mid;
	while (r - l > 0.001)
	{
		mid = (l + r) / 2;
		if (f(mid) == 0.0) return mid;
		if (f(l)*f(mid) < 0) r = mid;
		else l = mid;
	}
	return l;
}

int main()
{
	scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
	for (double i = -100.0; i < 100.0; i++)
		if (f(i)*f(i + 1) < 0)
		{
			if (first)
			{
				printf("%.2lf", Binary(i, i + 1));
				first = false;
			}
			else printf(" %.2lf", Binary(i, i + 1));
		}
		else if (f(i) == 0)
		{
			if (first)
			{
				printf("%.2lf", i);
				first = false;
			}
			else printf(" %.2lf", i);
		}
	putchar('\n');
	return 0;
}