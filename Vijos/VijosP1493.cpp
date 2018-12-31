#include<cstdio>

int n, m;
int i, j, h, k;
int a[51][51];
int f[51][51][51][51];

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			for (h = 1; h <= n; h++)
				for (k = 1; k <= m; k++)
				{
					f[i][j][h][k] = mymax(mymax(f[i - 1][j][h - 1][k], f[i][j - 1][h][k - 1]), mymax(f[i - 1][j][h][k - 1], f[i][j - 1][h - 1][k])) + a[i][j];
					if (i != h && j != k)
						f[i][j][h][k] += a[h][k];
				}
	printf("%d", f[n][m][n][m]);
	return 0;
}