#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 5000
#define MAXM 20000
#define INT_MAX ~(1<<31)
using namespace std;

struct link
{
	int to, val, flow, nxt;
};

link e[MAXM << 1];
int head[MAXN], cnt = 1;
int k, m, n, a, b, c, S, T, ans;
int matrix[110][25];
bool vis[MAXN];
int dis[MAXN], f[MAXN], from[MAXN];
queue <int> q;

inline int get(int a, int b)
{
	return (a - 1) * m + b;
}

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
	memset(dis, -1, sizeof dis);
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
			if (dis[e[i].to] < dis[u] + e[i].val && e[i].flow)
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
	ans += dis[T];
	for (int i = from[T]; i; i = from[e[i ^ 1].to])
		e[i].flow -= f[T], e[i ^ 1].flow += f[T];
	return true;
}

inline void read(int &x)
{
	x = 0;
	int f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	x *= f;
	return ;
}

int main()
{
	read(k);
	read(m);
	read(n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			read(matrix[i][j]);
	for (int i = 1; i < n; i++)
		for (int j = 1; j < m; j++)
		{
			a = get(i, j);
			b = get(i, j + 1);
			c = get(i + 1, j);
			add(a << 1, a << 1 | 1, 1, matrix[i][j]);
			add(a << 1, a << 1 | 1, INT_MAX, 0);
			add(a << 1 | 1, b << 1, INT_MAX, 0);
			add(a << 1 | 1, c << 1, INT_MAX, 0);
		}
	for (int i = 1; i < m; i++)
	{
		a = get(n, i);
		b = get(n, i + 1);
		add(a << 1, a << 1 | 1, 1, matrix[n][i]);
		add(a << 1, a << 1 | 1, INT_MAX, 0);
		add(a << 1 | 1, b << 1, INT_MAX, 0);
	}
	for (int i = 1; i < n; i++)
	{
		a = get(i, m);
		c = get(i + 1, m);
		add(a << 1, a << 1 | 1, 1, matrix[i][m]);
		add(a << 1, a << 1 | 1, INT_MAX, 0);
		add(a << 1 | 1, c << 1, INT_MAX, 0);
	}
	a = get(n, m);
	add(a << 1, a << 1 | 1, 1, matrix[n][m]);
	add(a << 1, a << 1 | 1, INT_MAX, 0);
	S = 0;
	T = n * m * 2 + 7;
	add(S, get(1, 1) << 1, k, 0);
	add(get(n, m) << 1 | 1, T, k, 0);
	while (Edmonds_Karp());
	printf("%d\n", ans);
	return 0;
}