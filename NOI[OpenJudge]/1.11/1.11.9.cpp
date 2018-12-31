//Code By HeRaNO
#include <cmath>
#include <cstdio>
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-20;

double l, c, n, nl;
double newl;
double left, right, middle;

int main()
{
	scanf("%lf %lf %lf", &l, &c, &n);
	newl = (1.0 + n * c) * l;
	right = PI / 2.0;
	left = 0.0;
	while (true)
	{
		middle = (left + right) / 2.0;
		double ans = ((l / 2.0) / sin(middle)) * middle * 2.0;
		if (fabs(ans - newl) < eps)
		{
			double r = (l / 2.0) / sin(middle);
			double k = (l / 2.0) / tan(middle);
			printf("%.3lf\n", r - k);
			return 0;
		}
		if (ans < newl) left = middle;
		else right = middle;
	}
	return 0;
}
