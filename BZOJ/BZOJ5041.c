#include <math.h>
#include <stdio.h>

const double pi = acos(-1.0);
const double _2pi = acos(-1.0) * 2;
const double eps = 1e-4;

double F1x, F1y, F2x, F2y, m, n, R;
double Ax, Ay, Bx, By, Px, Py, Qx, Qy;
int T;

double Dis(double ax, double ay, double bx, double by)
{
	return sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
}

void Tri(int x)
{
	double l, r, lmid, rmid;
	if (x == 0)
		l = 0, r = pi;
	else
		l = pi, r = _2pi;
	while (r - l > eps)
	{
		lmid = (l + r) / 2.0;
		rmid = (lmid + r) / 2.0;
		Px = m + R * cos(lmid);
		Py = n + R * sin(lmid);
		Qx = m + R * cos(rmid);
		Qy = n + R * sin(rmid);
		if (Dis(Px, Py, F1x, F1y) + Dis(Px, Py, F2x, F2y) >
				Dis(Qx, Qy, F1x, F1y) + Dis(Qx, Qy, F2x, F2y)) l = lmid;
		else r = rmid;
	}
	if (x == 0)
	{
		Ax = m + R * cos(l);
		Ay = n + R * sin(l);
	}
	else
	{
		Bx = m + R * cos(l);
		By = n + R * sin(l);
	}
	return ;
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lf %lf %lf %lf", &F1x, &F1y, &F2x, &F2y);
		scanf("%lf %lf %lf", &m, &n, &R);
		Tri(0);
		Tri(1);
		if (Dis(Ax, Ay, F1x, F1y) + Dis(Ax, Ay, F2x, F2y) <
				Dis(Bx, By, F1x, F1y) + Dis(Bx, By, F2x, F2y))
			printf("%.3lf %.3lf\n", Ax, Ay);
		else printf("%.3lf %.3lf\n", Bx, By);
	}
	return 0;
}