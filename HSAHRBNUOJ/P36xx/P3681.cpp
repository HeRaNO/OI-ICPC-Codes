#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 610
#define MAXM 200010
#define Point(x,y) (x-1)*m+y
using namespace std;

struct link
{
	int to, flow, nxt;
};

link e[MAXM << 1], f[MAXM << 1];
int head[MAXN], cnt = 1;
int h[MAXN], cntx;
int n, m, S, T, x, y, z, ans;
int dpt[MAXN], in[MAXN], val[MAXN];
int sta[MAXN], top;
bool vis[MAXN];
queue <int> q;

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

inline void add_topological(int u, int v)
{
	in[v]++;
	f[cntx] = (link)
	{
		v, 0, h[u]
	};
	h[u] = cntx++;
}

inline void add(int u, int v, int f)
{
	e[++cnt] = (link)
	{
		v, f, head[u]
	};
	head[u] = cnt;
	e[++cnt] = (link)
	{
		u, 0, head[v]
	};
	head[v] = cnt;
}

inline void Topological_Sort()
{
	for (int i = 1; i <= n * m; i++) if (!in[i]) sta[++top] = i;
	while (top)
	{
		int u = sta[top--];
		vis[u] = true;
		for (int i = h[u]; ~i; i = f[i].nxt)
			if (--in[f[i].to] == 0) sta[++top] = f[i].to;
	}
	return ;
}

inline void Build_Graph()
{
	S = 0;
	T = n * m + 1;
	for (int i = 1; i <= n * m; i++)
		if (vis[i])
		{
			if (val[i] > 0) add(S, i, val[i]), ans += val[i];
			else add(i, T, -val[i]);
			for (int j = h[i]; ~j; j = f[j].nxt)
				if (vis[f[j].to]) add(f[j].to, i, ~(1 << 31));
		}
	return ;
}

inline bool BFS()
{
	memset(dpt, -1, sizeof dpt);
	dpt[S] = 1;
	q.push(S);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = head[u]; i; i = e[i].nxt)
			if (e[i].flow && !~dpt[e[i].to])
			{
				dpt[e[i].to] = dpt[u] + 1;
				q.push(e[i].to);
			}
	}
	return dpt[T] != -1;
}

inline int Dinic(int x, int flow)
{
	int left = flow;
	if (x == T) return flow;
	for (int i = head[x]; i && left; i = e[i].nxt)
		if (e[i].flow && dpt[e[i].to] == dpt[x] + 1)
		{
			int t = Dinic(e[i].to, mymin(e[i].flow, left));
			e[i].flow -= t;
			e[i ^ 1].flow += t;
			left -= t;
		}
	if (left) dpt[x] = -1;
	return flow - left;
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
	memset(h, -1, sizeof h);
	read(n);
	read(m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			read(val[Point(i, j)]);
			read(z);
			while (z--)
			{
				read(x);
				read(y);
				x++;
				y++;
				add_topological(Point(i, j), Point(x, y));
			}
			if (j != 1) add_topological(Point(i, j), Point(i, j - 1));
		}
	Topological_Sort();
	Build_Graph();
	while (BFS()) ans -= Dinic(S, ~(1 << 31));
	printf("%d\n", ans);
	return 0;
}