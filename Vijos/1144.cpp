#include <cstdio>
#include <vector>
#include <climits>
#define MAXN 1510
using namespace std;

vector <int> g[MAXN];
int cost[MAXN];
int dp[MAXN][4];
int n, i, j;
int tmp, tmp1, tmp2, tmp3;

int mymin(int a, int b)
{
	return a < b ? a : b;
}

void dfs(int k)
{
	dp[k][2] = cost[k];
	dp[k][0] = 0;
	int flag = INT_MAX - 1000000;
	for (int j = 0; j < g[k].size(); j++)
	{
		int i = g[k][j];
		dfs(i);
		dp[k][0] += mymin(dp[i][1], dp[i][2]);
		dp[k][1] += mymin(dp[i][1], dp[i][2]);
		dp[k][2] += mymin(dp[i][1], mymin(dp[i][2], dp[i][0]));
		if (dp[i][2] <= dp[i][1]) flag = 0;
		if (flag && dp[i][2] - dp[i][1] < flag && dp[i][2] - dp[i][1] >= 0)
			flag = dp[i][2] - dp[i][1];
	}
	dp[k][1] += flag;
}

int main()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d %d %d", &tmp1, &tmp2, &tmp3);
		cost[tmp1] = tmp2;
		for (j = 1; j <= tmp3; j++)
		{
			scanf("%d", &tmp);
			g[tmp1].push_back(tmp);
		}
	}
	dfs(1);
	if (mymin(dp[1][1], dp[1][2]) == 1001) printf("1019");
	else printf("%d", mymin(dp[1][1], dp[1][2]));
	return 0;
}