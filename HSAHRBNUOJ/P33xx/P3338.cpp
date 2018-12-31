#include <cstdio>
#include <cstring>
#define MAXN 500010
using namespace std;

struct link
{
	int from;
	int to;
	int val;
	int nxt;
};

struct query
{
	int from;
	int to;
	int num;
	int nxt;
};

link e[MAXN * 2];
query q[MAXN * 2];
int edge_num1[MAXN], cnt1, cnt2;
int edge_num2[MAXN];
int n, T, u, v;
int LCA[MAXN];
int dis[MAXN], father[MAXN];
bool vis[MAXN];

inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return x * f;
}

inline void add(int u, int v)
{
	e[cnt1] = (link)
	{
		u, v, 1, edge_num1[u]
	};
	edge_num1[u] = cnt1++;
	e[cnt1] = (link)
	{
		v, u, 1, edge_num1[v]
	};
	edge_num1[v] = cnt1++;
}

inline void add_query(int u, int v, int c)
{
	q[cnt2] = (query)
	{
		u, v, c, edge_num2[u]
	};
	edge_num2[u] = cnt2++;
	q[cnt2] = (query)
	{
		v, u, c, edge_num2[v]
	};
	edge_num2[v] = cnt2++;
}

int getfather(int x)
{
	return x == father[x] ? x : father[x] = getfather(father[x]);
}

void Tarjan(int u)
{
	vis[u] = true;
	father[u] = u;
	for (int i = edge_num2[u]; ~i; i = q[i].nxt)
		if (vis[q[i].to])
			LCA[q[i].num] = getfather(q[i].to);
	for (int i = edge_num1[u]; ~i; i = e[i].nxt)
		if (!vis[e[i].to])
		{
			dis[e[i].to] = dis[u] + e[i].val;
			Tarjan(e[i].to);
			father[e[i].to] = u;
		}
}

int main()
{
	//freopen("tree.in","r",stdin);freopen("tree.out","w",stdout);
	memset(edge_num1, -1, sizeof edge_num1);
	memset(edge_num2, -1, sizeof edge_num2);
	memset(vis, false, sizeof vis);
	n = read();
	T = read();
	for (int i = 1; i <= n; i++) father[i] = i;
	for (int i = 1; i < n; i++)
	{
		u = read();
		v = read();
		add(u, v);
	}
	for (int i = 0; i < T; i++)
	{
		u = read();
		v = read();
		add_query(u, v, i);
	}
	Tarjan(1);
	for (int i = 0; i < cnt2; i += 2)
		printf("%d\n", dis[q[i].from] + dis[q[i].to] - 2 * dis[LCA[q[i].num]]);
	return 0;
}
