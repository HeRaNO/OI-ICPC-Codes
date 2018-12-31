#include <cstdio>
#define MOD 1000007
using namespace std;

int a[101], dp[101][101] = {0};
int m, n;
int i, j, k;
int ans;

int main()
{
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	dp[0][0] = 1;
	for (i = 1; i <= n; i++)
		for (j = 0; j <= m; j++)
			for (k = 0; k <= a[i]; k++)
			{
				if (j >= k)
					dp[i][j] = (dp[i - 1][j - k] + dp[i][j]) % MOD;
			}
	printf("%d\n", dp[n][m] % MOD);
	return 0;
}
