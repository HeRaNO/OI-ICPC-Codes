#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 2500
#define MAXM 40000
using namespace std;

struct link
{
	int to, val, flow, nxt;
};

link e[MAXM << 1];
int head[MAXN], cnt = 1;
int k, m, n, S, T, R, x, ans;
bool vis[MAXN];
int dis[MAXN], from[MAXN], f[MAXN], pt[40][40];
queue <int> q;

inline int in(int x, int y)
{
	return pt[x][y];
}
inline int out(int x, int y)
{
	return pt[x][y] + n * m;
}
inline int decode(int x)
{
	return x <= n * m ? x : x - n * m;
}
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
	return ;
}

inline bool Edmonds_Karp()
{
	for (int i = S; i <= T; i++) dis[i] = 1 << 31;
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
	ans += dis[T] * f[T];
	for (int i = from[T]; i; i = from[e[i ^ 1].to])
		e[i].flow -= f[T], e[i ^ 1].flow += f[T];
	return true;
}

inline void GetMethod(int P, int x, int pre)
{
	vis[x] = true;
	if (x == T) return ;
	for (int i = head[x]; i; i = e[i].nxt)
		if (e[i ^ 1].flow && !vis[e[i].to])
		{
			if (pre > 0 && decode(pre) != decode(x))
			{
				if (decode(pre) == decode(x) - 1) printf("%d 1\n", P);
				else printf("%d 0\n", P);
			}
			e[i ^ 1].flow--;
			GetMethod(P, e[i].to, x);
			break;
		}
	return ;
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
	read(k);
	read(m);
	read(n);
	S = 0;
	T = (n * m) << 1;
	T++;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			pt[i][j] = ++R;
	add(S, in(1, 1), 0, k);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			if (pt[i][j + 1]) add(out(i, j), in(i, j + 1), 0, ~(1 << 31));
			if (pt[i + 1][j]) add(out(i, j), in(i + 1, j), 0, ~(1 << 31));
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			read(x);
			if (!x) add(in(i, j), out(i, j), 0, ~(1 << 31));
			else if (x == 2)
			{
				add(in(i, j), out(i, j), 1, 1);
				add(in(i, j), out(i, j), 0, ~(1 << 31));
			}
		}
	add(out(n, m), T, 0, ~(1 << 31));
	while (Edmonds_Karp());
	for (int i = 1; i <= k; i++)
	{
		memset(vis, false, sizeof vis);
		GetMethod(i, S, -1);
	}
	return 0;
}