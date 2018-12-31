#include <cstdio>
#define MAXN 25

bool l[MAXN], r[MAXN], c[MAXN];
int ans, p[266][MAXN], q[MAXN];

void dfs(int dep)
{
	if (dep == 10)
	{
		++ans;
		for (int i = 1; i <= 9; i++) p[ans][i] = q[i];
		return ;
	}
	for (int i = 1; i <= 9; i++)
		if (!c[i] && !r[i + dep] && !l[dep - i + 10])
		{
			q[dep] = i;
			c[i] = true;
			r[i + dep] = true;
			l[dep - i + 10] = true;
			dfs(dep + 1);
			q[dep] = 0;
			c[i] = false;
			r[i + dep] = false;
			l[dep - i + 10] = false;
		}
	return ;
}

int main()
{
	dfs(1);
	printf("%d\n", ans);
	for (int i = 1; i <= ans; i++)
		for (int j = 1; j <= 9; j++)
		{
			printf("%d ", p[i][j]);
			puts("");
		}
	return 0;
}