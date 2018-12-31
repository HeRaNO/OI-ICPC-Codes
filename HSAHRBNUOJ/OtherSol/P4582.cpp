#include <cmath>
#include <cstdio>
using namespace std;

const double eps = 1e-12;

double l, r, lmid, rmid, a, b;

inline double f(double x)
{
	return cosh(x) + x;
}

int main()
{
	scanf("%lf %lf", &l, &r);
	while (r - l > eps)
	{
		lmid = (l + r) / 2.0;
		rmid = (lmid + r) / 2.0;
		if (f(lmid) < f(rmid)) r = rmid;
		else l = lmid;
	}
	printf("%.4lf\n", f(l));
	return 0;
}