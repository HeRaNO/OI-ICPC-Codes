#include <cstdio>
#include <climits>
#include <cstring>
#define MAXN 60
using namespace std;

int dis[MAXN][MAXN];
int n, ans, best;

int mymin(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	while (scanf("%d", &n) != EOF && n)
	{
		memset(dis, 0, sizeof dis);
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
			{
				scanf("%d", &dis[i][j]);
				dis[j][i] = dis[i][j];
			}
		ans = dis[1][2];
		for (int i = 3; i <= n; i++)
		{
			best = INT_MAX;
			for (int j = 2; j < i; j++)
				best = mymin(best, (dis[1][i] + dis[j][i] - dis[1][j]) / 2);
			ans += best;
		}
		printf("%d\n", ans);
	}
	return 0;
}
