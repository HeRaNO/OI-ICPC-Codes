#include <cmath>
#include <cstdio>
#include <algorithm>
#define MAXN 15
using namespace std;

double myabs(double a)
{
	return a < 0.0 ? -a : a;
}

double mymax(double a, double b)
{
	return a - b < 0 ? b : a;
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
	friend point operator * (const point &p1, double rate)
	{
		return point(p1.x * rate, p1.y * rate);
	}
	bool operator < (const point p) const
	{
		if (p.x != x) return p.x > x;
		else return p.y > y;
	}
	friend double dot(const point &p1, const point &p2)
	{
		return p1.x * p2.x, p1.y * p2.y;
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

int n;
point p[MAXN], ch[MAXN];
double c, s;

int ConvexHull(point *p, int n, point *ch)
{
	sort(p, p + n);
	int m = 0;
	for (int i = 0; i < n; i++)
	{
		while (m > 1 && cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0.0) m--;
		ch[m++] = p[i];
	}
	int k = m;
	for (int i = n - 2; i >= 0; i--)
	{
		while (m > k && cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0.0) m--;
		ch[m++] = p[i];
	}
	if (n > 1) m--;
	return m;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int tmp1, tmp2;
		scanf("%d %d", &tmp1, &tmp2);
		p[i].x = tmp1, p[i].y = tmp2;
	}
	int cnt;
	for (cnt = 0; cnt <= n; cnt++)
		if (p[cnt].x != p[(cnt + 1) % n].x) break;
	if (cnt == n)
	{
		sort(p, p + n);
		c = p[n - 1].y - p[0].y;
		printf("%.2lf", c);
		printf("\n0.00\n");
		return 0;
	}
	for (cnt = 0; cnt <= n; cnt++)
		if (p[cnt].y != p[(cnt + 1) % n].y) break;
	if (cnt == n)
	{
		sort(p, p + n);
		c = p[n - 1].x - p[0].x;
		printf("%.2lf", c);
		printf("\n0.00\n");
		return 0;
	}
	int siz = ConvexHull(p, n, ch);
	for (int i = 0; i < siz - 1; i++)
	{
		c += Euclid_dis(ch[i], ch[i + 1]);
		s += cross(ch[i], ch[i + 1]);
	}
	s += cross(ch[siz - 1], ch[0]);
	c += Euclid_dis(ch[siz - 1], ch[0]);
	s = s / 2.0;
	printf("%.2lf\n%.2lf\n", c, s);
	return 0;
}