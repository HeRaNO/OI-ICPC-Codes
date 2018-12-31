#include <cstdio>
#define MAXN 1010
using namespace std;

int n, a[MAXN][MAXN], dp[MAXN][MAXN][2], ans;

inline int mymax(int a, int b)
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
		for (int j = 1; j <= i; j++)
		{
			dp[i][j][0] = mymax(mymax(dp[i - 1][j][0], dp[i - 1][j][1]), mymax(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1])) + a[i][j];
			dp[i][j][1] = mymax(a[i][j], 0);
		}
	for (int i = 1; i <= n; i++) ans = mymax(ans, mymax(dp[n][i][0], dp[n][i][1]));
	printf("%d\n", ans);
	return 0;
}