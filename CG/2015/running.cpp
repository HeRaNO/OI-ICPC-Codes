#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

const double eps = 1e-7;

inline int sgn(double x){ return fabs(x) <= eps ? 0 : (x < 0 ? -1 : 1); }

struct point
{
	double x, y;
	point() {}
	point(double _x, double _y):
		x(_x), y(_y) {}
	point operator + (const point &p) const {
		return point(x + p.x, y + p.y);
	}
	point operator - (const point &p) const {
		return point(x - p.x, y - p.y);
	}
	point operator * (double r) const {
		return point(x * r, y * r);
	}
	int quadrant() const {
		int xs = sgn(x), ys = sgn(y);
		return xs == 0 && ys == 0 ? -1 : ((ys < 0 || ys == 0 && xs > 0) ? 0 : 1);
	}
	double length() const {
		return sqrt(x * x + y * y);
	}
	bool operator < (const point &p) const {
		int lq = quadrant(), rq = p.quadrant();
		if (lq != rq) return lq < rq;
		int s = sgn(*this * p);
		return s ? s > 0 : sgn(length() - p.length()) < 0;
	}
	double operator ^ (const point &p) const {
		return x * p.x + y * p.y;
	}
	double operator * (const point &p) const {
		return x * p.y - y * p.x;
	}
};

struct line
{
	point p, v;
	line() {}
	line(const point &_p, const point &_v): p(_p), v(_v) {}
	bool OnLeft(const point &A) const {
		return (A - p) * v < -eps;
	}
	bool OnRight(const point &A) const {
		return (A - p) * v > eps;
	}
	point GetIntersection(const line &l) {
		point u = p - l.p;
		return p + v * ((l.v * u) / (v * l.v));
	}
	bool operator < (const line &l) const {
		int r1 = sgn(v * l.v), r2 = sgn(v ^ l.v);
		return !r1 && r2 > 0 ? l.OnLeft(p) : v < l.v;
	}
};

point p[MAXN], r[MAXN];
line l[MAXN << 1], q[MAXN << 1];
int n, m;

double PolygonArea(point *p, int n)
{
	if (n < 3) return 0;
	double S = 0.0;
	for (int i = 0; i < n; i++) S += p[i % n] * p[(i + 1) % n];
	return S / 2.0;
}

inline void halfplaneIntersection(int n)
{
	sort(l, l + n);
	int h = 0, t = 0;
	q[t++] = l[0];
	for (int i = 1; i < n; i++)
	{
		while (h + 1 < t && l[i].OnRight(r[t - 2])) --t;
		while (h + 1 < t && l[i].OnRight(r[h])) ++h;
		q[t++] = l[i];
		if (!sgn(q[t - 2].v * q[t - 1].v))
		{
			t--;
			if (q[t - 1].OnLeft(l[i].p)) q[t - 1] = l[i];
		}
		if (h + 1 < t) r[t - 2] = q[t - 2].GetIntersection(q[t - 1]);
	}
	while (h + 1 < t && q[h].OnRight(r[t - 2])) --t;
	r[t - 1] = q[h].GetIntersection(q[t - 1]);
	m = t - h;
	for (int i = 0; i < m; i++) r[i] = r[i + h];
	return ;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0, x, y; i < n; i++)
	{
		scanf("%d %d", &x, &y);
		p[i] = point(x, y);
	}
	for (int i = 0; i < n; i++)
		l[i] = line(p[i], p[(i + 1) % n] - p[i]);
	double S = PolygonArea(p, n);
	point P = p[0] - p[1];
	for (int i = 1; i < n; i++)
	{
		point Q = p[(i + 1) % n] - p[i];
		double A = P.y + Q.y;
		double B = -Q.x - P.x;
		double C = (p[0] * p[1]) - (p[i] * p[(i + 1) % n]);
		point v = point(-B, A), R;
		if (fabs(A) < eps) R = point(0, -C / B);
		else R = point(-C / A, 0);
		l[i + n - 1] = line(R, v);
	}
	halfplaneIntersection((n << 1) - 1);
	double s = fabs(PolygonArea(r, m));
	printf("%.4lf\n", s / S);
	return 0;
}