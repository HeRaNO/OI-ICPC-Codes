#include <cstdio>
#define MAXN 3000
using namespace std;

int n, m;
unsigned long long dp[12][MAXN];
int i;

void dfs(int c, int s1, int s2)
{
	if (c == n)
	{
		dp[i][s1] += dp[i - 1][s2];
		return ;
	}
	if (c + 1 <= n)
	{
		dfs(c + 1, s1 << 1, s2 << 1 | 1);
		dfs(c + 1, s1 << 1 | 1, s2 << 1);
	}
	if (c + 2 <= n)
		dfs(c + 2, s1 << 2 | 3, s2 << 2 | 3);
}

int main()
{
	scanf("%d %d", &n, &m);
	dp[0][(1 << n) - 1] = 1;
	for (i = 1; i <= m; i++)
		dfs(0, 0, 0);
	printf("%llu\n", dp[m][(1 << n) - 1]);
	return 0;
}
