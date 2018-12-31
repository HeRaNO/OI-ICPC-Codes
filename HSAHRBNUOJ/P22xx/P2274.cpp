#include <cstdio>
#include <cstring>
#include <climits>
#define MAXN 3010
#define MAXK 3010
using namespace std;

int dp[MAXN][MAXN], last[MAXN][MAXN];
int a[MAXN];
int n, k, cnt, x;

int mymin(int a, int b)
{
	return a < b ? a : b;
}

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		if (x < 120) a[++cnt] = x;
	}
	n = cnt;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dp[i][j] = INT_MAX;
	last[0][0] = 120;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= mymin(i, k); j++)
		{
			dp[i][j] = dp[i - 1][j];
			last[i][j] = last[i - 1][j];
			if (last[i - 1][j - 1] > a[i])
			{
				if (dp[i][j] == dp[i - 1][j - 1])
					last[i][j] = mymax(last[i][j], last[i - 1][j - 1] - a[i]);
				if (dp[i][j] > dp[i - 1][j - 1])
				{
					dp[i][j] = dp[i - 1][j - 1];
					last[i][j] = last[i - 1][j - 1] - a[i];
				}
			}
			else
			{
				if (dp[i][j] == dp[i - 1][j - 1] + 1)
					last[i][j] = mymax(last[i][j], 120 - a[i]);
				if (dp[i][j] > dp[i - 1][j - 1] + 1)
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
					last[i][j] = 120 - a[i];
				}
			}
		}
	if (dp[n][k] == INT_MAX) printf("You can't do it.\n");
	else printf("%d\n", dp[n][k] + 1);
	return 0;
}
