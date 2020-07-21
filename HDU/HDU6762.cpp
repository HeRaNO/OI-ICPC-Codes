#include <bits/stdc++.h>
#define MAXN 205
using namespace std;

const double pi = acos(-1.0);
const double eps = 1e-8;

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
	bool operator < (const point &p) const {
		if (p.x != x) return p.x > x;
		else return p.y > y;
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
	point Rotate(double alpha) const {
		return point(x * cos(alpha) - y * sin(alpha), x * sin(alpha) + y * cos(alpha));
	}
};

inline int sgn(double x){ return fabs(x) <= eps ? 0 : (x < 0 ? -1 : 1); }

struct line
{
	point p, v;
	line() {}
	line(const point &_p, const point &_v): p(_p), v(_v) {}
	bool OnLeft(const point &A) const {
		return (A - p) * v < -eps;
	}
	point GetIntersection(const line &l) {
		point u = p - l.p;
		return p + v * ((l.v * u) / (v * l.v));
	}
	bool operator < (const line &l) const {
		int res = sgn(v * l.v);
		return !res ? l.OnLeft(p) : res < 0;
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
	int hq = 0, tq = 0, ha = 0, ta = 0;
	q[tq++] = l[0];
	for (int i = 1; i < n; i++)
	{
		if (!sgn(l[i].v * l[i - 1].v)) continue;
		while (ha < ta && !l[i].OnLeft(r[ta - 1])) --ta, --tq;
		while (ha < ta && !l[i].OnLeft(r[ha])) ++ha, ++hq;
		r[ta++] = l[i].GetIntersection(q[tq - 1]);
		q[tq++] = l[i];
	}
	while (ha < ta && !q[hq].OnLeft(r[ta - 1])) --ta, --tq;
	while (ha < ta && !q[tq - 1].OnLeft(r[ha])) ++ha, ++hq;
	r[ta++] = q[hq].GetIntersection(q[tq - 1]);
	m = ta - ha;
	for (int i = 0; i < m; i++) r[i] = r[i + ha];
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