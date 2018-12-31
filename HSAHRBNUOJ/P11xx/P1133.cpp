#include <cstdio>

int n, a[10];
bool vis[10];

void dfs(int dep)
{
	if (dep == n + 1)
	{
		for (int i = 1; i < n; i++) printf("%d ", a[i]);
		printf("%d\n", a[n]);
		return ;
	}
	for (int i = 1; i <= n; i++)
		if (!vis[i])
		{
			vis[i] = true;
			a[dep] = i;
			dfs(dep + 1);
			vis[i] = false;
		}
	return ;
}

int main()
{
	scanf("%d", &n);
	dfs(1);
	return 0;
}
