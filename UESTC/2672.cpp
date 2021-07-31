#include <bits/stdc++.h>
#define MAXN 5005
using namespace std;

const double eps = 1e-6;

inline int sgn(double x)
{
	if (fabs(x) < eps) return 0;
	return x < -eps ? -1 : 1;
}

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
	point operator * (double rate) const {
		return point(x * rate, y * rate);
	}
	point operator / (double rate) const {
		return point(x / rate, y / rate);
	}
	bool operator < (const point &p) const {
		if (p.x != x) return p.x > x;
		else return p.y > y;
	}
	int quadrant() const {
		int xs = sgn(x), ys = sgn(y);
		return xs == 0 && ys == 0 ? -1 : ((ys < 0 || ys == 0 && xs > 0) ? 0 : 1);
	}
	double length() const {
		return sqrt(x * x + y * y);
	}
	double operator ^ (const point &p) const {
		return x * p.x + y * p.y;
	}
	double operator * (const point &p) const {
		return x * p.y - y * p.x;
	}
	point Rotate(double alpha) const {
		return point(x * cos(alpha) - y * sin(alpha), x * sin(alpha) + y * cos(alpha));
	}
	point norm() const {
		return point(-y, x);
	}
	point unit(double r) const {
		double d = sqrt(x * x + y * y);
		return point(x / d * r, y / d * r);
	}
};

bool cmp(const point &a, const point &b)
{
	int lq = a.quadrant(), rq = b.quadrant();
	if (lq != rq) return lq < rq;
	int s = sgn(a * b);
	return s ? s > 0 : sgn(a.length() - b.length()) < 0;
}

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
		return !r1 && r2 > 0 ? l.OnLeft(p) : cmp(v, l.v);
	}
};

int n;
point p[MAXN], r[MAXN];
line l[MAXN], q[MAXN];

inline int halfplaneIntersection(int n)
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
	int m = t - h;
	for (int i = 0; i < m; i++) r[i] = r[i + h];
	return m;
}

inline bool check(double R)
{
	for (int i = 0; i < n; i++)
	{
		point v = (p[(i + 1) % n] - p[i]).norm().unit(R);
		l[i] = line(p[i] + v, p[(i + 1) % n] - p[i]);
	}
	int m = halfplaneIntersection(n);
	return halfplaneIntersection(n) > 2;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lf %lf", &p[i].x, &p[i].y);
	double l = 0, r = 5000;
	for (int i = 1; i <= 100; i++)
	{
		double mid = (l + r) / 2.0;
		if (check(mid)) l = mid;
		else r = mid;
	}
	printf("%.4lf\n", (l + r) / 2.0);
	return 0;
}