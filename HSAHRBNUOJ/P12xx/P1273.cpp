#include <cstdio>
using namespace std;

bool map[51][51];
bool vis[51];
int ans[51];
int n, a, b, k, i;
bool flag = false;

void dfs(int dep)
{
	if (k == n && !flag)
	{
		if (map[dep][1])
		{
			for (i = 1; i < n; i++)
				printf("%d ", ans[i]);
			printf("%d\n", ans[n]);
			flag = true;
			return ;
		}
		else return ;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i] && map[dep][i])
		{
			vis[i] = true;
			k++;
			ans[k] = i;
			dfs(i);
			vis[i] = false;
			k--;
		}
	}
}

int main()
{
	scanf("%d", &n);
	while (scanf("%d %d", &a, &b) != EOF)
	{
		map[a][b] = true;
		map[b][a] = true;
	}
	vis[1] = true;
	k = 1;
	ans[1] = 1;
	dfs(1);
	return 0;
}
