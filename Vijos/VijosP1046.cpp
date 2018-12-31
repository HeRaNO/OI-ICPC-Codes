#include <cstdio>
#define MAXN 101
#define INF 2147483647LL
using namespace std;

long long a[MAXN][MAXN], dis[MAXN][MAXN], w, ans;
int n, m, u, v;

inline long long mymin(long long a, long long b)
{
	return a < b ? a : b;
}

inline void clean()
{
	ans = INF;
	for (int i = 0; i < MAXN; i++)
	{
		for (int j = 0; j < MAXN; j++) dis[i][j] = a[i][j] = INF;
		dis[i][i] = 0LL;
	}
	return ;
}

int main()
{
	while (~scanf("%d %d", &n, &m))
	{
		clean();
		for (int i = 1; i <= m; i++)
		{
			scanf("%d %d %lld", &u, &v, &w);
			dis[u][v] = dis[v][u] = mymin(dis[u][v], w);
			a[u][v] = a[v][u] = mymin(a[u][v], w);
		}
		for (int k = 1; k <= n; k++)
		{
			for (int i = 1; i < k; i++)
				for (int j = i + 1; j < k; j++)
					ans = mymin(ans, dis[i][j] + a[i][k] + a[k][j]);
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					dis[i][j] = mymin(dis[i][j], dis[i][k] + dis[k][j]);
		}
		if (ans == INF) puts("No solution.");
		else printf("%lld\n", ans);
	}
	return 0;
}
