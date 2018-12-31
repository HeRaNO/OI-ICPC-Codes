#include <cstdio>
#define MAXN 26

int a[MAXN][MAXN], dp[MAXN][MAXN];
int n, p, ans;

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	scanf("%d", &n);
	p = n >> 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			scanf("%d", &a[i][j]);
	for (int i = 1; i <= p; i++)
		for (int j = 1; j <= i; j++)
			dp[i][j] = mymax(dp[i - 1][j], dp[i - 1][j - 1]) + a[i][j];
	for (int i = 1; i < p; i++) dp[p][i] = 0;
	for (int i = p + 1; i <= n; i++) dp[p][i] = 0;
	for (int i = p + 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			dp[i][j] = mymax(dp[i - 1][j], dp[i - 1][j - 1]) + a[i][j];
	for (int i = 1; i <= n; i++) ans = mymax(ans, dp[n][i]);
	printf("%d\n", ans);
	return 0;
}