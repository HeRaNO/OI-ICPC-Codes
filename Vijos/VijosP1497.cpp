#include <cstdio>
#include <cstring>
#define MAXN 55
#define MAXL 1111
using namespace std;

int m, n;
int a[MAXN][MAXN];
int h, w, x, y;
char ans[MAXL][MAXL];

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			h = mymax(h, a[i][j] * 3 + (n - i) * 2 + 3);
	w = n * 2 + m * 4 + 1;
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			ans[i][j] = '.';
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (int k = 1; k <= a[i][j]; k++)
			{
				x = h - k * 3 - (n - i) * 2 + 3;
				y = (n - i) * 2 + j * 4 - 3;
				for (int p = x - 5; p <= x - 2; p++)
					for (int q = y + 2; q <= y + 6; q++)
					{
						if (p == x - 5 || p == x - 2)
						{
							if (q == y + 2 || q == y + 6) ans[p][q] = '+';
							else ans[p][q] = '-';
						}
						else
						{
							if (q == y + 2 || q == y + 6) ans[p][q] = '|';
							else ans[p][q] = ' ';
						}
					}
				for (int p = x - 3; p <= x; p++)
					for (int q = y; q <= y + 4; q++)
					{
						if (p == x - 3 || p == x)
						{
							if (q == y || q == y + 4) ans[p][q] = '+';
							else ans[p][q] = '-';
						}
						else
						{
							if (q == y || q == y + 4) ans[p][q] = '|';
							else ans[p][q] = ' ';
						}
					}
				ans[x - 2][y + 5] = ans[x - 4][y + 2] = ' ';
				ans[x - 4][y + 1] = ans[x - 1][y + 5] = ans[x - 4][y + 5] = '/';
			}
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
			printf("%c", ans[i][j]);
		printf("\n");
	}
	return 0;
}