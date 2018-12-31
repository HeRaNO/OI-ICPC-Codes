#include <cstdio>
#define MAXN 110
using namespace std;

const int d[4][2] =
{
	{1, 0}, {-1, 0},
	{0, 1}, {0, -1}
};

int dp[MAXN][MAXN], a[MAXN][MAXN];
int n, k;

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

int dfs(int x, int y)
{
	if (dp[x][y]) return dp[x][y];
	for (int i = 0; i < 4; i++)
		for (int j = 1; j <= k; j++)
		{
			int tx = x + d[i][0] * j, ty = y + d[i][1] * j;
			if (tx > 0 && tx <= n && ty > 0 && ty <= n && a[tx][ty] > a[x][y]) dp[x][y] = mymax(dp[x][y], dfs(tx, ty));
		}
	dp[x][y] += a[x][y];
	return dp[x][y];
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	printf("%d\n", dfs(1, 1));
	return 0;
}
