#include <cstdio>
#include <cstring>
#define MOD 10000
#define MAXN 1010
using namespace std;

int dp[MAXN][MAXN], t, n, k;
int cas;

int main()
{
	scanf("%d", &cas);
	while (cas--)
	{
		scanf("%d %d", &n, &k);
		memset(dp, 0, sizeof dp);
		for (int i = 1; i <= n; i++) dp[i][0] = 1;
		for (int i = 2; i <= n; i++)
		{
			t = dp[i - 1][0];
			for (int j = 1; j <= k; j++)
			{
				if (j - i >= 0) t -= dp[i - 1][j - i];
				t += dp[i - 1][j];
				dp[i][j] = t % MOD;
			}
		}
		printf("%d\n", dp[n][k]);
	}
	return 0;
}