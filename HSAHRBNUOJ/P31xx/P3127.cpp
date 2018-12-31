#include <cstdio>
#define MAXM 1010
#define MAXN 2010
using namespace std;

long long a[MAXN][MAXM];
long long dp[MAXN][MAXM], ans = ~(1LL << 63);
int n, m;

long long mymin(long long a, long long b)
{
	return a < b ? a : b;
}

int main()
{
	//freopen("red.in","r",stdin);freopen("red.out","w",stdout);
	scanf("%d %d", &n, &m);
	for (int j = 1; j <= m; j++)
		for (int i = 1; i <= n; i++)
			scanf("%lld", &a[i][j]);
	for (int i = 1; i <= n; i++)
	{
		dp[i][1] = mymin(dp[i - 1][1], dp[i - 1][m]) + a[i][1];
		for (int j = 2; j <= m; j++)
			dp[i][j] = mymin(dp[i - 1][j], dp[i - 1][j - 1]) + a[i][j];
	}
	for (int i = 1; i <= m; i++) ans = mymin(ans, dp[n][i]);
	printf("%lld\n", ans);
	return 0;
}
