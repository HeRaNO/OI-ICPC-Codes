#include <stdio.h>
int n, a[8];
void dfs(int dep)
{
	int i;
	if (dep == n + 1)
	{
		for (i = 1; i < n; i++) printf("%d ", a[i]);
		printf("%d\n", a[n]);
		return ;
	}
	for (i = 1; i <= n; i++)
	{
		a[dep] = i;
		dfs(dep + 1);
	}
}
int main()
{
	scanf("%d", &n);
	dfs(1);
	return 0;
}
