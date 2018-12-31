#include <cstdio>
#include <cstring>
#define MAXN 110

int dis[MAXN][MAXN];
int n, m, u, v, w;

int mymin(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++) dis[i][j] = 50000000;
		dis[i][i] = 0;
	}
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &u, &v, &w);
		dis[u][v] = dis[v][u] = mymin(w, dis[u][v]);
	}
	for (int i = 1; i <= n; i++) dis[i][i] = 0;
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dis[i][j] = mymin(dis[i][j], dis[i][k] + dis[k][j]);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < n; j++) printf("%d ", dis[i][j]);
		printf("%d\n", dis[i][n]);
	}
	return 0;
}
