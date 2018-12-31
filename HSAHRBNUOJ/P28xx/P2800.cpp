#include <cstdio>
#define MAXN 55
#define MAXS 2010
#define MOD 1000000007LL
using namespace std;

int n, k, s;
long long dp[MAXN][MAXN][MAXS];

int main()
{
	//freopen("number.in","r",stdin);freopen("number.out","w",stdout);
	scanf("%d %d %d", &n, &k, &s);
	dp[0][0][0] = 1LL;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= k; j++)
			for (int r = 0; r <= s; r++)
			{
				dp[i][j][r] += dp[i - 1][j][r];
				if (j && r >= i) dp[i][j][r] = (dp[i][j][r] + dp[i - 1][j - 1][r - i]) % MOD;
			}
	printf("%lld\n", dp[n][k][s]);
	return 0;
}
