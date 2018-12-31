#include <cstdio>
#define MAXN 2010
#define MAXM 2010
#define MAXV 310
using namespace std;

int n, m, v, e, x, y, z;
int c[MAXN], d[MAXN], dis[MAXV][MAXV];
double dp[MAXN][MAXM][2], p[MAXN], ans = 1e18;

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}
inline double mymin(double a, double b)
{
	return a < b ? a : b;
}

inline void Pre_Work()
{
	for (int i = 0; i < MAXV; i++)
	{
		for (int j = 0; j < MAXV; j++) dis[i][j] = 1e9;
		dis[i][i] = 0;
	}
	for (int i = 1; i < MAXN; i++) dp[i][0][1] = 1e17;
	return ;
}

inline void Floyed()
{
	for (int k = 1; k <= v; k++)
		for (int i = 1; i <= v; i++)
			for (int j = 1; j <= v; j++)
				dis[i][j] = mymin(dis[i][j], dis[i][k] + dis[k][j]);
	return ;
}

int main()
{
	Pre_Work();
	scanf("%d %d %d %d", &n, &m, &v, &e);
	for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &d[i]);
	for (int i = 1; i <= n; i++) scanf("%lf", &p[i]);
	for (int i = 1; i <= e; i++)
	{
		scanf("%d %d %d", &x, &y, &z);
		dis[x][y] = dis[y][x] = mymin(dis[x][y], z);
	}
	Floyed();
	for (int i = 2; i <= n; i++)
	{
		dp[i][0][0] = dp[i - 1][0][0] + (double)dis[c[i - 1]][c[i]];
		for (int j = 1; j <= m; j++)
		{
			dp[i][j][0] = mymin(dp[i - 1][j][0] + (double)dis[c[i - 1]][c[i]]
								, dp[i - 1][j][1] + (double)dis[d[i - 1]][c[i]] * p[i - 1]
								+ (double)dis[c[i - 1]][c[i]] * (1.0 - p[i - 1])
							   );
			dp[i][j][1] = mymin(dp[i - 1][j - 1][0] + (double)dis[c[i - 1]][d[i]] * p[i]
								+ (double)dis[c[i - 1]][c[i]] * (1.0 - p[i])
								, dp[i - 1][j - 1][1] + (double)dis[d[i - 1]][d[i]] * p[i - 1] * p[i]
								+ (double)dis[d[i - 1]][c[i]] * p[i - 1] * (1.0 - p[i])
								+ (double)dis[c[i - 1]][d[i]] * (1.0 - p[i - 1]) * p[i]
								+ (double)dis[c[i - 1]][c[i]] * (1.0 - p[i - 1]) * (1.0 - p[i])
							   );
		}
	}
	for (int i = 0; i <= m; i++) ans = mymin(ans, mymin(dp[n][i][0], dp[n][i][1]));
	printf("%.2lf\n", ans);
	return 0;
}
