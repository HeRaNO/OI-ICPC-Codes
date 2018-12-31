#include <cstdio>
#define MAXN 1000010

int w, z, a, b;
int dp[MAXN];

int dfs(int x)
{
	if (x > w) return 0;
	if (dp[x]) return dp[x];
	dp[x] = dfs(x + a) + dfs(x + b);
	return dp[x];
}

int main()
{
	scanf("%d %d", &w, &z);
	scanf("%d %d", &a, &b);
	dp[w - a] = dp[w - b] = 1;
	printf("%d\n", dfs(z));
	return 0;
}
