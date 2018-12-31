#include <queue>
#include <cstdio>
#include <cstring>
#include <climits>
#define MAXN 55
#define MAXM 210
#define MAXK 20001
using namespace std;

struct link
{
	int to;
	int val;
	int nxt;
};

link e[MAXM];
int cas, n, m, cnt;
int u, v, w, len;
int edge_num[MAXN];
long long T;
long long dis[MAXN][MAXK];
bool vis[MAXN][MAXK];
queue <pair<int, int> > q;

int mymin(int a, int b)
{
	return a < b ? a : b;
}

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

void spfa()
{
	memset(dis, 0x7f, sizeof(dis));
	memset(vis, false, sizeof(vis));
	dis[0][0] = 0;
	vis[0][0] = true;
	q.push(make_pair(0, 0));
	while (!q.empty())
	{
		pair<int, int> u = q.front();
		vis[u.first][u.second] = false;
		q.pop();
		for (int i = edge_num[u.first]; ~i; i = e[i].nxt)
		{
			int v = dis[u.first][u.second] + e[i].val;
			int t = v % len;
			if (dis[e[i].to][t] > v)
			{
				dis[e[i].to][t] = v;
				if (!vis[e[i].to][t])
				{
					vis[e[i].to][t] = true;
					q.push(make_pair(e[i].to, t));
				}
			}
		}
	}
}

int main()
{
	scanf("%d", &cas);
	while (cas--)
	{
		memset(edge_num, -1, sizeof(edge_num));
		cnt = 0;
		scanf("%d %d %lld", &n, &m, &T);
		for (int i = 1; i <= m; i++)
		{
			scanf("%d %d %d", &u, &v, &w);
			add(u, v, w);
		}
		if (edge_num[0] == -1) puts("Impossible");
		else
		{
			len = INT_MAX;
			for (int i = edge_num[0]; ~i; i = e[i].nxt)
				len = mymin(e[i].val, len);
			len *= 2;
			spfa();
			if (dis[n - 1][T % len] <= T) puts("Possible");
			else puts("Impossible");
		}
	}
	return 0;
}
