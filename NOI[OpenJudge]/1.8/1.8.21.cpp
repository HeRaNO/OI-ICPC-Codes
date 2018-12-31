//Code By HeRaNO
#include <stdio.h>

int i, j, n, m;
int a[105][105];

int main()
{
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	for (j = 1; j <= n + m - 1; j++)
		for (i = 1; i <= n; i++)
		{
			if (j - i + 1 <= 0 || j - i + 1 > m)
				continue;
			printf("%d\n", a[i][j - i + 1]);
		}
	return 0;
}