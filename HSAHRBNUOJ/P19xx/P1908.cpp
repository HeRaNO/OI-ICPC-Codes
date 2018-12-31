#include <cstdio>
#include <cstring>
#include <climits>
#define MAXN 110
using namespace std;

int a[MAXN][MAXN];
bool vis[MAXN][MAXN], flag;
int ans = INT_MAX, n, l = INT_MAX, r;

int mymin(int a, int b)
{
	return a < b ? a : b;
}

int mymax(int a, int b)
{
	return a > b ? a : b;
}

void check(int x, int y, int l, int r)
{
	if (a[x][y] < l || a[x][y] > r) return ;
	if (x == n && y == n)
	{
		flag = true;
		return ;
	}
	if (flag) return;
	vis[x][y] = true;
	if (x + 1 <= n && !vis[x + 1][y]) check(x + 1, y, l, r);
	if (x - 1 >= 1 && !vis[x - 1][y]) check(x - 1, y, l, r);
	if (y + 1 <= n && !vis[x][y + 1]) check(x, y + 1, l, r);
	if (y - 1 >= 1 && !vis[x][y - 1]) check(x, y - 1, l, r);
	return ;
}

int binary(int x)
{
	int left = x, right = 201, middle, ans = -1;
	while (left <= right)
	{
		memset(vis, 0, sizeof vis);
		flag = false;
		middle = (left + right) >> 1;
		check(1, 1, x, middle);
		if (flag) right = middle - 1, ans = middle;
		else left = middle + 1;
	}
	if (ans != -1) return ans - x;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &a[i][j]);
			l = mymin(l, a[i][j]);
			r = mymax(r, a[i][j]);
		}
	for (int i = l; i <= r; i++) ans = mymin(ans, binary(i));
	printf("%d\n", ans);
	return 0;
}
