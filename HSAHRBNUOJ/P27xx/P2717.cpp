#include <cstdio>
#include <climits>
#define MAXN 100010
using namespace std;

struct point
{
	int x;
	int y;
};

point a[MAXN];
int T, n;
int l, r, u, v;

int mymin(int a, int b)
{
	return a < b ? a : b;
}

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	//freopen("lighthouses.in","r",stdin);freopen("lighthouses.out","w",stdout);
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		l = u = INT_MAX;
		r = v = INT_MIN;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d %d", &a[i].x, &a[i].y);
			l = mymin(a[i].x, l);
			r = mymax(a[i].x, r);
			u = mymin(a[i].y, u);
			v = mymax(a[i].y, v);
		}
		int ans = 2;
		for (int i = 1; i <= n && ans != 1; i++)
		{
			if (a[i].x == l && (a[i].y == u || a[i].y == v)) ans = 1;
			if (a[i].x == r && (u == a[i].y || v == a[i].y)) ans = 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}
