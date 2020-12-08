#include <bits/stdc++.h>
#define MAXN 105
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
	point rotate(double alpha) const {
		return point(x * cos(alpha) - y * sin(alpha), x * sin(alpha) + y * cos(alpha));
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
}O;

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
int n, m, x, y;
double S;

double PolygonArea(point *p, int n)
{
	double S = 0.0;
	for (int i = 0; i < n; i++) S += p[i % n] * p[(i + 1) % n];
	return S / 2.0;
}

inline void halfplaneIntersection(line l[], int n)
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

inline bool check(line v)
{
	for (int i = 0; i < n; i++)
		l[i] = line(p[i], p[(i + 1) % n] - p[i]);
	l[n] = v;
	halfplaneIntersection(l, n + 1);
	return PolygonArea(r, m) * 2 >= S;
}

inline void Solve(int cas)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &x, &y);
		p[i] = point(x, y);
	}
	scanf("%d %d", &x, &y);
	O = point(x, y);
	double mnd = 1e18; point v, vn = point(1, 0);
	for (int i = 0; i < n; i++) p[i] = p[i] - O;
	for (int i = 0; i < n; i++)
	{
		point t = p[(i + 1) % n] - p[i];
		double A = t.y, B = -t.x, C = p[i] * p[(i + 1) % n];
		double d = fabs(C) / sqrt(A * A +  B * B);
		if (d < mnd)
		{
			mnd = d;
			v = t;
		}
	}
	double x = v * vn, y = v ^ vn, alpha;
	int xs = sgn(x), ys = sgn(y);
	if (!xs)
	{
		if (ys > 0) alpha = 0;
		else alpha = pi;
	}
	else
	{
		alpha = acos(y / v.length());
		if (xs < 0) alpha = 2 * pi - alpha;
	}
	for (int i = 0; i < n; i++) p[i] = p[i].rotate(alpha);
	S = PolygonArea(p, n);
	double l = 0, r = pi, ans;
	for (int i = 0; i < 100; i++)
	{
		double mid = (l + r) / 2.0;
		if (check(line(point(0, 0), point(cos(mid), sin(mid))))) l = mid;
		else r = mid;
	}
	ans = (l + r) / 2.0 - alpha;
	printf("Case #%d: %.4lf %.4lf\n", cas, cos(ans), sin(ans));
	return ;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) Solve(i);
	return 0;
}