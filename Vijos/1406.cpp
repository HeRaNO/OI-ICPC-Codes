#include <queue>
#include <cstdio>
#define MAXN 25
using namespace std;

int dis[MAXN * MAXN][MAXN * MAXN];
char a[MAXN][MAXN];
int n, m, ans = 1e7;

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

inline void add(int p, int i, int j)
{
	if (a[i][j] == a[i][j + 1] && j + 1 < m) dis[p][p + 1] = dis[p + 1][p] = 0;
	else if (a[i][j] != a[i][j + 1] && j + 1 < m) dis[p][p + 1] = dis[p + 1][p] = 1;
	if (a[i][j] == a[i][j - 1] && j - 1 >= 0) dis[p][p - 1] = dis[p - 1][p] = 0;
	else if (a[i][j] != a[i][j - 1] && j - 1 >= 0) dis[p][p - 1] = dis[p - 1][p] = 1;
	if (a[i][j] == a[i + 1][j] && i + 1 < n) dis[p][p + m] = dis[p + m][p] = 0;
	else if (a[i][j] != a[i + 1][j] && i + 1 < n) dis[p][p + m] = dis[p + m][p] = 1;
	if (a[i][j] == a[i - 1][j] && i - 1 >= 0) dis[p][p - m] = dis[p - m][p] = 0;
	else if (a[i][j] != a[i - 1][j] && i - 1 >= 0) dis[p][p - m] = dis[p - m][p] = 1;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%s", a[i]);
	for (int i = 0; i <= n * m; i++)
		for (int j = 0; j <= n * m; j++)
			dis[i][j] = 1e7;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			add(i * m + j, i, j);
	for (int i = (n - 1) * m; i < m * n; i++) dis[n * m][i] = dis[i][n * m] = 1;
	for (int k = 0; k <= m * n; k++)
		for (int i = 0; i <= n * m; i++)
			for (int j = 0; j <= n * m; j++)
				dis[i][j] = mymin(dis[i][j], dis[i][k] + dis[k][j]);
	for (int i = 0; i < m; i++)
		ans = mymin(ans, dis[i][n * m]);
	printf("%d\n", ans);
	return 0;
}
