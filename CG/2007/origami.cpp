#include <bits/stdc++.h>
#define MAXN 10
using namespace std;

const double eps = 1e-6;

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
	double operator ^ (const point &p) const {
		return x * p.x + y * p.y;
	}
	double operator * (const point &p) const {
		return x * p.y - y * p.x;
	}
	double length() const {
		return sqrt(x * x + y * y);
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
	bool On_Left(const point &O) {
		return (O - p) * v < -eps;
	}
	bool On(const point &O) {
		return fabs((O - p) * v) <= eps;
	}
	point reflect(const point &O) {
		double alpha = ((O - p) ^ v) / (O - p).length() / v.length();
		alpha = acos(alpha);
		double d = (O - p).length() * sin(alpha);
		point nv = v.norm().unit(d);
		return O - nv * 2;
	}
};

line l[MAXN];
int n, T;
double a, b, c, d;

inline bool inRange(double x)
{
	return eps <= x && x + eps <= 100.0;
}

inline bool inRange(point x)
{
	return inRange(x.x) && inRange(x.y);
}

int dfs(point O, int n)
{
	if (!n) return inRange(O);
	if (!l[n].On_Left(O) || l[n].On(O)) return 0;
	return dfs(O, n - 1) + dfs(l[n].reflect(O), n - 1);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
		l[i] = line(point(a, b), point(c, d) - point(a, b));
	}
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lf %lf", &a, &b);
		printf("%d\n", dfs(point(a, b), n));
	}
	return 0;
}