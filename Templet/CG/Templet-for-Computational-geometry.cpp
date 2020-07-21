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
};

bool cmp(const point &a, const point &b)
{
	return a * b > 0;
}

struct line
{
	point p, v;
	line() {}
	line(const point &_p, const point &_v): p(_p), v(_v) {}
	bool On_Left(const point &A)
	{
		return (A - p) * v < eps;
	}
	point Get_Intersection(const line &l)
	{
		point u = p - l.p;
		double tmp = (l.v * u) / (v * l.v);
		return p + v * tmp;
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
		res = mymax(res, max(dis(ch[i], ch[q]), dis(ch[i + 1], ch[q + 1])));
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

int main()
{
	return 0;
}
