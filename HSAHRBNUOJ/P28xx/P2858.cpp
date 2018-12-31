#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 605
#define	MAXM 50000
using namespace std;

struct link
{
	int to, val, flow, nxt;
};

link e[MAXM << 1];
int head[MAXN], cnt = 1;
int n, m, S, T, ans, a[65][10];
bool vis[MAXN];
int dis[MAXN], f[MAXN], from[MAXN];
queue <int> q;

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
		for (int i = head[u]; i; i = e[i].nxt)
			if (dis[e[i].to] > dis[u] + e[i].val && e[i].flow)
			{
				dis[e[i].to] = dis[u] + e[i].val;
				from[e[i].to] = i;
				f[e[i].to] = mymin(f[u], e[i].flow);
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
	read(m);
	read(n);
	S = 0;
	T = n * (m + 1) + 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			read(a[i][j]);
	for (int i = 1; i <= n; i++) add(S, i, 1, 0);
	for (int i = n + 1; i < T; i++) add(i, T, 1, 0);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (int k = 1; k <= n; k++)
				add(i, j * n + k, 1, a[i][j]*k);
	while (Edmonds_Karp());
	printf("%.2lf\n", (double)ans / (double)n);
	return 0;
}