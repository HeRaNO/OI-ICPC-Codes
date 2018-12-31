#include <cstdio>
#include <cstring>
#define MAXN 200
using namespace std;

int n, q, i, j, k, u, v, w;
int child[MAXN][3];
int g[MAXN][MAXN];
int dp[MAXN][MAXN];
int num[MAXN];

int mymax(int a, int b)
{
	return a > b ? a : b;
}

void Build_A_Tree(int k)
{
	for (int i = 1; i <= n; i++)
	{
		if (g[k][i] >= 0)
		{
			child[k][1] = i;
			num[i] = g[k][i];
			g[k][i] = g[i][k] = -1;
			Build_A_Tree(i);
			break;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (g[k][i] >= 0)
		{
			child[k][2] = i;
			num[i] = g[k][i];
			g[k][i] = g[i][k] = -1;
			Build_A_Tree(i);
			break;
		}
	}
}

void TreeDp(int k, int j)
{
	if (!j) dp[k][j] = 0;
	else if (child[k][1] == 0 && child[k][2] == 0) dp[k][j] = num[k];
	else
	{
		dp[k][j] = 0;
		for (int i = 0; i < j; i++)
		{
			if (!dp[child[k][1]][i]) TreeDp(child[k][1], i);
			if (!dp[child[k][2]][j - i - 1]) TreeDp(child[k][2], j - i - 1);
			dp[k][j] = mymax(dp[k][j], dp[child[k][1]][i] + dp[child[k][2]][j - i - 1] + num[k]);
		}
	}
}

int main()
{
	memset(g, -1, sizeof g);
	scanf("%d %d", &n, &q);
	for (i = 1; i < n; i++)
	{
		scanf("%d %d %d", &u, &v, &w);
		g[u][v] = w;
		g[v][u] = w;
	}
	Build_A_Tree(1);
	TreeDp(1, q + 1);
	printf("%d\n", dp[1][q + 1]);
	return 0;
}
