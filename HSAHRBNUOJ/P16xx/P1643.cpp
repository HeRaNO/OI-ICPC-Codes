#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 20010
using namespace std;

struct link
{
	int to;
	int val;
	int nxt;
};

link e[MAXN * 2];
int edge_num[MAXN], cnt;
int dis[3][MAXN];
bool vis[MAXN];
queue <int> q;
int ans, pt;
int n, a, b, c, u, v, w;

void add(int u, int v, int w)
{
	e[cnt] = (link)
	{
		v, w, edge_num[u]
	};
	edge_num[u] = cnt++;
	e[cnt] = (link)
	{
		u, w, edge_num[v]
	};
	edge_num[v] = cnt++;
}

inline void spfa(int p, int src)
{
	memset(vis, false, sizeof vis);
	q.push(src);
	dis[p][src] = 0;
	vis[src] = true;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = edge_num[u]; ~i; i = e[i].nxt)
			if (dis[p][e[i].to] > dis[p][u] + e[i].val)
			{
				dis[p][e[i].to] = dis[p][u] + e[i].val;
				if (!vis[e[i].to])
				{
					vis[e[i].to] = true;
					q.push(e[i].to);
				}
			}
	}
	return ;
}

int main()
{
	//freopen("escapeb.in","r",stdin);freopen("escapeb.out","w",stdout);
	memset(edge_num, -1, sizeof edge_num);
	memset(dis, 0x7f, sizeof dis);
	ans = dis[0][0];
	scanf("%d %d %d %d", &n, &a, &b, &c);
	for (int i = 1; i < n; i++)
	{
		scanf("%d %d %d", &u, &v, &w);
		add(u, v, w);
	}
	spfa(0, a);
	spfa(1, b);
	spfa(2, c);
	for (int i = 1; i <= n; i++)
		if (ans > dis[0][i] + dis[1][i] + dis[2][i])
		{
			ans = dis[0][i] + dis[1][i] + dis[2][i];
			pt = i;
		}
	printf("%d\n%d\n", pt, ans);
	return 0;
}
