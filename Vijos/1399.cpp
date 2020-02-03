#include <cstdio>
#include <climits>
#include <cstring>
using namespace std;
const int maxn = 201;

int mymin(int a, int b)
{
	return a < b ? a : b;
}

int n, m, t, v;
int time[maxn][maxn], value[maxn][maxn];
bool road[maxn][maxn];
bool vis[maxn][maxn];
int a, b, c, d;
int i;
int mintime = INT_MAX, minleftvalue = INT_MAX;

void dfs(int q, int ts, int vs)
{
	if (q == n)
	{
		if (vs < minleftvalue && vs >= 0 && ts <= t)
		{
			minleftvalue = vs;
			mintime = ts;
			return ;
		}
		else if (minleftvalue == vs && ts < mintime)
		{
			mintime = ts;
			return ;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (!vis[q][i] && road[q][i])
		{
			vis[q][i] = true;
			vis[i][q] = true;
			dfs(i, ts + time[q][i], vs - value[q][i]);
			vis[q][i] = false;
			vis[i][q] = false;
		}
	}
}

int main()
{
	memset(road, false, sizeof(road));
	memset(vis, false, sizeof(vis));
	scanf("%d %d %d %d", &n, &m, &t, &v);
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d %d %d", &a, &b, &c, &d);
		time[a][b] = c;
		value[a][b] = d;
		road[a][b] = true;
		time[b][a] = c;
		value[b][a] = d;
		road[b][a] = true;
	}
	dfs(1, 0, v);
	printf("%d %d", mintime, minleftvalue);
	return 0;
}
