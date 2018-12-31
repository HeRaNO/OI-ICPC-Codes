#include <queue>
#include <cstdio>
#include <cstring>
#include <climits>
#define MAXN 1010
#define MAXM 20010
using namespace std;

struct link
{
	int to;
	int val;
	int nxt;
};

link e[MAXM];
int edge_num[MAXN], cnt;
int n, m, u, v, w1, w2;
int negcir[MAXN], dis[MAXN];
bool vis[MAXN];
queue <int> q;

inline void add(int u, int v, int w1, int w2)
{
	e[cnt] = (link)
	{
		v, w1, edge_num[u]
	};
	edge_num[u] = cnt++;
	e[cnt] = (link)
	{
		u, w2, edge_num[v]
	};
	edge_num[v] = cnt++;
}

int SPFA()
{
	memset(vis, false, sizeof vis);
	memset(negcir, 0, sizeof negcir);
	for (int i = 1; i <= n; i++) dis[i] = INT_MAX;
	while (!q.empty()) q.pop();
	dis[1] = 0;
	q.push(1);
	vis[1] = true;
	negcir[1]++;
	while (!q.empty())
	{
		int u = q.front();
		vis[u] = false;
		q.pop();
		for (int i = edge_num[u]; ~i; i = e[i].nxt)
			if (dis[e[i].to] > dis[u] + e[i].val)
			{
				dis[e[i].to] = dis[u] + e[i].val;
				if (!vis[e[i].to])
				{
					vis[e[i].to] = true;
					negcir[e[i].to]++;
					if (negcir[e[i].to] > n) return INT_MAX;
					q.push(e[i].to);
				}
			}
	}
	return dis[n];
}

int main()
{
	while (~scanf("%d %d", &n, &m) && n && m)
	{
		memset(edge_num, -1, sizeof edge_num);
		cnt = 0;
		for (int i = 1; i <= m; i++)
		{
			scanf("%d %d %d %d", &u, &v, &w1, &w2);
			add(u, v, w1, w2);
		}
		int ans = SPFA();
		if (ans < 0 || ans == INT_MAX) puts("No such path");
		else printf("%d\n", ans);
	}
	return 0;
}
