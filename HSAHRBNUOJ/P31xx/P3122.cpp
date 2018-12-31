#include <cstdio>
#define MAXN 1010
#define MOD 100003

int dp[MAXN][MAXN];
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) dp[1][i] = dp[i][1] = 1;
	for (int i = 2; i <= n; i++)
		for (int j = 2; j <= n; j++)
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
	printf("%d\n", dp[n][n]);
}
