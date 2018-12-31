#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 1010
using namespace std;

int g[MAXN][MAXN];
int n, p, k, u, v, w, maxx;
bool vis[MAXN];
int dis[MAXN];
queue <int> q;

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}
inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

bool SPFA(int limit)
{
	memset(vis, false, sizeof vis);
	memset(dis, 0x7f, sizeof dis);
	dis[1] = 0;
	q.push(1);
	vis[1] = true;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = 1; i <= n; i++)
		{
			int d = (g[u][i] > limit);
			if (g[u][i] != 0x7f7f7f7f && dis[i] > dis[u] + d)
			{
				dis[i] = dis[u] + d;
				if (!vis[i])
				{
					vis[i] = true;
					q.push(i);
				}
			}
		}
	}
	return dis[n] <= k;
}

int binary(int left, int right)
{
	int middle, res;
	bool flag = false;
	while (left + 1 != right)
	{
		middle = (left + right) >> 1;
		if (SPFA(middle))
		{
			flag = true;
			res = middle;
			right = middle;
		}
		else left = middle;
	}
	if (!flag) return -1;
	return res;
}

int main()
{
	memset(g, 0x7f, sizeof g);
	scanf("%d %d %d", &n, &p, &k);
	for (int i = 1; i <= n; i++) g[i][i] = 0;
	for (int i = 1; i <= p; i++)
	{
		scanf("%d %d %d", &u, &v, &w);
		g[u][v] = g[v][u] = mymin(g[u][v], w);
		maxx = mymax(maxx, w);
	}
	printf("%d\n", binary(-1, maxx));
	return 0;
}
