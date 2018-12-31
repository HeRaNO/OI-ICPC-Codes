#include <queue>
#include <cstdio>
#include <climits>
#include <cstring>
#define MAXN 15100
#define MAXM 50100
#define MOD 1000000007
using namespace std;

struct link
{
	int from;
	int to;
	int val;
	int nxt;
};

link e[MAXM];
int n, m, cnt;
int u, v, w;
int edge_num[MAXN];
long long ans[MAXM];
int dis[MAXN];
bool vis[MAXM];
queue <int> q;
int front_num[MAXN];
int a[MAXN], b[MAXN];

inline void add(int u, int v, int w)
{
	e[cnt] = (link)
	{
		u, v, w, edge_num[u]
	};
	edge_num[u] = cnt++;
}

void spfa(int src)
{
	memset(vis, false, sizeof(vis));
	memset(dis, 0x7f, sizeof(dis));
	dis[src] = 0;
	vis[src] = true;
	q.push(src);
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
}

void get_front(int node)
{
	vis[node] = true;
	for (int i = edge_num[node]; ~i; i = e[i].nxt)
		if (dis[e[i].to] == dis[node] + e[i].val)
		{
			front_num[e[i].to]++;
			if (!vis[e[i].to]) get_front(e[i].to);
		}
}

void get_a(int node)
{
	for (int i = edge_num[node]; ~i; i = e[i].nxt)
		if (dis[e[i].to] == dis[node] + e[i].val)
		{
			vis[i] = true;
			a[e[i].to] = (a[e[i].to] + a[node]) % MOD;
			if (--front_num[e[i].to] == 0) get_a(e[i].to);
		}
}

void get_b(int node)
{
	b[node] = 1;
	for (int i = edge_num[node]; ~i; i = e[i].nxt)
		if (dis[e[i].to] == dis[node] + e[i].val)
		{
			if (!b[e[i].to]) get_b(e[i].to);
			b[node] = (b[node] + b[e[i].to]) % MOD;
		}
}

int main()
{
	memset(edge_num, -1, sizeof(edge_num));
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &u, &v, &w);
		add(u, v, w);
	}
	for (int i = 1; i <= m; i++)
	{
		spfa(i);
		memset(vis, false, sizeof(vis));
		get_front(i);
		memset(vis, false, sizeof(vis));
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		a[i] = 1;
		get_a(i);
		get_b(i);
		for (int j = 0; j < cnt; j++)
			if (vis[j]) ans[j] = (ans[j] + a[e[j].from] * b[e[j].to]) % MOD;
	}
	for (int i = 0; i < cnt; i++) printf("%lld\n", ans[i]);
	return 0;
}