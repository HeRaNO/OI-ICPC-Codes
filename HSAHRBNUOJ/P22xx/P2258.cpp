#include <cstdio>
#define MAXN 1010
#define MAXK 210
#define MOD 1000000007
using namespace std;

int dp[2][MAXN][MAXK], g[2][MAXN][MAXK];
int n, m, k;
char a[MAXN], b[MAXN];

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	scanf("%s", a + 1);
	scanf("%s", b + 1);
	dp[0][0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		dp[i & 1][0][0] = 1;
		for (int j = 1; j <= m; j++)
			for (int r = 1; r <= k; r++)
			{
				if (a[i] == b[j]) g[i & 1][j][r] = (dp[i - 1 & 1][j - 1][r - 1] + g[i - 1 & 1][j - 1][r]) % MOD;
				else g[i & 1][j][r] = 0;
				dp[i & 1][j][r] = (dp[i - 1 & 1][j][r] + g[i & 1][j][r]) % MOD;
			}
	}
	printf("%d\n", dp[n & 1][m][k]);
	return 0;
}
