#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 100010
#define MAXM 200010
using namespace std;

struct link
{
	int to;
	int nxt;
};

link e[MAXM], e1[2][MAXM];
int edge_num[MAXN], cnt;
int edge_num1[2][MAXN], cnt1, cnt2;
int dfn[MAXN], low[MAXN], sta[MAXN], belong[MAXN];
int siz[MAXN];
int n, m, u, v, top, ans, T, res;
bool vis[MAXN];
int dis[2][MAXN];
queue <int> q;

inline void add(int u, int v)
{
	e[cnt] = (link)
	{
		v, edge_num[u]
	};
	edge_num[u] = cnt++;
}

inline void add_new_pos(int u, int v)
{
	e1[0][cnt1] = (link)
	{
		v, edge_num1[0][u]
	};
	edge_num1[0][u] = cnt1++;
}

inline void add_new_neg(int u, int v)
{
	e1[1][cnt2] = (link)
	{
		u, edge_num1[1][v]
	};
	edge_num1[1][v] = cnt2++;
}

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}
inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

void Tarjan(int x)
{
	dfn[x] = low[x] = ++T;
	sta[++top] = x;
	for (int i = edge_num[x]; ~i; i = e[i].nxt)
	{
		if (vis[e[i].to]) continue;
		if (dfn[e[i].to]) low[x] = mymin(low[x], dfn[e[i].to]);
		else
		{
			Tarjan(e[i].to);
			low[x] = mymin(low[x], low[e[i].to]);
		}
	}
	if (dfn[x] == low[x])
	{
		int t;
		ans++;
		do
		{
			t = sta[top--];
			vis[t] = true;
			belong[t] = ans;
			siz[ans]++;
		}
		while (t != x);
	}
}

inline void spfa(int opt)
{
	memset(vis, false, sizeof vis);
	q.push(belong[1]);
	vis[belong[1]] = true;
	dis[opt][belong[1]] = siz[belong[1]];
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = edge_num1[opt][u]; ~i; i = e1[opt][i].nxt)
		{
			if (dis[opt][e1[opt][i].to] < dis[opt][u] + siz[e1[opt][i].to])
			{
				dis[opt][e1[opt][i].to] = dis[opt][u] + siz[e1[opt][i].to];
				if (!vis[e1[opt][i].to])
				{
					vis[e1[opt][i].to] = true;
					q.push(e1[opt][i].to);
				}
			}
		}
	}
	return ;
}

int main()
{
	//freopen("wander.in","r",stdin);freopen("wander.out","w",stdout);
	memset(edge_num, -1, sizeof edge_num);
	memset(edge_num1, -1, sizeof edge_num1);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d", &u, &v);
		add(u, v);
	}
	for (int i = 1; i <= n; i++) if (!vis[i]) Tarjan(i);
	for (int i = 1; i <= n; i++)
		for (int j = edge_num[i]; ~j; j = e[j].nxt)
			if (belong[i] != belong[e[j].to])
			{
				add_new_pos(belong[i], belong[e[j].to]);
				add_new_neg(belong[i], belong[e[j].to]);
			}
	spfa(0);
	spfa(1);
	for (int i = 1; i <= ans; i++)
		for (int j = edge_num1[0][i]; ~j; j = e1[0][j].nxt)
			if (dis[1][i] && dis[0][e1[0][j].to])
				res = mymax(res, dis[1][i] + dis[0][e1[0][j].to] - siz[belong[1]]);
	printf("%d\n", res);
	return 0;
}
