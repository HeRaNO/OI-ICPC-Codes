//Code By HeRaNO
#include <cstdio>
#define MAXN 110
using namespace std;

int r, c, n;
char a[MAXN][MAXN], ans[MAXN][MAXN];

int main()
{
	scanf("%d %d %d", &r, &c, &n);
	getchar();
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
			a[i][j] = ans[i][j] = getchar();
		getchar();
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= r; j++)
			for (int k = 1; k <= c; k++)
			{
				if (a[j][k] == 'R')
				{
					if (a[j - 1][k] == 'S') ans[j - 1][k] = a[j][k];
					if (a[j + 1][k] == 'S') ans[j + 1][k] = a[j][k];
					if (a[j][k - 1] == 'S') ans[j][k - 1] = a[j][k];
					if (a[j][k + 1] == 'S') ans[j][k + 1] = a[j][k];
				}
				if (a[j][k] == 'S')
				{
					if (a[j - 1][k] == 'P') ans[j - 1][k] = a[j][k];
					if (a[j + 1][k] == 'P') ans[j + 1][k] = a[j][k];
					if (a[j][k - 1] == 'P') ans[j][k - 1] = a[j][k];
					if (a[j][k + 1] == 'P') ans[j][k + 1] = a[j][k];
				}
				if (a[j][k] == 'P')
				{
					if (a[j - 1][k] == 'R') ans[j - 1][k] = a[j][k];
					if (a[j + 1][k] == 'R') ans[j + 1][k] = a[j][k];
					if (a[j][k - 1] == 'R') ans[j][k - 1] = a[j][k];
					if (a[j][k + 1] == 'R') ans[j][k + 1] = a[j][k];
				}
			}
		for (int i = 1; i <= r; i++)
			for (int j = 1; j <= c; j++)
				a[i][j] = ans[i][j];
	}
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
			printf("%c", a[i][j]);
		printf("\n");
	}
	return 0;
}
