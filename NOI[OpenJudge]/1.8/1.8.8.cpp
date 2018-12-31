//Code By HeRaNO
#include <stdio.h>
#include <iostream>
using namespace std;
int ans = 0, n, m, x, i, j;
int a[1005][1005], b[1005][1005];
int main()
{
	cin >> n >> m;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			scanf("%d", &b[i][j]);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
		{
			printf("%d ", a[i][j] + b[i][j]);
			if (j == m)
				printf("\n");
		}
	return 0;
}

