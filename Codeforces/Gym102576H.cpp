#include <bits/stdc++.h>
#define ll long long
#define ls id << 1
#define rs id << 1 | 1
#define mem(array, value, size, type) memset(array, value, ((size) + 5) * sizeof(type))
#define memarray(array, value) memset(array, value, sizeof(array))
#define pb(x) push_back(x)
#define st(x) (1LL << (x))
#define pii pair<int, int>
#define mp(a, b) make_pair((a), (b))
#define Flush fflush(stdout)
using namespace std;
const int N = 350;
const int inf = 0x3f3f3f3f;
const ll mod = 998244353LL;
clock_t TIME_START, TIME_END;
void program_end()
{
#ifdef ONLINE
	printf("\nTime used: %.6lf(s)\n", ((double)TIME_END - TIME_START) / CLOCKS_PER_SEC);
	system("pause");
#endif
}
int n, m;
double dp[N][N][2];
double d[N][N];
bool exist[N][N];
struct convex
{
	ll x, y;
} p1[N];
inline double dist(const convex &X, const convex &Y)
{
	return sqrt(1.0 * (X.x - Y.x) * (X.x - Y.x) + 1.0 * (X.y - Y.y) * (X.y - Y.y));
}
inline int nxt(int i)
{
	int ret = (i + 1) % n;
	if (ret == 0)
		ret = n;
	return ret;
}

void solve()
{
	scanf("%d", &n);
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= n; ++j)
			exist[i][j] = 0;
	for (int i = 1; i <= n; ++i)
		scanf("%lld%lld", &p1[i].x, &p1[i].y);
	scanf("%d", &m);
	double ans = -1e18;
	for (int i = 1; i <= m; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		d[x][y] = d[y][x] = dist(p1[x], p1[y]);
		exist[x][y] = exist[y][x] = 1;
	}
	for (int i = 0; i <= n + 1; ++i)
		for (int j = 0; j <= n + 1; ++j)
			dp[i][j][0] = dp[i][j][1] = -1e18;
	for (int i = 0; i <= n; ++i)
		dp[i][i][0] = 0;
	for (int o = 1; o <= n; ++o)
	{
		for (int i = 1; i <= n; ++i)
		{
			int j = (o + i - 2) % n + 1;
			ans = max(ans, max(dp[i][j][0], dp[i][j][1]));
			for (int k = nxt(j); k != i; k = nxt(k))
			{
				if (exist[i][k])
				{
					dp[k][j][0] = max(dp[k][j][0], dp[i][j][0] + d[i][k]);
					dp[i][k][1] = max(dp[i][k][1], dp[i][j][0] + d[i][k]);
				}
				if (exist[j][k])
				{
					dp[k][j][0] = max(dp[k][j][0], dp[i][j][1] + d[j][k]);
					dp[i][k][1] = max(dp[i][k][1], dp[i][j][1] + d[j][k]);
				}
			}
		}
	}
	printf("%.12lf\n", ans);
}

int main()
{
	TIME_START = clock();
	int Test = 1;
	cin >> Test;
	while (Test--)
		solve();
	TIME_END = clock();
	program_end();
	return 0;
}