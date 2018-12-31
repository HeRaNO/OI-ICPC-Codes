#include<cstdio>
#define MOD 1000000007

int dp[2][333][333];
int n, m;

int main()
{
	scanf("%d %d", &n, &m);
	if (n > m)
	{
		printf("0");
		return 0;
	}
	dp[0][0][0] = 1;
	for (int k = 1; k <= m; k++)
	{
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= i; j++)
			{
				dp[k & 1][i][j] = dp[k - 1 & 1][i][j];
				if (i) dp[k & 1][i][j] = (dp[k - 1 & 1][i - 1][j] + dp[k & 1][i][j]) % MOD;
				if (j) dp[k & 1][i][j] = (dp[k - 1 & 1][i][j - 1] + dp[k & 1][i][j]) % MOD;
				if (i && j) dp[k & 1][i][j] = (dp[k - 1 & 1][i - 1][j - 1] + dp[k & 1][i][j]) % MOD;
			}
	}
	printf("%d\n", dp[m & 1][n][n] % MOD);
	return 0;
}
