#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 10010
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
int n, m, u, v, w, opt;
bool vis[MAXN];
int dis[MAXN];

inline void add(int u, int v, int w)
{
	e[cnt] = (link)
	{
		v, w, edge_num[u]
	};
	edge_num[u] = cnt++;
	return ;
}

inline bool SPFA(int x)
{
	vis[x] = true;
	for (int i = edge_num[x]; ~i; i = e[i].nxt)
		if (dis[e[i].to] > dis[x] + e[i].val)
		{
			if (vis[e[i].to]) return true;
			dis[e[i].to] = dis[x] + e[i].val;
			if (SPFA(e[i].to)) return true;
		}
	vis[x] = false;
	return false;
}

int main()
{
	memset(edge_num, -1, sizeof edge_num);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &opt);
		if (opt == 1)
		{
			scanf("%d %d %d", &u, &v, &w);
			add(u, v, -w);
		}
		else if (opt == 2)
		{
			scanf("%d %d %d", &u, &v, &w);
			add(v, u, w);
		}
		else
		{
			scanf("%d %d", &u, &v);
			add(u, v, 0);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		dis[i] = 0;
		if (SPFA(i))
		{
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}
