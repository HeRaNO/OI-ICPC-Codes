#include <cstdio>
#include <climits>
#define MAXN 160
using namespace std;

char g[MAXN][MAXN];
int n;
int dp[MAXN][MAXN], ans;

int mymin(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%s", g[i]);
	for (int i = 1; i <= n; i++)
		for (int j = n; j; j--)
		{
			if (g[i][j - 1] == 'B') dp[i][j] = 0;
			else dp[i][j] = dp[i][j + 1] + 1;
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (g[i][j - 1] == 'B') continue;
			int res = INT_MAX;
			for (int k = i; k <= n && g[k][j - 1] != 'B'; k++)
			{
				res = mymin(res, dp[k][j]);
				ans += res;
			}
		}
	printf("%d\n", ans);
	return 0;
}
