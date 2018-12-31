#include <cstdio>
#include <algorithm>
#define MAXN 5010
using namespace std;

struct point
{
	int x, y;
};

point a[MAXN];
int n, l, w, ans, u, d;

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}
inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

inline bool cmpy(point a, point b)
{
	return a.y == b.y ? a.x < b.x : a.y < b.y;
}
inline bool cmpx(point a, point b)
{
	return a.x == b.x ? a.y < b.y : a.x < b.x;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return ;
}

int main()
{
	read(l);
	read(w);
	read(n);
	if (!n)
	{
		printf("%d\n", l * w);
		return 0;
	}
	for (int i = 1; i <= n; i++) read(a[i].x), read(a[i].y);
	sort(a + 1, a + n + 1, cmpx);
	for (int i = 1; i <= n; i++)
	{
		u = w;
		d = 0;
		for (int j = i + 1; j <= n; j++)
		{
			ans = mymax(ans, (u - d) * (a[j].x - a[i].x));
			if (a[j].y >= a[i].y) u = mymin(u, a[j].y);
			if (a[j].y <= a[i].y) d = mymax(d, a[j].y);
		}
		ans = mymax(ans, (u - d) * (l - a[i].x));
	}
	for (int i = n; i; i--)
	{
		u = w;
		d = 0;
		for (int j = i - 1; j; j--)
		{
			ans = mymax(ans, (u - d) * (a[i].x - a[j].x));
			if (a[j].y >= a[i].y) u = mymin(u, a[j].y);
			if (a[j].y <= a[i].y) d = mymax(d, a[j].y);
		}
		ans = mymax(ans, (u - d) * a[i].x);
	}
	sort(a + 1, a + n + 1, cmpy);
	for (int i = 1; i < n; i++) ans = mymax(ans, (a[i + 1].y - a[i].y) * l);
	printf("%d\n", ans);
	return 0;
}