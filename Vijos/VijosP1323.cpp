#include <cstdio>
#include <climits>
#define MAXN 150
#define MAXNUM 11
using namespace std;

int dp[MAXN][MAXNUM][MAXNUM][MAXNUM];
bool g[MAXN][MAXNUM][MAXNUM][MAXNUM];
int data[MAXN];
char c;
int n;

int mymin(int a, int b)
{
	return a < b ? a : b;
}

int dfs(int k, int a, int b, int c)
{
	int i, j = a + b + c;
	for (int i = 1; i <= 10 - j; i++)
	{
		k++;
		if (k > n) break;
		if (data[k] == 1) a++;
		else if (data[k] == 2) b++;
		else if (data[k] == 3) c++;
	}
	if (k >= n)
	{
		g[n][a][b][c] = true;
		dp[n][a][b][c] = (a > 0) + (b > 0) + (c > 0);
		return dp[n][a][b][c];
	}
	if (!g[k][a][b][c])
	{
		g[k][a][b][c] = true;
		dp[k][a][b][c] = INT_MAX;
		if (a) dp[k][a][b][c] = mymin(dp[k][a][b][c], dfs(k, 0, b, c) + 1);
		if (b) dp[k][a][b][c] = mymin(dp[k][a][b][c], dfs(k, a, 0, c) + 1);
		if (c) dp[k][a][b][c] = mymin(dp[k][a][b][c], dfs(k, a, b, 0) + 1);
	}
	return dp[k][a][b][c];
}

int main()
{
	scanf("%d\n", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%c\n", &c);
		data[i] = c - 64;
	}
	printf("%d\n", dfs(0, 0, 0, 0));
	return 0;
}