#include <cstdio>
#include <algorithm>
#define MAXN 35
#define INT_MAX 2147483647
using namespace std;

char g[MAXN][MAXN], f[MAXN][MAXN], s[26];
int x[26][2], y[26][2];
bool appear[26], used[26];
int cnt, a[26];
int n, m;

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}
inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

inline void check()
{
	for (int i = 1; i <= cnt; i++)
	{
		for (int j = x[s[a[i]] - 'A'][0]; j <= x[s[a[i]] - 'A'][1]; j++)
			f[y[s[a[i]] - 'A'][0]][j] = f[y[s[a[i]] - 'A'][1]][j] = s[a[i]];
		for (int j = y[s[a[i]] - 'A'][0]; j <= y[s[a[i]] - 'A'][1]; j++)
			f[j][x[s[a[i]] - 'A'][0]] = f[j][x[s[a[i]] - 'A'][1]] = s[a[i]];
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (g[i][j] != '.' && f[i][j] != g[i][j]) return ;
	for (int i = 1; i <= cnt; i++) putchar(s[a[i]]);
	putchar('\n');
	return ;
}

void dfs(int dep)
{
	if (dep == cnt + 1)
	{
		check();
		return ;
	}
	for (int i = 1; i <= cnt; i++)
		if (!used[i])
		{
			used[i] = true;
			a[dep] = i;
			dfs(dep + 1);
			used[i] = false;
		}
	return ;
}

int main()
{
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 1; i <= n; i++) scanf("%s", g[i] + 1);
	for (int i = 0; i < 26; i++) x[i][0] = y[i][0] = INT_MAX;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (g[i][j] != '.')
			{
				if (!appear[g[i][j] - 'A'])
				{
					appear[g[i][j] - 'A'] = true;
					cnt++;
					s[cnt] = g[i][j];
				}
				x[g[i][j] - 'A'][0] = mymin(x[g[i][j] - 'A'][0], j);
				x[g[i][j] - 'A'][1] = mymax(x[g[i][j] - 'A'][1], j);
				y[g[i][j] - 'A'][0] = mymin(y[g[i][j] - 'A'][0], i);
				y[g[i][j] - 'A'][1] = mymax(y[g[i][j] - 'A'][1], i);
			}
	sort(s + 1, s + cnt + 1);
	dfs(1);
	return 0;
}
