#include <cstdio>
#include <climits>
#include <cstring>
#define MAXL 210
#define MAX 2139062143
using namespace std;

int dp[2][MAXL][MAXL];
int c[MAXL][MAXL];
int ans = INT_MAX;
int n, l, x, cur;
int last = 1;

int mymin(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	memset(dp, 0x7f, sizeof(dp));
	scanf("%d %d", &l, &n);
	for (int i = 1; i <= l; i++)
		for (int j = 1; j <= l; j++)
			scanf("%d", &c[i][j]);
	dp[cur][2][3] = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		for (int j = 1; j <= l; j++)
			for (int k = 1; k <= l; k++)
			{
				if (dp[cur][j][k] < MAX)
				{
					if (j != x && k != x) dp[1 - cur][j][k] = mymin(dp[1 - cur][j][k], dp[cur][j][k] + c[last][x]);
					if (last != x && k != x) dp[1 - cur][last][k] = mymin(dp[1 - cur][last][k], dp[cur][j][k] + c[j][x]);
					if (j != x && last != x) dp[1 - cur][j][last] = mymin(dp[1 - cur][j][last], dp[cur][j][k] + c[k][x]);
					dp[cur][j][k] = MAX;
				}
			}
		last = x;
		cur = 1 - cur;
	}
	for (int i = 1; i <= l; i++)
		for (int j = 1; j <= l; j++)
			ans = mymin(ans, dp[cur][i][j]);
	printf("%d\n", ans);
	return 0;
}
