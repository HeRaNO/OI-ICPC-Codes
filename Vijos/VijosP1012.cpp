#include <cmath>
#include <cstdio>
#include <algorithm>
#define MAXN 100010
#define INF 1e18
using namespace std;

struct point
{
	double x, y;
	point() {}
	point(double _x, double _y): x(_x), y(_y) {}
};

point p[MAXN], t[MAXN];
int n;

bool cmp(point a, point b)
{
	if (a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

bool cmpy(point a, point b)
{
	return a.y < b.y;
}

inline double dis(point p1, point p2)
{
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

inline double mymin(double a, double b)
{
	return a < b ? a : b;
}

double Closest_Pair(int left, int right)
{
	double res = INF;
	if (left == right) return res;
	if (left + 1 == right) return dis(p[left], p[right]);
	int middle = (left + right) >> 1;
	res = mymin(Closest_Pair(left, middle), Closest_Pair(middle, right));
	int cnt = 0;
	for (int i = left; i <= right; i++)
		if (fabs(p[middle].x - p[i].x) <= res) t[++cnt] = p[i];
	sort(t + 1, t + cnt + 1, cmpy);
	for (int i = 1; i <= cnt; i++)
		for (int j = i + 1; j <= cnt && t[j].y - t[i].y < res; j++)
			res = mymin(res, dis(t[i], t[j]));
	return res;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lf %lf", &p[i].x, &p[i].y);
	sort(p + 1, p + n + 1, cmp);
	printf("%.3lf\n", Closest_Pair(1, n));
	return 0;
}
