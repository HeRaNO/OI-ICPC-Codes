#include <cstdio>
using namespace std;

int n;
bool used[9][9];
int mem[9][9];
int ans;

int mymax(int a, int b)
{
	return a > b ? a : b;
}

void dfs(int x, int y, int have)
{
	if (y > 8)
	{
		dfs(x + 1, 1, have);
		return;
	}
	if (x > n)
	{
		ans = mymax(have, ans);
		return;
	}
	if (used[x][y])
	{
		dfs(x, y + 1, have);
		return;
	}
	else
	{
		if (have >= mem[x][y])
		{
			mem[x][y] = have;
			if (!used[x][y + 1] && !used[x][y + 2] && y <= 6) //1
			{
				used[x][y + 1] = true;
				used[x][y + 2] = true;
				dfs(x, y + 1, have + 1);
				used[x][y + 1] = false;
				used[x][y + 2] = false;
			}
			if (!used[x][y + 1] && !used[x + 1][y] && y <= 7 && x <= n - 1) //3
			{
				used[x][y + 1] = true;
				used[x + 1][y] = true;
				dfs(x, y + 1, have + 1);
				used[x][y + 1] = false;
				used[x + 1][y] = false;
			}
			if (x <= n - 2 && !used[x + 1][y] && !used[x + 2][y]) //6
			{
				used[x + 1][y] = true;
				used[x + 2][y] = true;
				dfs(x, y + 1, have + 1);
				used[x + 1][y] = false;
				used[x + 2][y] = false;
			}
			if (x <= n - 1 && !used[x + 1][y] && !used[x + 1][y + 1] && y <= 7) //4
			{
				used[x + 1][y] = true;
				used[x + 1][y + 1] = true;
				dfs(x, y + 1, have + 1);
				used[x + 1][y] = false;
				used[x + 1][y + 1] = false;
			}
			if (x <= n - 1 && y <= 7 && !used[x][y + 1] && !used[x + 1][y + 1]) //2
			{
				used[x][y + 1] = true;
				used[x + 1][y + 1] = true;
				dfs(x, y + 1, have + 1);
				used[x][y + 1] = false;
				used[x + 1][y + 1] = false;
			}
			if (x <= n - 1 && !used[x + 1][y] && !used[x + 1][y - 1] && y > 1) //5
			{
				used[x + 1][y] = true;
				used[x + 1][y - 1] = true;
				dfs(x, y + 1, have + 1);
				used[x + 1][y] = false;
				used[x + 1][y - 1] = false;
			}
			dfs(x, y + 1, have);
		}
	}
}

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= 8; j++)
			scanf("%d", &used[i][j]);
	dfs(1, 1, 0);
	printf("%d\n", ans);
	return 0;
}
