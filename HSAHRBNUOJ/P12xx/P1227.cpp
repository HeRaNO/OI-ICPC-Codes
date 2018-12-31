#include <cstdio>
#define MAXN 11
using namespace std;

bool a[MAXN][MAXN], f[MAXN];
int n, m, ans[MAXN * MAXN], cnt, p = 1;

void dfs(int x, int pt)
{
	if (pt == p)
	{
		++cnt;
		return ;
	}
	if (x > m) return;
	dfs(x + 1, pt);
	for (int i = 1; i <= n; i++)
		if (a[i][x] && !f[i])
		{
			f[i] = true;
			dfs(x + 1, pt + 1);
			f[i] = false;
		}
	return ;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	while (true)
	{
		cnt = 0;
		dfs(1, 0);
		if (!cnt) break;
		ans[p++] = cnt;
	}
	printf("%d\n", --p);
	for (int i = 1; i <= p; i++) printf("%d:%d\n", i, ans[i]);
	return 0;
}