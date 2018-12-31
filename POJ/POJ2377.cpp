#include <cstdio>
#include <climits>
#include <algorithm>
#define MAXN 1010
#define MAXM 20010
using namespace std;

bool vis[MAXN] = {false};
bool used[MAXN] = {false};
int cost[MAXN][MAXN];
bool road[MAXN][MAXN] = {false};
int maxcost[MAXN], far[MAXN];
int n, m, ans;
int u, v, w;
int i;
bool shut = false;

int mymax(int a, int b)
{
	return a > b ? a : b;
}

void dfs(int dep)
{
	vis[dep] = true;
	if (dep == n)
		return ;
	for (int i = 1; i <= n; i++)
	{
		if (road[dep][i] && !vis[i])
			dfs(i);
	}
}

void prim(int v)
{
	for (int i = 1; i <= n; i++)
	{
		maxcost[i] = cost[v][i];
		far[i] = v;
	}
	int mymin, now;
	for (int i = 1; i < n; i++)
	{
		mymin = INT_MIN;
		for (int j = 1; j <= n; j++)
			if (maxcost[j] > mymin)
				if (!used[j])
				{
					mymin = maxcost[j];
					now = j;
				}
		used[now] = 1;
		for (int j = 1; j <= n; j++)
			if (!used[j])
				if (cost[j][now] > maxcost[j])
				{
					maxcost[j] = cost[j][now];
					far[j] = now;
				}
	}
	return ;
}

int main()
{
	//freopen("cowtract.in","r",stdin);freopen("cowtract.out","w",stdout);
	scanf("%d %d", &n, &m);
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &u, &v, &w);
		road[u][v] = road[v][u] = true;
		cost[u][v] = cost[v][u] = mymax(w, cost[u][v]);
	}
	dfs(1);
	for (i = 1; i <= n; i++)
		if (!vis[i])
		{
			shut = true;
			break;
		}
	if (shut)
	{
		printf("-1");
		return 0;
	}
	prim(1);
	for (i = 2; i <= n; i++)
		ans += cost[i][far[i]];
	printf("%d\n", ans);
	return 0;
}
