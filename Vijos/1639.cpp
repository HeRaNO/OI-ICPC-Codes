#include <cstdio>
#include <climits>
#define MAXN 1100
using namespace std;

int dp[MAXN][MAXN];
int ans[MAXN][2];
int n, k, m, i, j;
int p, q, cnt;
int a[MAXN];
int sum[MAXN];

int mymax(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	scanf("%d %d", &n, &k);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= k; j++)
			dp[i][j] = INT_MAX;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		sum[i] = sum[i - 1] + a[i];
		dp[i][1] = sum[i];
	}
	for (m = 2; m <= k; m++)
		for (i = 1; i <= n; i++)
			for (j = 1; j < i; j++)
			{
				if (dp[i][m] > mymax(dp[j][m - 1], sum[i] - sum[j]))
					dp[i][m] = mymax(dp[j][m - 1], sum[i] - sum[j]);
			}
	p = n, q = k;
	for (i = n; i >= 1; i--)
	{
		cnt += a[i];
		if (cnt > dp[n][k])
		{
			ans[q][0] = i + 1;
			ans[q][1] = p;
			p = i;
			q--;
			cnt = a[i];
		}
	}
	ans[1][0] = 1;
	ans[1][1] = p;
	for (int i = 1; i <= k; i++)
		if (ans[i][0] && ans[i][1])
			printf("%d %d\n", ans[i][0], ans[i][1]);
	return 0;
}