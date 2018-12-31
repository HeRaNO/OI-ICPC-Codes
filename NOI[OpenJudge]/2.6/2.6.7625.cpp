//Code By HeRaNO
#include <cstdio>
#define MAXN 110
using namespace std;

int dp[MAXN][MAXN], a[MAXN][MAXN];
int ans, n;

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			scanf("%d", &a[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dp[i][j] = mymax(dp[i - 1][j], dp[i - 1][j - 1]) + a[i][j];
	for (int i = 1; i <= n; i++)
		ans = mymax(ans, dp[n][i]);
	printf("%d\n", ans);
	return 0;
}
