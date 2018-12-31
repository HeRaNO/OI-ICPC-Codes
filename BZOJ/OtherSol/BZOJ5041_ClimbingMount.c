#include <math.h>
#include <stdio.h>
#include <stdlib.h>

const double pi = acos(-1.0);
const double _2pi = acos(-1.0) * 2;

double F1x, F1y, F2x, F2y, m, n, R;
double T, ans, now;
int cas;

double Rand()
{
	return rand() % 1000 / 1000.0;
}

double Dis(double ax, double ay, double bx, double by)
{
	return sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
}

double F(double theta)
{
	double x = m + R * cos(theta), y = n + R * sin(theta);
	return Dis(x, y, F1x, F1y) + Dis(x, y, F2x, F2y);
}

int main()
{
	scanf("%d", &cas);
	while (cas--)
	{
		scanf("%lf %lf %lf %lf", &F1x, &F1y, &F2x, &F2y);
		scanf("%lf %lf %lf", &m, &n, &R);
		T = _2pi;
		ans = pi;
		while (T > 1e-3)
		{
			now = ans + T * (Rand() * 2.0 - 1.0);
			if (F(now) < F(ans)) ans = now;
			T *= 0.98;
		}
		printf("%.3lf %.3lf\n", m + R * cos(ans), n + R * sin(ans));
	}
	return 0;
}