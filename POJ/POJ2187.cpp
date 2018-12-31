#include <cstdio>
#include <algorithm>
#define MAXN 50010
using namespace std;

struct point
{
	int x, y;
	point() {}
	point(int _x, int _y): x(_x), y(_y) {}
	friend point operator + (const point &p1, const point &p2)
	{
		return point(p1.x + p2.x, p1.y + p2.y);
	}
	friend point operator - (const point &p1, const point &p2)
	{
		return point(p1.x - p2.x, p1.y - p2.y);
	}
};

int n, siz;
point p[MAXN];
int ch[MAXN];

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}
inline int cross(point a, point b)
{
	return a.x * b.y - a.y * b.x;
}
inline int dis(point a, point b)
{
	return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
}

bool cmp(point a, point b)
{
	if (a.y != b.y) return a.y < b.y;
	return a.x < b.x;
}

int ConvexHull(int n)
{
	sort(p, p + n, cmp);
	int m = 0;
	for (int i = 0; i < n; i++)
	{
		while (m > 1 && cross(p[ch[m - 1]] - p[ch[m - 2]], p[i] - p[ch[m - 2]]) <= 0) m--;
		ch[m++] = i;
	}
	int k = m;
	for (int i = n - 2; i >= 0; i--)
	{
		while (m > k && cross(p[ch[m - 1]] - p[ch[m - 2]], p[i] - p[ch[m - 2]]) <= 0) m--;
		ch[m++] = i;
	}
	if (n > 1) m--;
	return m;
}

int Rotating_Calipers()
{
	int res = 0, q = 1;
	for (int i = 0; i < siz; i++)
	{
		while (cross(p[ch[i + 1]] - p[ch[i]], p[ch[q + 1]] - p[ch[i]]) > cross(p[ch[i + 1]] - p[ch[i]], p[ch[q]] - p[ch[i]])) q = (q + 1) % siz;
		res = mymax(res, mymax(dis(p[ch[i]], p[ch[q]]), dis(p[ch[i + 1]], p[ch[q + 1]])));
	}
	return res;
}

int main()
{
	while (~scanf("%d", &n))
	{
		for (int i = 0; i < n; i++) scanf("%d %d", &p[i].x, &p[i].y);
		siz = ConvexHull(n);
		printf("%d\n", Rotating_Calipers());
	}
	return 0;
}
