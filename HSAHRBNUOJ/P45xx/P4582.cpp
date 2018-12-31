#include <cmath>
#include <cstdio>
using namespace std;

const double eps = 1e-9;

double a, b, x, mn;

inline double f(double x)
{
	return cosh(x) + x;
}
inline double df(double x)
{
	return sinh(x) + 1.0;
}

inline void Getmin()
{
	double l = -10, r = 10, mid;
	while (r - l > eps)
	{
		mid = (l + r) / 2;
		if (df(mid) == 0.0)
		{
			x = mid;
			mn = f(x);
			return ;
		}
		if (df(l)*df(mid) < 0) r = mid;
		else l = mid;
	}
	x = l;
	mn = f(x);
	return ;
}

int main()
{
	Getmin();
	scanf("%lf %lf", &a, &b);
	if (x <= (double)a) printf("%.4lf\n", f(a));
	else if ((double)b <= x) printf("%.4lf\n", f(b));
	else printf("%.4lf\n", mn);
	return 0;
}