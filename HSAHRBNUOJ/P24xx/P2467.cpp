#include <cmath>
#include <cstdio>
#include <algorithm>
#define MAXN 110
using namespace std;

struct point
{
	double x, y;
};

int n;
point p[MAXN];
double s;

double cross(point a, point b, point c)
{
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
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
	point tmp;
	tmp.x = 0.0, tmp.y = 0.0;
	for (int i = 0; i < n; i++)
		s += cross(tmp, p[i], p[i + 1]);
	s += cross(tmp, p[n - 1], p[0]);
	s = s / 2.0;
	printf("%.1lf\n", s);
	return 0;
}
