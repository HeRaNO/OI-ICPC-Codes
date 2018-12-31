#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 800
#define MAXM 20000
#define in(x) x<<1
#define out(x) x<<1|1
#define E e,heade,cnte
#define G g,headg,cntg
#define H h,headh,cnth
#define INF ~(1<<31)
using namespace std;

struct link
{
	int to, val, flow, nxt;
};

link e[MAXM << 1], g[MAXM << 1], h[MAXM << 1];
int heade[MAXN], headg[MAXN], headh[MAXN];
int cnte = 1, cntg = 1, cnth = 1;
int n, m, S, T, ans;
int a[25][25], pt[25][25], cnt;
bool vis[MAXN];
int dis[MAXN], f[MAXN], from[MAXN];
queue <int> q;

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

inline void add(link e[], int head[], int &cnt, int u, int v, int c, int f)
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

inline bool Edmonds_Karp(link e[], int head[], int &cnt)
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
	ans += dis[T] * f[T];
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
	//freopen("digit.in","r",stdin);freopen("digit.out","w",stdout);
	read(m);
	read(n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < m + i; j++)
			read(a[i][j]), pt[i][j] = ++cnt;
	S = 0;
	T = (cnt << 1) + 1;
	for (int i = 1; i <= m; i++)
	{
		add(E, S, in(pt[1][i]), 0, 1);
		add(G, S, in(pt[1][i]), 0, 1);
		add(H, S, in(pt[1][i]), 0, 1);
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < m + i; j++)
		{
			add(E, in(pt[i][j]), out(pt[i][j]), a[i][j], 1);
			add(G, in(pt[i][j]), out(pt[i][j]), a[i][j], INF);
			add(H, in(pt[i][j]), out(pt[i][j]), a[i][j], INF);
			if (i == n) continue;
			add(E, out(pt[i][j]), in(pt[i + 1][j]), 0, 1);
			add(E, out(pt[i][j]), in(pt[i + 1][j + 1]), 0, 1);
			add(G, out(pt[i][j]), in(pt[i + 1][j]), 0, 1);
			add(G, out(pt[i][j]), in(pt[i + 1][j + 1]), 0, 1);
			add(H, out(pt[i][j]), in(pt[i + 1][j]), 0, INF);
			add(H, out(pt[i][j]), in(pt[i + 1][j + 1]), 0, INF);
		}
	for (int i = 1; i < m + n; i++)
	{
		add(E, out(pt[n][i]), T, 0, 1);
		add(G, out(pt[n][i]), T, 0, INF);
		add(H, out(pt[n][i]), T, 0, INF);
	}
	while (Edmonds_Karp(E));
	printf("%d\n", ans);
	ans = 0;
	while (Edmonds_Karp(G));
	printf("%d\n", ans);
	ans = 0;
	while (Edmonds_Karp(H));
	printf("%d\n", ans);
	return 0;
}