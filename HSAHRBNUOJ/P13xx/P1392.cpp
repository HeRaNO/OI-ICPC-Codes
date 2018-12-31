#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 510
#define MAXM 5210
using namespace std;

struct link
{
	int to;
	int val;
	int nxt;
};

link e[MAXM];
int edge_num[MAXN], cnt;
int n, m, w, T, x, y, z;
bool vis[MAXN];
int dis[MAXN], negcir[MAXN];
queue <int> q;

inline void add(int u, int v, int w)
{
	e[cnt] = (link)
	{
		v, w, edge_num[u]
	};
	edge_num[u] = cnt++;
}

bool SPFA()
{
	memset(vis, false, sizeof vis);
	memset(negcir, 0, sizeof negcir);
	memset(dis, 0x7f, sizeof dis);
	while (!q.empty()) q.pop();
	dis[1] = 0;
	q.push(1);
	vis[1] = true;
	negcir[1]++;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = edge_num[u]; ~i; i = e[i].nxt)
			if (dis[e[i].to] > dis[u] + e[i].val)
			{
				dis[e[i].to] = dis[u] + e[i].val;
				if (!vis[e[i].to])
				{
					vis[e[i].to] = true;
					negcir[e[i].to]++;
					if (negcir[e[i].to] > n) return true;
					q.push(e[i].to);
				}
			}
	}
	if (dis[n] < 0) return true;
	return false;
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		memset(edge_num, -1, sizeof edge_num);
		cnt = 0;
		scanf("%d %d %d", &n, &m, &w);
		for (int i = 1; i <= m; i++)
		{
			scanf("%d %d %d", &x, &y, &z);
			add(x, y, z);
			add(y, x, z);
		}
		for (int i = 1; i <= w; i++)
		{
			scanf("%d %d %d", &x, &y, &z);
			add(x, y, -z);
		}
		if (SPFA()) puts("YES");
		else puts("NO");
	}
	return 0;
}
