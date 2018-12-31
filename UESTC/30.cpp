#include <stdio.h>
#include <string.h>

int n, m, a, b, c, f[101][101];

inline int min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	while (~scanf("%d %d", &n, &m) && n && m)
	{
		memset(f, 0x3f, sizeof f);
		for (int i = 1; i <= m; i++)
		{
			scanf("%d %d %d", &a, &b, &c);
			f[a][b] = f[b][a] = min(f[a][b], c);
		}
		for (int i = 1; i <= n; i++) f[i][i] = 0;
		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
		printf("%d\n", f[1][n]);
	}
	return 0;
}