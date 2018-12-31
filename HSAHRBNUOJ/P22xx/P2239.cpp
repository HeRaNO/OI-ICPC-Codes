#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 5010
#define MAXM 200000
using namespace std;

struct link
{
	int to, val, flow, nxt;
};

link e[MAXM << 1];
int head[MAXN], cnt = 1;
int n, S, T, P, ans;
int dis[MAXN], a[MAXN];
bool vis[MAXN];
queue <int> q;
pair <int, int> p[MAXN];

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

inline void add(int u, int v, int f, int c)
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

inline bool SPFA()
{
	memset(vis, false, sizeof vis);
	memset(dis, -1, sizeof dis);
	q.push(T);
	dis[T] = 0;
	vis[T] = true;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = head[u]; i; i = e[i].nxt)
			if (e[i ^ 1].flow && dis[e[i].to] < dis[u] + e[i ^ 1].val)
			{
				dis[e[i].to] = dis[u] + e[i ^ 1].val;
				if (!vis[e[i].to])
				{
					vis[e[i].to] = true;
					q.push(e[i].to);
				}
			}
	}
	return dis[S] != -1;
}

inline int Dinic(int x, int flow)
{
	int left = flow;
	vis[x] = true;
	if (x == T) return flow;
	for (int i = head[x]; i && left; i = e[i].nxt)
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

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return ;
}

int main()
{
	read(n);
	T = (n << 1) + 2;
	P = T - 1;
	add(S, P, 2, 0);
	for (int i = 1; i <= n; i++) read(p[i].first), read(p[i].second);
	sort(p + 1, p + n + 1);
	for (int i = 1; i <= n; i++)
	{
		a[i] = p[i].second;
		int mx = -1;
		add(P, i, 1, 0);
		add(i + n, T, 1, 0);
		add(i, i + n, 1, 1);
		add(i, i + n, 1, 0);
		for (int j = i - 1; j; j--)
			if (a[j] <= a[i] && a[j] > mx)
				mx = a[j], add(j + n, i, 2, 0);
	}
	printf("%d\n", ZKW_Cost_Flow());
	return 0;
}