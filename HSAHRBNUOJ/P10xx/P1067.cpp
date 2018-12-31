#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 1100
#define MAXM 100010
using namespace std;

struct link
{
	int to;
	long long val;
	int nxt;
};

link e[MAXM];
int edge_num[MAXN], cnt;
long long dis[MAXN], dis1[MAXN];
bool vis[MAXN];
long long ans, w;
int n, m, x, u, v;
queue <int> q;

long long mymax(long long a, long long b)
{
	return a > b ? a : b;
}

void add(int u, int v, long long w)
{
	e[cnt] = (link)
	{
		v, w, edge_num[u]
	};
	edge_num[u] = cnt++;
}

void spfa(int src, long long dis[])
{
	for (int i = 1; i <= n; i++) dis[i] = 1e12;
	memset(vis, false, sizeof vis);
	q.push(src);
	vis[src] = true;
	dis[src] = 0;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = edge_num[u]; ~i; i = e[i].nxt)
		{
			if (dis[e[i].to] > dis[u] + e[i].val)
			{
				dis[e[i].to] = dis[u] + e[i].val;
				if (!vis[e[i].to])
				{
					vis[e[i].to] = true;
					q.push(e[i].to);
				}
			}
		}
	}
	return ;
}

int main()
{
	//freopen("party.in","r",stdin);freopen("party.out","w",stdout);
	while (~scanf("%d %d %d", &n, &m, &x))
	{
		memset(edge_num, -1, sizeof edge_num);
		cnt = 0;
		ans = 0;
		for (int i = 1; i <= m; i++)
		{
			scanf("%d %d %lld", &u, &v, &w);
			add(u, v, w);
		}
		spfa(x, dis);
		for (int i = 1; i <= n; i++)
		{
			spfa(i, dis1);
			ans = mymax(ans, dis1[x] + dis[i]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
