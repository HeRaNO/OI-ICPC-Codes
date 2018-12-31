//Code By HeRaNO
#include <cmath>
#include <cstdio>
#define MAXN 101
using namespace std;

char mine[MAXN][MAXN];
int n, m;

char gather(int a, int b)
{
	int num = 0;
	if (mine[a - 1][b] == '*') num++;
	if (mine[a + 1][b] == '*') num++;
	if (mine[a][b - 1] == '*') num++;
	if (mine[a][b + 1] == '*') num++;
	if (mine[a - 1][b - 1] == '*') num++;
	if (mine[a - 1][b + 1] == '*') num++;
	if (mine[a + 1][b - 1] == '*') num++;
	if (mine[a + 1][b + 1] == '*') num++;
	return num + '0';
}

int main()
{
	scanf("%d %d", &n, &m);
	getchar();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			mine[i][j] = getchar();
		getchar();
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (mine[i][j] != '*')
				mine[i][j] = gather(i, j);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			putchar(mine[i][j]);
		putchar('\n');
	}
	return 0;
}
