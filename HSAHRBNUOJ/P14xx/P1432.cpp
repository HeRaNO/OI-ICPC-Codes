#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 210
#define MAXM 20000
#define E e,heade
#define G g,headg
using namespace std;

struct link
{
	int to, val, flow, nxt;
};

link e[MAXM << 1], g[MAXM << 1];
int heade[MAXN], cnte = 1, headg[MAXN], cntg = 1;
int n, m, S, T, x, ans;
bool vis[MAXN];
int dis[MAXN], f[MAXN], from[MAXN];
queue <int> q;

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

inline void add(int u, int v, int c, int f)
{
	e[++cnte] = (link)
	{
		v, c, f, heade[u]
	};
	heade[u] = cnte;
	e[++cnte] = (link)
	{
		u, -c, 0, heade[v]
	};
	heade[v] = cnte;
	g[++cntg] = (link)
	{
		v, c, f, headg[u]
	};
	headg[u] = cntg;
	g[++cntg] = (link)
	{
		u, -c, 0, headg[v]
	};
	headg[v] = cntg;
	return ;
}

inline bool Edmonds_Karp_Min(link e[], int head[])
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

inline bool Edmonds_Karp_Max(link e[], int head[])
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
	//freopen("tran.in","r",stdin);freopen("tran.out","w",stdout);
	read(m);
	read(n);
	S = 0;
	T = m + n + 1;
	for (int i = 1; i <= m; i++) read(x), add(S, i, 0, x);
	for (int i = 1; i <= n; i++) read(x), add(i + m, T, 0, x);
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
		{
			read(x);
			add(i, j + m, x, ~(1 << 31));
		}
	while (Edmonds_Karp_Min(E));
	printf("%d\n", ans);
	ans = 0;
	while (Edmonds_Karp_Max(G));
	printf("%d\n", ans);
	return 0;
}