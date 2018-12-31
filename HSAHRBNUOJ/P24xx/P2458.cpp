#include <cstdio>
#include <algorithm>
#define MAXN 100010
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

int n;
point p[MAXN], ch[MAXN];

int cross(point p1, point p2)
{
	return p1.x * p2.y - p1.y * p2.x;
}

bool cmp(point a, point b)
{
	if (a.y != b.y) return a.y < b.y;
	else return a.x < b.x;
}

int ConvexHull(point *p, int n, point *ch)
{
	sort(p, p + n, cmp);
	int m = 0;
	for (int i = 0; i < n; i++)
	{
		while (m > 1 && cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0) m--;
		ch[m++] = p[i];
	}
	int k = m;
	for (int i = n - 2; i >= 0; i--)
	{
		while (m > k && cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0) m--;
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
	int siz = ConvexHull(p, n, ch);
	printf("%d\n", siz);
	for (int i = 0; i < siz; i++)
		printf("%d %d\n", ch[i].x, ch[i].y);
	return 0;
}
