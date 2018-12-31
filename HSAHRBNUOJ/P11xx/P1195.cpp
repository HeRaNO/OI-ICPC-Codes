#include <cstdio>
#define MAXN 26
using namespace std;

int a[MAXN][MAXN], ans, n;
bool dp[MAXN][MAXN][101];

inline void max(int &a, int b)
{
	if (a < b) a = b;
	return ;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			scanf("%d", &a[i][j]);
	dp[1][1][a[1][1] % 100] = true;
	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= i; j++)
			for (int k = 0; k < 100; k++)
			{
				if (dp[i - 1][j][k]) dp[i][j][(k + a[i][j]) % 100] = true;
				if (dp[i - 1][j - 1][k]) dp[i][j][(k + a[i][j]) % 100] = true;
			}
	for (int i = 1; i <= n; i++)
		for (int j = 99; ~j; j--)
			if (dp[n][i][j]) max(ans, j);
	printf("%d\n", ans);
	return 0;
}