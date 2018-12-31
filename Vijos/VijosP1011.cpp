#include <stdio.h>

int i, j, n, m, ma;
int a[1005][1005], f[1005][1005];

int max(int a, int b)
{
	if (a > b) return a;
	else return b;
}

int dfs(int x, int y)
{
	if (f[x][y] != -1) return f[x][y];
	f[x][y] = 0;
	if (a[x - 1][y] > a[x][y]) f[x][y] = max(f[x][y], dfs(x - 1, y));
	if (a[x + 1][y] > a[x][y]) f[x][y] = max(f[x][y], dfs(x + 1, y));
	if (a[x][y - 1] > a[x][y]) f[x][y] = max(f[x][y], dfs(x, y - 1));
	if (a[x][y + 1] > a[x][y]) f[x][y] = max(f[x][y], dfs(x, y + 1));
	f[x][y]++;
	return f[x][y];
}

int main()
{
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
			f[i][j] = -1;
		}
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			ma = max(ma, dfs(i, j));
	printf("%d\n", ma);
	return 0;
}
