#include <cmath>
#include <cstdio>
using namespace std;

double v, v0;

double mymax(double a, double b)
{
	return a > b ? a : b;
}

int main()
{
	scanf("%lf", &v);
	scanf("%lf", &v0);
	double ans = 0, now;
	bool flag = 0;
	int most = int(v / v0), p;
	for (int i = 1; i <= most; i++)
	{
		now = i * 0.3 * sqrt(v / i - v0);
		if (fabs(ans - now) < 0.000001) flag = 1;
		else
		{
			if (ans < now)
			{
				ans = now;
				flag = 0;
				p = i;
			}
		}
	}
	if (flag) printf("0\n");
	else printf("%d\n", p);
	return 0;
}
