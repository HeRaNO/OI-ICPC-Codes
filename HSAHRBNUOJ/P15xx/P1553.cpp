#include <cstdio>
#include <cstring>
#include <climits>
#define MAXN 110
#define MAXK 15
using namespace std;

bool car[MAXN][MAXK];
int dp[MAXN][MAXK];
int n, k;
char c;

int mymin(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	memset(car, false, sizeof(car));
	scanf("%d %d", &n, &k);
	getchar();
	for (int i = n; i; i--)
	{
		for (int j = 1; j <= k; j++)
		{
			dp[i][j] = INT_MAX;
			c = getchar();
			if (c == '1') car[i][j] = true;
		}
		getchar();
	}
	if (n & 1) n--;
	int ans = INT_MAX;
	for (int i = 2; i <= n; i += 2)
		for (int j = 1; j <= k; j++)
		{
			if (j > 1) dp[i][j] = mymin(dp[i][j], dp[i - 2][j - 1] + car[i][j]);
			if (j < k) dp[i][j] = mymin(dp[i][j], dp[i - 2][j + 1] + car[i][j]);
			dp[i][j] = mymin(dp[i][j], dp[i - 2][j] + car[i - 1][j] + car[i][j]);
		}
	for (int i = 1; i <= k; i++) ans = mymin(ans, dp[n][i]);
	printf("%d\n", ans);
	return 0;
}
