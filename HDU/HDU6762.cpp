#include <bits/stdc++.h>
#define MAXN 205
using namespace std;

const double pi = acos(-1.0);
const double eps = 1e-8;

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
	point norm() const {
		return point(-y, x);
	}
	point unit(double r) const {
		double d = sqrt(x * x + y * y);
		return point(x / d * r, y / d * r);
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
line l[MAXN], q[MAXN];
int n, m, R, a, b;

double PolygonArea(point *p, int n)
{
	double S = 0.0;
	for (int i = 0; i < n; i++) S += p[i % n] * p[(i + 1) % n];
	return S / 2.0;
}

double distance(point a, point b)
{
	point x = b - a;
	return sqrt(x ^ x);
}

inline void halfplaneIntersection()
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

inline void Solve()
{
	scanf("%d %d", &n, &R);
	scanf("%d %d", &a, &b);
	for (int i = 0, x, y; i < n; i++)
	{
		scanf("%d %d", &x, &y);
		p[i] = point(x, y);
	}
	double S = PolygonArea(p, n);
	if (S < 0)
	{
		reverse(p, p + n);
		S = -S;
	}
	double ans = S * a;
	for (int i = 0; i < n; i++)
	{
		point v = (p[(i + 1) % n] - p[i]).norm().unit(R);
		l[i] = line(p[i] + v, p[(i + 1) % n] - p[i]);
	}
	halfplaneIntersection();
	if (m >= 3)
	{
		double L = 0.0;
		for (int i = 0; i < m; i++) L += distance(r[i], r[(i + 1) % m]);
		double s = fabs(PolygonArea(r, m)) + L * R + pi * R * R;
		ans = min(ans, b * s + a * (S - s));
	}
	printf("%.9lf\n", ans);
	return ;
}

int main()
{
	int T; scanf("%d", &T);
	while (T--) Solve();
	return 0;
}