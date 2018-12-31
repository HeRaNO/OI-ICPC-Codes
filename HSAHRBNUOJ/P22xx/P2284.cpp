#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 110
#define MAXM 10010
#define MAXW 1010
#define INF 2110000000
using namespace std;

struct link
{
	int to;
	int len;
	int cost;
	int nxt;
};

link e[MAXM];
int edge_num[MAXN];
int W, n, k, cnt;
int u, v, len, w;
int ans = INF;
int vis[MAXN], dis[MAXN][MAXW];
queue <int> q;

int mymin(int a, int b)
{
	return a < b ? a : b;
}

void add(int u, int v, int len, int w)
{
	e[cnt] = (link)
	{
		v, len, w, edge_num[u]
	};
	edge_num[u] = cnt++;
}

void spfa()
{
	memset(vis, false, sizeof(vis));
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= W; j++)
			dis[i][j] = INF;
	dis[1][0] = 0;
	vis[1] = true;
	q.push(1);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = edge_num[u]; ~i; i = e[i].nxt)
			for (int j = 0; j <= W - e[i].cost; j++)
			{
				if (dis[u][j] + e[i].len < dis[e[i].to][e[i].cost + j])
				{
					dis[e[i].to][e[i].cost + j] = dis[u][j] + e[i].len;
					if (!vis[e[i].to])
					{
						vis[e[i].to] = true;
						q.push(e[i].to);
					}
				}
			}
	}
}

int main()
{
	memset(edge_num, -1, sizeof(edge_num));
	scanf("%d", &W);
	scanf("%d", &n);
	scanf("%d", &k);
	for (int i = 1; i <= k; i++)
	{
		scanf("%d %d %d %d", &u, &v, &len, &w);
		add(u, v, len, w);
	}
	spfa();
	for (int i = 0; i <= W; i++)
		ans = mymin(ans, dis[n][i]);
	if (ans == INF) printf("NO\n");
	else printf("%d\n", ans);
	return 0;
}
