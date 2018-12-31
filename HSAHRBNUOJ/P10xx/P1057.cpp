#include <cstdio>
#include <algorithm>
#define MAXN 100010
#define fi first
#define se second
using namespace std;

pair <double, pair<int, int> > a[MAXN << 1];
int n, m = 1, fx, fy, cnt, f[MAXN];
double ans, lim;

inline int getf(int x)
{
	return x == f[x] ? x : f[x] = getf(f[x]);
}

int main()
{
	scanf("%lf%d", &lim, &n);
	for (int i = 1; i <= n; i++) f[i] = i;
	while (~scanf("%d %d %lf", &a[m].se.fi, &a[m].se.se, &a[m].fi)) ++m;
	--m;
	if (m < n - 1)
	{
		puts("Impossible");
		return 0;
	}
	sort(a + 1, a + m + 1);
	for (int i = 1; i <= m; i++)
	{
		fx = getf(a[i].se.fi);
		fy = getf(a[i].se.se);
		if (fx != fy)
		{
			f[fy] = fx;
			ans += a[i].fi;
			++cnt;
		}
		if (cnt == n - 1) break;
	}
	if (ans > lim || cnt != n - 1) puts("Impossible");
	else printf("Need %.2lf miles of cable\n", ans);
	return 0;
}