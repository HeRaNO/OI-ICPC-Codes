#include <cstdio>
#include <climits>
using namespace std;

int a[310], b[310][310], c[50][310], d[50][310];
int n, m, i, j, k;

int myabs(int a)
{
	return a > 0 ? a : -a;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)scanf("%d", &a[i]);
	for (i = 1; i < n; i++)
	{
		b[i][i + 1] = myabs(a[i + 1] - a[i]);
		b[i][i] = 0;
	}
	b[n][n] = 0;
	for (i = 2; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (j + i <= n)
			{
				int mid = i / 2 + j;
				b[j][j + i] = b[j + 1][j + i - 1] + myabs(a[j] - a[mid]) + myabs(a[j + i] - a[mid]);
			}
	for (i = 1; i <= n; i++) c[1][i] = b[1][i];
	d[1][i] = 1;
	for (i = 2; i <= m; i++)
	{
		j = n;
		c[i][j] = INT_MAX;
		for (k = d[i - 1][j]; k < j; k++)
			if (c[i - 1][k] + b[k + 1][j] < c[i][j])
				c[i][j] = c[i - 1][k] + b[k + 1][j], d[i][j] = k;
		for (j = n - 1; j > i; j--)
		{
			c[i][j] = INT_MAX;
			for (k = d[i - 1][j]; k <= d[i][j + 1]; k++)
				if (c[i - 1][k] + b[k + 1][j] < c[i][j])
					c[i][j] = c[i - 1][k] + b[k + 1][j], d[i][j] = k;
		}
	}
	printf("%d\n", c[m][n]);
	return 0;
}
