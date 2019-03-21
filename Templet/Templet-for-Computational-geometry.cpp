#include <cmath>
#include <cstdio>
#include <algorithm>
#define MAXN 1010
using namespace std;
//double can be replaced by long double

//Also,the eps can be changed if the problem needs.

const double eps = 1e-7;


double myabs(double a)
{
	return a < eps ? -a : a;
}

double mymax(double a, double b)
{
	return a - b < eps ? b : a;
}

struct point
{
	double x, y;
	point() {}
	point(double _x, double _y):
		x(_x), y(_y) {}
	friend point operator + (const point &p1, const point &p2)
	{
		return point(p1.x + p2.x, p1.y + p2.y);
	}
	friend point operator - (const point &p1, const point &p2)
	{
		return point(p1.x - p2.x, p1.y - p2.y);
	}
	friend point operator * (const point &p, double rate)
	{
		return point(p.x * rate, p.y * rate);
	}
	bool operator < (const point p) const
	{
		if (p.x != x) return p.x > x;
		else return p.y > y;
	}
	friend double dot(const point &p1, const point &p2)
	{
		return p1.x * p2.x + p1.y * p2.y;
	}
	friend double cross(const point &p1, const point &p2)
	{
		return p1.x * p2.y - p1.y * p2.x;
	}
	friend double Polar_Angle(const point &p)
	{
		return atan2(p.y, p.x);
	}
	friend point Rotate(const point &p, double alpha)
	{
		return point(p.x * cos(alpha) - p.y * sin(alpha), p.x * sin(alpha) + p.y * cos(alpha));
	}
	friend double Euclid_dis(const point &p1, const point &p2)
	{
		return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
	}
	friend double Manhattan_dis(const point &p1, const point &p2)
	{
		return myabs(p1.x - p2.x) + myabs(p1.y - p2.y);
	}
	friend double Chebyshev_dis(const point &p1, const point &p2)
	{
		return mymax(myabs(p1.x - p2.x), myabs(p1.y - p2.y));
	}
};

struct line
{
	point p, v;
	line() {}
	line(const point &_p, const point &_v): p(_p), v(_v) {}
	bool On_Left(const line &l, const point &p)
	{
		return cross(p - l.p, l.v) < eps;
	}
	friend point Get_Intersection(const line &l1, const line &l2)
	{
		point u = l1.p - l2.p;
		double tmp = cross(l2.v, u) / cross(l1.v, l2.v);
		return l1.p + l1.v * tmp;
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
		while (m > 1 && cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= eps) m--;
		ch[m++] = p[i];
	}
	int k = m;
	for (int i = n - 2; ~i; i--)
	{
		while (m > k && cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= eps) m--;
		ch[m++] = p[i];
	}
	if (n > 1) m--;
	return m;
}

double cross_a(point a, point b, point c)
{
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

double Polygon_Area(point *p, int n) //Figure out the size of the Polygen
{
	double S = 0.0;
	point tmp(0, 0); //the base point can be changed if the problem needs.
	int siz = ConvexHull(p, n);
	for (int i = 0; i < siz; i++) S += cross_a(tmp, p[i % siz], p[(i + 1) % siz]);
	S /= 2.0;
	return s;
}

double Rotating_Calipers()//Get the longest distance among points
{
	double res = 0.0;
	int q = 1;
	for (int i = 0; i < siz; i++)
	{
		while (cross(ch[i + 1] - ch[i], ch[q + 1] - ch[i]) > cross(ch[i + 1] - ch[i], ch[q] - ch[i])) q = (q + 1) % siz;
		res = mymax(res, mymax(dis(ch[i], ch[q]), dis(ch[i + 1], ch[q + 1])));
	}
	return res;
}

int main()

{
	return 0;
}
