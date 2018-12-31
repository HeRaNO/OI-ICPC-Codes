//Code By HeRaNO
#include <stdio.h>
int i, j, n;
int f[45][45];
int main()
{
	scanf("%d", &n);
	f[1][1] = f[1][0] = 1;
	for (i = 2; i <= n; i++)
		for (j = i; j < 45; j++)
			f[i][j] = f[i - 1][j - 1] + f[i - 1][j - 2];
	for (i = 1; i <= n; i++)
		f[0][0] += f[i][n];
	printf("%d\n", f[0][0]);
	return 0;
}
