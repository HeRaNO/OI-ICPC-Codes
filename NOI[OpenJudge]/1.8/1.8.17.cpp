//Code By HeRaNO
#include <cstdio>
#define MAXN 1010
using namespace std;

int a[MAXN][MAXN];
char ch;
int r, c;
int ans;

void dfs(int x, int y)
{
	a[x][y] = 0;
	if (a[x - 1][y]) dfs(x - 1, y);
	if (a[x][y - 1]) dfs(x, y - 1);
	if (a[x + 1][y]) dfs(x + 1, y);
	if (a[x][y + 1]) dfs(x, y + 1);
	return ;
}

int main()
{
	scanf("%d %d", &r, &c);
	getchar();
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			ch = getchar();
			if (ch == '#') a[i][j] = 1;
		}
		getchar();
	}
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
		{
			if (a[i][j])
			{
				dfs(i, j);
				ans++;
			}
		}
	printf("%d\n", ans);
	return 0;
}
