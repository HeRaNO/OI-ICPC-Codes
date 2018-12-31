#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 100
#define MAXM 20000
using namespace std;

struct link
{
	int to, val, flow, nxt;
};

link e[MAXM << 1];
int head[MAXN], cnt = 1;
int dis[MAXN], from[MAXN], f[MAXN];
bool vis[MAXN];
queue <int> q;

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

inline void add(int u, int v, int c, int f)
{
	e[++cnt] = (link)
	{
		v, c, f, head[u]
	};
	head[u] = cnt;
	e[++cnt] = (link)
	{
		u, -c, 0, head[v]
	};
	head[v] = cnt;
}

inline bool Edmonds_Karp()
{
	memset(dis, 0x7f, sizeof dis);
	memset(vis, false, sizeof vis);
	q.push(S);
	dis[S] = 0;
	vis[S] = true;
	f[S] = ~(1 << 31);
	f[T] = 0;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = head[u]; ~i; i = e[i].nxt)
			if (e[i].flow && dis[e[i].to] > dis[u] + e[i].val)
			{
				dis[e[i].to] = dis[u] + e[i].val;
				f[e[i].to] = mymin(f[u], e[i].flow);
				from[e[i].to] = i;
				if (!vis[e[i].to])
				{
					vis[e[i].to] = true;
					q.push(e[i].to);
				}
			}
	}
	if (!f[T]) return false;
	ans += dis[T] * f[T];
	for (int i = from[T]; i; i = from[e[i ^ 1].to])
		e[i].flow -= f[T], e[i ^ 1].flow += f[T];
	return true;
}

inline bool SPFA()
{
	memset(dis, 0x7f, sizeof dis);
	memset(vis, false, sizeof vis);
	q.push(T);
	dis[T] = 0;
	vis[T] = true;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = head[u]; ~i; i = e[i].nxt)
			if (e[i].flow && dis[e[i].to] > dis[u] + e[i].val)
			{
				dis[e[i].to] = dis[u] + e[i].val;
				if (!vis[e[i].to])
				{
					vis[e[i].to] = true;
					q.push(e[i].to);
				}
			}
	}
	return dis[S] != 0x7f7f7f7f;
}

inline int Dinic(int x, int flow)
{
	int left = flow;
	vis[x] = true;
	if (x == T) return flow;
	for (int i = head[x]; ~i && left; i = e[i].nxt)
		if (dis[e[i].to] == dis[x] - e[i].val && e[i].flow && !vis[e[i].to])
		{
			int t = Dinic(e[i].to, mymin(e[i].flow, left));
			ans += t * e[i].val;
			e[i].flow -= t;
			e[i ^ 1].flow += t;
			left -= t;
		}
	return flow - left;
}

inline int ZKW_Cost_Flow()
{
	while (SPFA())
	{
		vis[T] = true;
		while (vis[T])
		{
			memset(vis, false, sizeof vis);
			Dinic(S, ~(1 << 31));
		}
	}
	return ans;
}

int main()
{
	memset(head, -1, sizeof head);
	//Make_Graph
	while (Edmonds_Karp());
	printf("%d\n", ans);
	printf("%d\n", ZKW_Cost_Flow());
	return 0;
}
