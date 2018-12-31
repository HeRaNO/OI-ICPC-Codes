#include <cstdio>
#define MAXSUM 1800
#define MAXN 35
using namespace std;

int T, n, m;
double a[MAXN][MAXN];
double dp[MAXN][MAXN];
double ans;

double mymin(double a, double b)
{
	return a < b ? a : b;
}

void dpit(int x)
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			dp[i][j] = 1000000;
	double p = double(x) / double(n + m - 1);
	dp[1][1] = (a[1][1] - p) * (a[1][1] - p);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (dp[i][j] != 1000000)
			{
				dp[i + 1][j] = mymin(dp[i + 1][j], dp[i][j] + (a[i + 1][j] - p) * (a[i + 1][j] - p));
				dp[i][j + 1] = mymin(dp[i][j + 1], dp[i][j] + (a[i][j + 1] - p) * (a[i][j + 1] - p));
			}
	ans = mymin(ans, dp[n][m]);
	return ;
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		ans = 1000000;
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				scanf("%lf", &a[i][j]);
		for (int i = 1; i <= MAXSUM; i++) dpit(i);
		printf("%d\n", (int)(ans * (n + m - 1) + 1e-5));
	}
	return 0;
}
