#include <cstdio>
#define MAXN 1000010
#define MOD 1000000007LL
using namespace std;

int n;
long long dp[MAXN][4], ans;

int main()
{
	scanf("%d", &n);
	dp[0][0] = 1LL;
	for (int i = 0; i <= n; i++)
	{
		dp[i + 3][0] = (dp[i][0] + dp[i + 3][0]) % MOD;
		dp[i + 3][1] = (dp[i][0] + dp[i + 3][1]) % MOD;
		dp[i + 3][3] = (dp[i][0] + dp[i + 3][3]) % MOD;
		dp[i + 2][0] = (dp[i][0] + dp[i + 2][0]) % MOD;
		dp[i + 3][2] = (dp[i][0] + dp[i + 3][2]) % MOD;
		dp[i + 3][3] = (dp[i][0] + dp[i + 3][3]) % MOD;
		dp[i + 2][2] = (dp[i][1] + dp[i + 2][2]) % MOD;
		dp[i + 3][3] = (dp[i][1] + dp[i + 3][3]) % MOD;
		dp[i + 2][3] = (dp[i][1] + dp[i + 2][3]) % MOD;
		dp[i + 2][0] = (dp[i][1] + dp[i + 2][0]) % MOD;
		dp[i + 1][0] = (dp[i][1] + dp[i + 1][0]) % MOD;
		dp[i + 3][1] = (dp[i][1] + dp[i + 3][1]) % MOD;
		dp[i + 2][3] = (dp[i][2] + dp[i + 2][3]) % MOD;
		dp[i + 3][2] = (dp[i][2] + dp[i + 3][2]) % MOD;
		dp[i + 2][0] = (dp[i][2] + dp[i + 2][0]) % MOD;
		dp[i + 3][0] = (dp[i][2] + dp[i + 3][0]) % MOD;
		dp[i + 3][1] = (dp[i][2] + dp[i + 3][1]) % MOD;
		dp[i + 3][3] = (dp[i][2] + dp[i + 3][3]) % MOD;
		dp[i + 2][2] = (dp[i][3] + dp[i + 2][2]) % MOD;
		dp[i + 2][0] = (dp[i][3] + dp[i + 2][0]) % MOD;
		dp[i + 2][0] = (dp[i][3] + dp[i + 2][0]) % MOD;
		dp[i + 2][3] = (dp[i][3] + dp[i + 2][3]) % MOD;
		dp[i + 3][1] = (dp[i][3] + dp[i + 3][1]) % MOD;
		dp[i + 3][3] = (dp[i][3] + dp[i + 3][3]) % MOD;
		ans = (ans + dp[i][0] + dp[i][1] + dp[i][2] + dp[i][3]) % MOD;
	}
	printf("%lld\n", ans);
	return 0;
}
