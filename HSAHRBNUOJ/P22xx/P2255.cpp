#include <cstdio>
#include <cstring>
#include <climits>
#define MAXN 200005
using namespace std;

int n, ans = INT_MAX, y;
int father[MAXN], nxt[MAXN], dfn[MAXN];
bool vis[MAXN];

inline int read()
{
	int x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return x;
}

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

int getfather(int x)
{
	return x == father[x] ? x : father[x] = getfather(father[x]);
}

void dfs(int x, int dep)
{
	vis[x] = true;
	dfn[x] = dep;
	if (!vis[nxt[x]]) dfs(nxt[x], dep + 1);
	else
	{
		int k = dfn[x] - dfn[nxt[x]] + 1;
		ans = mymin(ans, k);
		return ;
	}
}

int main()
{
	n = read();
	for (int i = 1; i <= n; i++) father[i] = i;
	for (int i = 1; i <= n; i++)
	{
		y = read();
		nxt[i] = y;
		if (getfather(i) != getfather(y)) father[getfather(i)] = getfather(y);
		else
		{
			memset(vis, 0, sizeof(vis));
			dfs(i, 1);
		}
	}
	printf("%d\n", ans);
	return 0;
}
