#include <bits/stdc++.h>
#define MAXN 50010
using namespace std;

struct point
{
	int x, y;
	point() {}
	point(int _x, int _y):
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
	friend int cross(const point &p1, const point &p2)
	{
		return p1.x * p2.y - p1.y * p2.x;
	}
	friend int dis(const point &p1, const point &p2)
	{
		return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
	}
};

int n, siz;
point p[MAXN], ch[MAXN];

int ConvexHull(point *p, int n)
{
	sort(p, p + n);
	int m = 0;
	for (int i = 0; i < n; i++)
	{
		while (m > 1 && cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0) m--;
		ch[m++] = p[i];
	}
	int k = m;
	for (int i = n - 2; ~i; i--)
	{
		while (m > k && cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0) m--;
		ch[m++] = p[i];
	}
	if (n > 1) m--;
	return m;
}

int Rotating_Calipers()
{
	int res = 0;
	int q = 1;
	for (int i = 0; i < siz; i++)
	{
		while (cross(ch[i + 1] - ch[i], ch[q + 1] - ch[i]) > cross(ch[i + 1] - ch[i], ch[q] - ch[i])) q = (q + 1) % siz;
		res = max(res, max(dis(ch[i], ch[q]), dis(ch[i + 1], ch[q + 1])));
	}
	return res;
}

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d %d",&p[i].x,&p[i].y);
	siz=ConvexHull(p,n);
	printf("%d\n", Rotating_Calipers());
	return 0;
}