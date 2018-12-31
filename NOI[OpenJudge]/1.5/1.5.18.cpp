//Code By HeRaNO
#include <cstdio>
using namespace std;

int n;
double a, b, c, d;
double sta;
double now;

int main()
{
	scanf("%d", &n);
	scanf("%lf %lf", &a, &b);
	for (int i = 1; i < n; i++)
	{
		scanf("%lf %lf", &c, &d);
		if (d / c - b / a > 0.05) printf("better\n");
		else if (b / a - d / c > 0.05) printf("worse\n");
		else printf("same\n");
	}
	return 0;
}
