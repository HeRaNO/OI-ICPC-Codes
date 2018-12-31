#include <cstdio>
#include <cstring>
#define MAXN 100010
#define cleardp memset(dp,0,sizeof(dp));
using namespace std;

int dp[MAXN][4];
int a[MAXN][4];
int ans, n;

int mymax(int a, int b)
{
	return a > b ? a : b;
}

inline void dpit()
{
	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = mymax(dp[i - 1][2], dp[i - 1][3]) + a[i][0];
		dp[i][1] = dp[i - 1][3] + a[i][1];
		dp[i][2] = dp[i - 1][0] + a[i][1];
		dp[i][3] = mymax(dp[i - 1][0], dp[i - 1][1]) + a[i][2];
	}
	return ;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
	cleardp
	dp[1][0] = a[1][0];
	dpit();
	ans = mymax(ans, mymax(dp[n][2], dp[n][3]));
	cleardp
	dp[1][1] = a[1][1];
	dpit();
	ans = mymax(ans, dp[n][3]);
	cleardp
	dp[1][2] = a[1][1];
	dpit();
	ans = mymax(ans, dp[n][0]);
	cleardp
	dp[1][3] = a[1][2];
	dpit();
	ans = mymax(ans, mymax(dp[n][0], dp[n][1]));
	printf("%d\n", ans);
	return 0;
}
