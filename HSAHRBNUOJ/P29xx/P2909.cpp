#include <cmath>
#include <cstdio>
#include <algorithm>
#define MAXN 10010
using namespace std;

struct point
{
	double x;
	double y;
};

point a[MAXN];
double l;
double d;
int n;
int ans, pos;
double left, right;

bool cmp(point a, point b)
{
	if (a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

double mymax(double a, double b)
{
	return a > b ? a : b;
}

double mymin(double a, double b)
{
	return a < b ? a : b;
}

int main()
{
	while (~scanf("%lf", &l))
	{
		scanf("%lf", &d);
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%lf %lf", &a[i].x, &a[i].y);
		sort(a + 1, a + n + 1, cmp);
		left = mymax(0.0, a[1].x - sqrt(d * d - a[1].y * a[1].y));
		right = mymin(a[1].x + sqrt(d * d - a[1].y * a[1].y), l);
		ans = 1;
		for (int i = 2; i <= n; i++)
		{
			left = mymax(left, a[i].x - sqrt(d * d - a[i].y * a[i].y));
			right = mymin(right, a[i].x + sqrt(d * d - a[i].y * a[i].y));
			if (left > right)
			{
				ans++;
				left = mymax(0.0, a[i].x - sqrt(d * d - a[i].y * a[i].y));
				right = mymin(l, a[i].x + sqrt(d * d - a[i].y * a[i].y));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
