#include <cstdio>
#include <cstring>
#define MAXN 110
using namespace std;

int n;
int a[MAXN][MAXN];
int minn = 2147483647, maxx, middle;
bool vis[MAXN][MAXN];

int mymin(int a, int b)
{
	return a < b ? a : b;
}

int mymax(int a, int b)
{
	return a > b ? a : b;
}

void dfs(int x, int y, int mi, int ma)
{
	if (a[x][y] < mi || a[x][y] > ma) return ;
	vis[x][y] = true;
	if (x + 1 <= n && !vis[x + 1][y]) dfs(x + 1, y, mi, ma);
	if (x - 1 >= 1 && !vis[x - 1][y]) dfs(x - 1, y, mi, ma);
	if (y + 1 <= n && !vis[x][y + 1]) dfs(x, y + 1, mi, ma);
	if (y - 1 >= 1 && !vis[x][y - 1]) dfs(x, y - 1, mi, ma);
}

bool check(int limit)
{
	for (int i = minn; i <= maxx - limit; i++)
	{
		memset(vis, false, sizeof(vis));
		dfs(1, 1, i, i + limit);
		if (vis[n][n]) return true;
	}
	return false;
}

int binary()
{
	int left = 0, right = maxx - minn, middle;
	while (left <= right)
	{
		middle = (left + right) >> 1;
		if (check(middle)) right = middle - 1;
		else left = middle + 1;
	}
	return left;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &a[i][j]);
			minn = mymin(minn, a[i][j]);
			maxx = mymax(maxx, a[i][j]);
		}
	printf("%d\n", binary());
	return 0;
}
