#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 300
#define MAXM 20000
using namespace std;

struct link
{
	int to, val, flow, nxt;
};

link e[MAXM << 1];
int head[MAXN], cnt = 1;
int P, Q, a, b, S, T, k, x, y, ans;
int dis[MAXN], from[MAXN], f[MAXN];
bool vis[MAXN];
queue <int> q;

inline int GetPos(int x, int y)
{
	return x * (Q + 1) + y + 1;
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
}

inline bool Edmonds_Karp()
{
	for (int i = S; i <= T; dis[i] = 1 << 31, i++);
	memset(vis, false, sizeof vis);
	q.push(S);
	vis[S] = true;
	dis[S] = 0;
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
				f[e[i].to] = mymin(e[i].flow, f[u]);
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
	//freopen("shinkai.in","r",stdin);freopen("shinkai.out","w",stdout);
	read(a);
	read(b);
	read(P);
	read(Q);
	S = 0;
	T = (P + 1) * (Q + 1) + 1;
	for (int i = 1; i <= P + 1; i++)
		for (int j = 1; j <= Q; j++)
		{
			read(x);
			add(GetPos(i - 1, j - 1), GetPos(i - 1, j), x, 1);
			add(GetPos(i - 1, j - 1), GetPos(i - 1, j), 0, ~(1 << 31));
		}
	for (int i = 1; i <= Q + 1; i++)
		for (int j = 1; j <= P; j++)
		{
			read(x);
			add(GetPos(j - 1, i - 1), GetPos(j, i - 1), x, 1);
			add(GetPos(j - 1, i - 1), GetPos(j, i - 1), 0, ~(1 << 31));
		}
	for (int i = 1; i <= a; i++)
	{
		read(k);
		read(x);
		read(y);
		add(S, GetPos(x, y), 0, k);
	}
	for (int i = 1; i <= b; i++)
	{
		read(k);
		read(x);
		read(y);
		add(GetPos(x, y), T, 0, k);
	}
	while (Edmonds_Karp());
	printf("%d\n", ans);
	return 0;
}