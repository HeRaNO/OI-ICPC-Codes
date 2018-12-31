#include <queue>
#include <cstdio>
#include <cstring>
#include <climits>
#define MAXN 2000
#define MAXM 400000
using namespace std;

struct link
{
	int to;
	int nxt;
};

link e[MAXM], e1[MAXM];
int T, n, m, x, y, CAS, ans;
int edge_num[MAXN], edge_num1[MAXN];
int sta[MAXM], top, edge_cnt, scc_cnt, edge_cnt1;
int dfn[MAXN], low[MAXN], belong[MAXN], val[MAXN];
bool vis[MAXN];
char g[MAXN][MAXN];
int dis[MAXN], v[MAXN];
queue <int> q;

inline void pre_work()
{
	memset(edge_num, -1, sizeof(edge_num));
	memset(edge_num1, -1, sizeof(edge_num1));
	ans = INT_MIN;
	top = 0;
	edge_cnt = 0;
	scc_cnt = 0;
	edge_cnt1 = 0;
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(belong, 0, sizeof(belong));
	memset(vis, false, sizeof(vis));
	memset(val, 0, sizeof(val));
	memset(v, 0, sizeof(v));
	return ;
}

void add(int u, int v)
{
	e[edge_cnt] = (link)
	{
		v, edge_num[u]
	};
	edge_num[u] = edge_cnt++;
}

void add1(int u, int v)
{
	e1[edge_cnt1] = (link)
	{
		v, edge_num1[u]
	};
	edge_num1[u] = edge_cnt1++;
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
		scc_cnt++;
		do
		{
			t = sta[top--];
			vis[t] = true;
			belong[t] = scc_cnt;
			//v[x]+=val[t];
		}
		while (t != x);
	}
}

void spfa(int S)
{
	memset(dis, -1, sizeof(dis));
	memset(vis, false, sizeof(vis));
	vis[S] = true;
	dis[S] = val[S];
	q.push(S);
	while (!q.empty())
	{
		int u = q.front();
		vis[u] = false;
		q.pop();
		for (int i = edge_num1[u]; ~i; i = e1[i].nxt)
		{
			if (dis[e1[i].to] < dis[u] + val[e1[i].to])
			{
				dis[e1[i].to] = dis[u] + val[e1[i].to];
				if (!vis[e1[i].to])
				{
					vis[e1[i].to] = true;
					q.push(e1[i].to);
				}
			}
		}
	}
}

int main()
{
	//freopen("flow.in","r",stdin);
	scanf("%d", &CAS);
	while (CAS--)
	{
		pre_work();
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) scanf("%s", g[i]);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				if (g[i][j] == '#') continue;
				else if (g[i][j] == '*')
				{
					scanf("%d %d", &x, &y);
					if (g[x][y] != '#') add(i * m + j, x * m + y);
					if (g[i][j + 1] != '#' && j < m - 1) add(i * m + j, i * m + j + 1);
					if (g[i + 1][j] != '#' && i < n - 1) add(i * m + j, (i + 1)*m + j);
				}
				else
				{
					if (g[i][j + 1] != '#' && j < m - 1) add(i * m + j, i * m + j + 1);
					if (g[i + 1][j] != '#' && i < n - 1) add(i * m + j, (i + 1)*m + j);
				}
			}
		for (int i = 0; i < n * m; i++) if (!vis[i]) Tarjan(i);
		for (int i = 0; i < n * m; i++)
			if (g[i / m][i % m] >= '0' && g[i / m][i % m] <= '9')
				val[belong[i]] += g[i / m][i % m] - '0';
		for (int i = 0; i < n * m; i++)
			for (int j = edge_num[i]; ~j; j = e[j].nxt)
				if (belong[i] != belong[e[j].to]) add1(belong[i], belong[e[j].to]);
		spfa(belong[0]);
		for (int i = 1; i <= scc_cnt; i++) ans = mymax(ans, dis[i]);
		printf("%d\n", ans);
		//for (int i=0;i<=44;i++) printf("%d\n",v[i]);
	}
	return 0;
}
