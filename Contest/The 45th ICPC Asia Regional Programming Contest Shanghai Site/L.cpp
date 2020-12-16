#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
inline double dist(double x1, double y1, double x2, double y2) { return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)); }
inline int gcd(int x, int y)
{
	if (x == 0)
		return y;
	if (y == 0)
		return x;
	return __gcd(x, y);
}

void solve()
{
	scanf("%d%d", &n, &m);
	double ans = LONG_LONG_MAX;
	if (n > m)
		swap(n, m);
	int g = gcd(n, m);
	if (g == 1)
		return printf("%.12lf\n", dist(0, 0, n, m)), void();
	for (int x = 0; x <= n; ++x)
	{
		int mid = 1LL * x * m / n;
		for (int k = mid, tot = 1; tot <= 2 && k >= 0; ++tot, --k)
		{
			if (1ll * x * m == 1ll * k * n)
				continue;
			int g1 = gcd(x, k);
			int g2 = gcd(n - x, m - k);
			if (g1 > 1 || g2 > 1)
				continue;
			ans = min(ans, dist(0, 0, x, k) + dist(x, k, n, m));
			break;
		}
		for (int k = mid, tot = 1; tot <= 2 && k <= m; ++tot, ++k)
		{
			if (1ll * x * m == 1ll * k * n)
				continue;
			int g1 = gcd(x, k);
			int g2 = gcd(n - x, m - k);
			if (g1 > 1 || g2 > 1)
				continue;
			ans = min(ans, dist(0, 0, x, k) + dist(x, k, n, m));
			break;
		}
	}
	printf("%.12lf\n", ans);
}

int main()
{
	int Test;
	scanf("%d", &Test);
	while (Test--)
		solve();
#ifdef ONLINE
	system("pause");
#endif
	return 0;
}
