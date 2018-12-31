#include <queue>
#include <cstdio>
#include <climits>
#include <cstring>
#define MAXN 410
#define MAXM 20010
using namespace std;

struct link
{
	int to;
	int flow;
	int nxt;
};

link e[MAXM];
int edge_num[MAXN], cnt = 1;
int dpt[MAXN];
int n, f, d, fc, dc;
int S, T, x, ans;
queue <int> q;

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

inline void add(int u, int v, int flow)
{
	cnt++;
	e[cnt] = (link)
	{
		v, flow, edge_num[u]
	};
	edge_num[u] = cnt;
	cnt++;
	e[cnt] = (link)
	{
		u, 0, edge_num[v]
	};
	edge_num[v] = cnt;
}

inline bool BFS()
{
	memset(dpt, -1, sizeof dpt);
	dpt[S] = 0;
	q.push(S);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = edge_num[x]; ~i; i = e[i].nxt)
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
	for (int i = edge_num[x]; ~i && left; i = e[i].nxt)
		if (e[i].flow && dpt[e[i].to] == dpt[x] + 1)
		{
			int t = Dinic(e[i].to, mymin(left, e[i].flow));
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
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	x *= f;
	return ;
}

int main()
{
	memset(edge_num, -1, sizeof edge_num);
	read(n);
	read(f);
	read(d);
	S = 0;
	T = n + n + f + d + 1;
	for (int i = 1; i <= f; i++) add(S, i, 1);
	for (int i = f + 1; i <= f + d; i++) add(i, T, 1);
	for (int i = 1; i <= n; i++)
	{
		read(fc);
		read(dc);
		for (int j = 1; j <= fc; j++)
		{
			read(x);
			add(x, d + f + i, 1);
		}
		for (int j = 1; j <= dc; j++)
		{
			read(x);
			add(d + f + n + i, x + f, 1);
		}
		add(d + f + i, d + f + n + i, 1);
	}
	while (BFS()) ans += Dinic(S, INT_MAX);
	printf("%d\n", ans);
	return 0;
}
