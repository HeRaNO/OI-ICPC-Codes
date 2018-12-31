#include <cstdio>
#define MAXN 210
using namespace std;

struct rectangle
{
	double x1, x2, y1, y2;
};

rectangle a[MAXN];
int n;
double ans;

inline void Float(double x1, double y1, double x2, double y2, int t)
{
	if (x1 >= x2 || y1 >= y2) return ;
	while (t && (x1 >= a[t].x2 || x2 <= a[t].x1 || y1 >= a[t].y2 || y2 <= a[t].y1)) t--;
	if (!t)
	{
		ans += (x2 - x1) * (y2 - y1);
		return ;
	}
	if (x1 < a[t].x1)
	{
		Float(x1, y1, a[t].x1, y2, t);
		x1 = a[t].x1;
	}
	if (x2 > a[t].x2)
	{
		Float(a[t].x2, y1, x2, y2, t);
		x2 = a[t].x2;
	}
	if (y1 < a[t].y1)
	{
		Float(x1, y1, x2, a[t].y1, t);
		y1 = a[t].y1;
	}
	if (y2 > a[t].y2)
	{
		Float(x1, a[t].y2, x2, y2, t);
		y2 = a[t].y2;
	}
	return ;
}

int main()
{
	while (~scanf("%d", &n) && n)
	{
		for (int i = 1; i <= n; i++)
			scanf("%lf %lf %lf %lf", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
		for (int i = 1; i <= n; i++) Float(a[i].x1, a[i].y1, a[i].x2, a[i].y2, i - 1);
		printf("%.2lf\n", ans);
		ans = 0;
	}
	return 0;
}
