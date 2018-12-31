//Code By HeRaNO
#include <stdio.h>
#define MAXN 1005

int n, m;
int a[MAXN][MAXN], f[MAXN][MAXN];
int ans;

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int dfs(int x, int y)
{
	if (f[x][y] != -1)
		return f[x][y];
	f[x][y] = 0;
	if (a[x - 1][y] > a[x][y])
		f[x][y] = mymax(f[x][y], dfs(x - 1, y));
	if (a[x + 1][y] > a[x][y])
		f[x][y] = mymax(f[x][y], dfs(x + 1, y));
	if (a[x][y - 1] > a[x][y])
		f[x][y] = mymax(f[x][y], dfs(x, y - 1));
	if (a[x][y + 1] > a[x][y])
		f[x][y] = mymax(f[x][y], dfs(x, y + 1));
	f[x][y]++;
	return f[x][y];
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
			f[i][j] = -1;
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			ans = mymax(ans, dfs(i, j));
	printf("%d\n", ans);
	return 0;
}
