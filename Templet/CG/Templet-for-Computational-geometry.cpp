#include <cmath>
#include <cstdio>
#include <algorithm>
#define MAXN 1010
using namespace std;
//double can be replaced by long double or int/long long

//Also,the eps can be changed if the problem needs.

const double eps = 1e-7;

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
	double Polar_Angle() const {
		return atan2(y, x);
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
	int lq = quadrant(), rq = p.quadrant();
	if (lq != rq) return lq < rq;
	int s = sgn(*this * p);
	return s ? s > 0 : sgn(length() - p.length()) < 0;
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
point p[MAXN], ch[MAXN];
//Please start at 0 when you input.(It can be convenient for figure the size)

int ConvexHull(point *p, int n)
{
	sort(p, p + n);
	int m = 0;
	for (int i = 0; i < n; i++)
	{
		while (m > 1 && (ch[m - 1] - ch[m - 2]) * (p[i] - ch[m - 2]) <= eps) --m;
		ch[m++] = p[i];
	} // Lower hull
	int k = m;
	for (int i = n - 2; ~i; i--)
	{
		while (m > k && (ch[m - 1] - ch[m - 2]) * (p[i] - ch[m - 2]) <= eps) --m;
		ch[m++] = p[i];
	} // Upper hull
	if (n > 1) m--;
	return m;
}

double Polygon_Area(point *p, int n) //Figure out the size of the Polygon
{
	double S = 0.0;
	int siz = ConvexHull(p, n);
	for (int i = 0; i < siz; i++) S += p[i % siz] * p[(i + 1) % siz];
	return S / 2.0;
}

double Rotating_Calipers() //Get the longest distance among points
{
	double res = 0.0;
	int q = 1;
	for (int i = 0; i < siz; i++)
	{
		while ((ch[i + 1] - ch[i]) * (ch[q + 1] - ch[i]) > (ch[i + 1] - ch[i]) * (ch[q] - ch[i])) q = (q + 1) % siz;
		res = max(res, max(dis(ch[i], ch[q]), dis(ch[i + 1], ch[q + 1])));
	}
	return res;
}

// Is segment ab intersect with segment cd?
inline bool isIntersection(point a, point b, point c, point d)
{
	if (max(a.x, b.x) < min(c.x, d.x)) return false;
	if (max(a.y, b.y) < min(c.y, d.y)) return false;
	if (max(c.x, d.x) < min(a.x, b.x)) return false;
	if (max(c.y, d.y) < min(a.y, b.y)) return false;
	double p = (b - a) * (b - c);
	double q = (b - a) * (b - d);
	double r = (d - c) * (d - a);
	double s = (d - c) * (d - b);
	return (p * q <= eps) && (r * s <= eps);
}

// PIP Problem: Ray casting algorithm
// Point: (x, y), Polygon size: c
// Return val: 0: out, 1: in, 2: on the polygon
int in(int x, int y, int c)
{
	double k = sqrt(2), b = y - k * x;
	int cnt = 0; Point O = Point(x, y);
	for (int i = 0; i < c; i++)
		if (ch[i].x == x && ch[i].y == y) return 2;
	for (int i = 0; i < c; i++)
	{
		Point oa = ch[i] - O;
		Point ob = ch[(i + 1) % c] - O;
		if (fabs(oa * ob) <= eps) return 2;
	}
	for (int i = 0; i < c; i++)
	{
		double A = ch[(i + 1) % c].y - ch[i].y;
		double B = ch[i].x - ch[(i + 1) % c].x;
		double C = ch[(i + 1) % c] * ch[i];
		double lx = min(ch[i].x, ch[(i + 1)%c].x), rx = max(ch[i].x, ch[(i + 1) % c].x);
		double ly = min(ch[i].y, ch[(i + 1)%c].y), ry = max(ch[i].y, ch[(i + 1) % c].y);
		double nx = -(B * b + C) / (A + B * k);
		double ny = k * nx + b;
		if (ny > y) continue;
		if (lx - eps <= nx && nx <= rx + eps && ly - eps <= ny && ny <= ry + eps) ++cnt;
	}
	return cnt & 1;
}

point r[MAXN];
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

int main()
{
	return 0;
}
