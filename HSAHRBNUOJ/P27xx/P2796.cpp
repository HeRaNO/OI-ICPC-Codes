#include <queue>
#include <cstdio>
#include <cstring>
#include <climits>
#define MAXN 110
#define MAXM 10010
using namespace std;

struct link
{
	int from;
	int to;
	int val;
	int nxt;
};

link e[MAXM];
int edge_num[MAXN], cnt;
int n, m, T, u, v, w;
bool connected[MAXN], vis[MAXN];
int dis[MAXN];
queue <int> q;

__attribute__((__optimize__("O2"))) inline void read(int &x)
{
	x = 0;
	int f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	x *= f;
	return ;
}

__attribute__((__optimize__("O2"))) inline void add(int u, int v, int w)
{
	e[cnt] = (link)
	{
		u, v, w, edge_num[u]
	};
	edge_num[u] = cnt++;
}

__attribute__((__optimize__("O2"))) void ergodic(int x)
{
	vis[x] = true;
	for (int i = edge_num[x]; ~i; i = e[i].nxt)
		if (!vis[e[i].to])
			ergodic(e[i].to);
	return ;
}

__attribute__((__optimize__("O2"))) inline void get_connected()
{
	memset(connected, true, sizeof connected);
	memset(vis, false, sizeof vis);
	ergodic(1);
	for (int i = 1; i <= n; i++) if (!vis[i]) connected[i] = false;
	for (int i = 1; i <= n; i++)
		if (connected[i])
		{
			memset(vis, false, sizeof vis);
			ergodic(i);
			if (!vis[n]) connected[i] = false;
		}
	return ;
}

__attribute__((__optimize__("O2"))) bool Bellman_Ford(int add)
{
	for (int i = 1; i <= n; i++) dis[i] = INT_MAX;
	dis[1] = 0;
	for (int i = 1; i < n; i++)
		for (int j = 0; j < cnt; j++)
			if (dis[e[j].to] > dis[e[j].from] + e[j].val + add && connected[e[j].from] && connected[e[j].to])
				dis[e[j].to] = dis[e[j].from] + e[j].val + add;
	for (int i = 0; i < cnt; i++)
		if (dis[e[i].to] > dis[e[i].from] + e[i].val + add && connected[e[i].from] && connected[e[i].to])
			return true;
	return false;
}

__attribute__((__optimize__("O2"))) void SPFA(int add)
{
	memset(vis, false, sizeof vis);
	for (int i = 1; i <= n; i++) dis[i] = INT_MAX;
	dis[1] = 0;
	vis[1] = true;
	q.push(1);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = edge_num[u]; ~i; i = e[i].nxt)
			if (dis[e[i].to] > dis[u] + e[i].val + add && connected[e[i].to])
			{
				dis[e[i].to] = dis[u] + e[i].val + add;
				if (!vis[e[i].to])
				{
					q.push(e[i].to);
					vis[e[i].to] = true;
				}
			}
	}
	return ;
}

__attribute__((__optimize__("O2"))) bool check(int limit)
{
	if (Bellman_Ford(limit)) return false;
	SPFA(limit);
	if (dis[n] >= 0 && dis[n] != INT_MAX) return true;
	return false;
}

__attribute__((__optimize__("O2"))) int binary()
{
	int left = -100001, right = 100000, middle, ans = -1;
	while (left + 1 != right)
	{
		middle = (left + right) >> 1;
		if (check(middle)) ans = dis[n], right = middle;
		else left = middle;
	}
	return ans;
}

__attribute__((__optimize__("O2"))) int main()
{
	read(T);
	while (T--)
	{
		memset(edge_num, -1, sizeof edge_num);
		cnt = 0;
		read(n);
		read(m);
		for (int i = 1; i <= m; i++)
		{
			read(u);
			read(v);
			read(w);
			add(u, v, w);
		}
		get_connected();
		printf("%d\n", binary());
	}
	return 0;
}
