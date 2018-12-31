#include <cstdio>
#include <climits>
#include <cstring>
#define MAXN 105
using namespace std;

int a[MAXN][MAXN];
bool vis[MAXN];
int n, i, j;
bool flag;
bool finish;

void dfs(int pos, int hp)
{
	if (pos == n && hp > 0)
	{
		flag = false;
		finish = true;
		return ;
	}
	else if (pos == n && hp <= 0)
	{
		flag = true;
		return ;
	}
	if (hp <= 0)
	{
		flag = true;
		return ;
	}
	if (hp > 20000)
	{
		flag = false;
		return ;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i] && a[pos][i] != 0 && !finish)
		{
			vis[i] = true;
			dfs(i, hp * 2 + a[pos][i]);
			vis[i] = false;
		}
	}
}

int work()
{
	int left = -1, right = 20000, middle;
	while (left + 1 != right)
	{
		memset(vis, false, sizeof(vis));
		middle = left + (right - left) / 2;
		finish = false;
		flag = false;
		dfs(1, middle);
		if (flag) left = middle;
		else right = middle;
	}
	return right;
}

int main()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	printf("%d\n", work());
	return 0;
}
