#include <cstdio>
#include <cstring>
#define MAXN 50010

int n, c;
int e, f, l, x;
int dp[MAXN][40], happy[MAXN][40];
int like, hate;
int ans;

int mymax(int a, int b)
{
	return a > b ? a : b;
}

void dfs(int dep, int status)
{
	if (dep == 5)
	{
		if ((like & status) || (hate & status) != hate) happy[e][status]++;
		return ;
	}
	dfs(dep + 1, status);
	dfs(dep + 1, status | (1 << dep));
}

void dpit(int k)
{
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++)
	{
		if (i <= 4)
		{
			for (int j = 0; j < (1 << 5); j++)
			{
				if ((j & ((1 << (5 - i)) - 1)) == (k >> (i - 1)))
					dp[i][j] = mymax(dp[i - 1][(j << 1) & 31], dp[i - 1][((j << 1) & 31) | 1]) + happy[i][j];
				else dp[i][j] = 0;
			}
		}
		else if (i <= n - 4)
		{
			for (int j = 0; j < (1 << 5); j++)
				dp[i][j] = mymax(dp[i - 1][(j << 1) & 31], dp[i - 1][((j << 1) & 31) | 1]) + happy[i][j];
		}
		else
		{
			for (int j = 0; j < (1 << 5); j++)
			{
				if ((j >> (n - i + 1)) == (k & ((1 << (i + 4 - n)) - 1)))
					dp[i][j] = mymax(dp[i - 1][(j << 1) & 31], dp[i - 1][((j << 1) & 31) | 1]) + happy[i][j];
				else dp[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < (1 << 5); i++) ans = mymax(ans, dp[n][i]);
	return ;
}

int main()
{
	while (scanf("%d %d", &n, &c) == 2)
	{
		ans = -1;
		memset(happy, 0, sizeof(happy));
		for (int i = 1; i <= c; i++)
		{
			like = hate = 0;
			scanf("%d %d %d", &e, &f, &l);
			while (f--)
			{
				scanf("%d", &x);
				hate = hate | (1 << ((x - e + n) % n));
			}
			while (l--)
			{
				scanf("%d", &x);
				like = like | (1 << ((x - e + n) % n));
			}
			dfs(0, 0);
		}
		for (int i = 0; i < (1 << 4); i++) dpit(i);
		printf("%d\n\n", ans);
	}
	return 0;
}
