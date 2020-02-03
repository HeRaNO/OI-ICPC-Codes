#include <cstdio>
#include <vector>
#define MAXN 6010
using namespace std;

bool road[MAXN][MAXN] = {false};
int dp[MAXN][2];
int laoda[MAXN];
int happy[MAXN];
int n, i, flag1, flag2;
vector <int> g[MAXN];

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

void dfs(int k)
{
	for (int j = 0; j < g[k].size(); j++)
	{
		int i = g[k][j];
		dfs(i);
		dp[k][0] += mymax(dp[i][0], dp[i][1]);
		dp[k][1] += dp[i][0];
	}
	dp[k][1] += happy[k];
}

int main()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &happy[i]);
	for (i = 2; i <= n; i++)
	{
		scanf("%d", &laoda[i]);
		g[laoda[i]].push_back(i);
	}
	for (i = 1; i <= n; i++)
	{
		if (!laoda[i])
		{
			dfs(i);
			printf("%d", mymax(dp[i][0], dp[i][1]));
			break;
		}
	}
	return 0;
}