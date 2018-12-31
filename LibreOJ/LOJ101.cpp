#include <cstdio>
#include <vector>
#define MAXN 1000010
#define MAXM 8000010
using namespace std;

struct link
{
	int to, flow, re;
} d;

vector <link> G[MAXM];
int n, m, S, T, u, v, f, dpt[MAXN], q[MAXN], tim[MAXN], hd, tl, ans, RE;

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

inline void add(int u, int v, int f)
{
	d.to = v;
	d.flow = f;
	d.re = G[v].size();
	G[u].push_back(d);
	d.to = u;
	d.flow = 0;
	d.re = G[u].size() - 1;
	G[v].push_back(d);
}

inline bool BFS()
{
	tim[S] = ++RE;
	q[hd = 0] = S;
	dpt[S] = 1;
	tl = 0;
	while (hd <= tl)
	{
		u = q[hd++];
		for (int i = 0; i < G[u].size(); i++)
			if (tim[G[u][i].to] != RE && G[u][i].flow)
			{
				tim[G[u][i].to] = RE;
				dpt[G[u][i].to] = dpt[u] + 1;
				q[++tl] = G[u][i].to;
			}
	}
	return tim[T] == RE;
}

inline int Dinic(int x, int flow)
{
	if (x == T || !flow) return flow;
	int mxflw = 0, flw;
	for (int i = 0; i < G[x].size() && mxflw < flow; i++)
		if (dpt[G[x][i].to] == dpt[x] + 1 && G[x][i].flow && tim[G[x][i].to] == RE)
			if (flw = Dinic(G[x][i].to, mymin(flow - mxflw, G[x][i].flow)))
			{
				mxflw += flw;
				G[x][i].flow -= flw;
				G[G[x][i].to][G[x][i].re].flow += flw;
			}
	if (!mxflw) dpt[x] = -1;
	return mxflw;
}

inline int read()
{
	int x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return x;
}

int main()
{
	n = read();
	m = read();
	S = read();
	T = read();
	for (int i = 1; i <= m; i++)
	{
		u = read();
		v = read();
		f = read();
		add(u, v, f);
	}
	while (BFS()) ans += Dinic(S, ~(1 << 31));
	printf("%d\n", ans);
	return 0;
}