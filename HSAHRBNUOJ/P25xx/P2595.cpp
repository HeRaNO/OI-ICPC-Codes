#include <cstdio>
#include <cstring>
#define MAXN 1510
using namespace std;

int dp[MAXN][MAXN];
bool a[MAXN][MAXN];
int n, m;
int ans;

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int mymin(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (i % 2 == j % 2) a[i][j] = !a[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i][j])
			{
				dp[i][j] = mymin(dp[i][j - 1], mymin(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
				ans = mymax(dp[i][j], ans);
			}
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (!a[i][j])
			{
				dp[i][j] = mymin(dp[i][j - 1], mymin(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
				ans = mymax(dp[i][j], ans);
			}
	printf("%d\n", ans);
	return 0;
}
