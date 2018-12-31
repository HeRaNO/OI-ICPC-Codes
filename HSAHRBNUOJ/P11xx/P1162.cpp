#include <cstdio>
#define MAXN 1010

int n, x, a[MAXN][2], ans;

void dfs(int x, int dep)
{
	if (dep > ans) ans = dep;
	if (a[x][0]) dfs(a[x][0], dep + 1);
	if (a[x][1]) dfs(a[x][1], dep + 1);
	return ;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return ;
}

int main()
{
	read(n);
	for (int i = 1; i < n; i++)
	{
		read(x);
		read(a[x][0]);
		read(a[x][1]);
	}
	dfs(1, 1);
	printf("%d\n", ans);
	return 0;
}