#include <cstdio>
#define MAXN 25

bool vis[MAXN];
int a[MAXN], n, r;

void dfs(int dep)
{
	if (dep == r + 1)
	{
		for (int i = 1; i < r; i++) printf("%d ", a[i]);
		printf("%d\n", a[r]);
		return ;
	}
	for (int i = 1; i <= n; i++)
		if (!vis[i] && a[dep - 1] < i)
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
	scanf("%d %d", &n, &r);
	dfs(1);
	return 0;
}
