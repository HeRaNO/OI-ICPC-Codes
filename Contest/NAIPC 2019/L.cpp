#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 200005
#define MAXM 300005
using namespace std;

struct link
{
	int to, flow, nxt;
};

link e[MAXM << 1];
int head[MAXN], cnt = 1;
int dpt[MAXN];
int n, m, u, v, S, T, ans;
bool f = true, in[MAXN], out[MAXN];
queue <int> q;

inline void write(int x)
{
	if (f){ printf("%d", x); f = false; }
	else printf(" %d", x);
	return ;
}

inline void add(int u, int v, int f)
{
	e[++cnt] = (link){ v, f, head[u] }; head[u] = cnt;
	e[++cnt] = (link){ u, 0, head[v] }; head[v] = cnt;
}

inline bool BFS()
{
	memset(dpt, -1, sizeof dpt); dpt[S] = 1; q.push(S);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = head[x]; ~i; i = e[i].nxt)
			if (e[i].flow && !~dpt[e[i].to])
			{
				dpt[e[i].to] = dpt[x] + 1;
				q.push(e[i].to);
			}
	}
	return dpt[T] != -1;
}

inline int Dinic(int x, int flow)
{
	int left = flow;
	if (x == T) return flow;
	for (int i = head[x]; ~i && left; i = e[i].nxt)
		if (e[i].flow && dpt[e[i].to] == dpt[x] + 1)
		{
			int t = Dinic(e[i].to, min(left, e[i].flow));
			e[i].flow -= t;
			e[i ^ 1].flow += t;
			left -= t;
		}
	if (left) dpt[x] = -1;
	return flow - left;
}

inline void BFS2(int S, bool vis[], bool flag)
{
	q.push(S);
	while (!q.empty())
	{
		int x = q.front(); q.pop(); vis[x] = true;
		for (int i = head[x]; ~i; i = e[i].nxt)
			if (!vis[e[i].to] && (e[i].flow > 0) == flag)
				q.push(e[i].to);
	}
	return ;
}

int main()
{
	memset(head, -1, sizeof head);
	scanf("%d %d", &n, &m); S = 0; T = n << 1 | 1;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d", &u, &v);
		add(u, v + n, 1);
	}
	for (int i = 1; i <= n; i++) add(S, i, 1), add(i + n, T, 1);
	while (BFS()) ans += Dinic(S, ~(1 << 31));
	ans = n - ans - 1;
	printf("%d\n", ans);
	if (!ans) return 0;
	BFS2(S, out, true); BFS2(T, in, false);
	for (int i = 1; i <= n; i++)
		if (in[i + n] || out[i]) write(i);
	puts("");
	return 0;
}