#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <climits>
#define MAXN 5500
#define MAXM 105000
using namespace std;

struct edge
{
	int from;
	int to;
	int nxt;
	int flow;
	int cost;
};

edge e[MAXM];
int a[MAXN], p[MAXN], dis[MAXN];
bool vis[MAXN];
int edge_num[MAXM], cnt;
int matrix[110][51];
int k, m, n;
int aa, bb, cc;
int S, T;
queue <int> q;

inline void add(int u, int v, int flow, int val)
{
	e[cnt] = (edge)
	{
		u, v, edge_num[u], flow, val
	};
	edge_num[u] = cnt++;
	e[cnt] = (edge)
	{
		v, u, edge_num[v], 0, -val
	};
	edge_num[v] = cnt++;
}

int get(int a, int b)
{
	return ((a - 1) * m + b);
}

int mymin(int a, int b)
{
	return a < b ? a : b;
}

bool spfa()
{
	a[S] = INT_MAX;
	for (int i = 0; i <= T; i++) dis[i] = -INT_MAX;
	memset(vis, false, sizeof(vis));
	memset(p, -1, sizeof(p));
	q.push(S);
	dis[S] = 0;
	vis[S] = true;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = edge_num[u]; ~i; i = e[i].nxt)
		{
			if (e[i].flow > 0 && dis[e[i].to] < dis[u] + e[i].cost)
			{
				dis[e[i].to] = dis[u] + e[i].cost;
				a[e[i].to] = mymin(a[u], e[i].flow);
				p[e[i].to] = i;
				if (!vis[e[i].to])
				{
					vis[e[i].to] = true;
					q.push(e[i].to);
				}
			}
		}
	}
	if (p[T] == -1) return false;
	int tmp = p[T];
	while (tmp != -1)
	{
		e[tmp].flow -= a[T];
		e[tmp ^ 1].flow += a[T];
		tmp = p[e[tmp].from];
	}
	return true;
}
int Max_Cost_Max_Flow()
{
	int ans = 0;
	while (spfa()) ans += dis[T];
	return ans;
}

int main()
{
	memset(edge_num, -1, sizeof(edge_num));
	scanf("%d %d", &n, &k);
	m = n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &matrix[i][j]);
	for (int i = 1; i < n; i++)
		for (int j = 1; j < m; j++)
		{
			aa = get(i, j);
			bb = get(i, j + 1);
			cc = get(i + 1, j);
			add(aa << 1, aa << 1 | 1, 1, matrix[i][j]);
			add(aa << 1, aa << 1 | 1, INT_MAX, 0);
			add(aa << 1 | 1, bb << 1, INT_MAX, 0);
			add(aa << 1 | 1, cc << 1, INT_MAX, 0);
		}
	for (int i = 1; i < m; i++)
	{
		aa = get(n, i);
		bb = get(n, i + 1);
		add(aa << 1, aa << 1 | 1, 1, matrix[n][i]);
		add(aa << 1, aa << 1 | 1, INT_MAX, 0);
		add(aa << 1 | 1, bb << 1, INT_MAX, 0);
	}
	for (int i = 1; i < n; i++)
	{
		aa = get(i, m);
		cc = get(i + 1, m);
		add(aa << 1, aa << 1 | 1, 1, matrix[i][m]);
		add(aa << 1, aa << 1 | 1, INT_MAX, 0);
		add(aa << 1 | 1, cc << 1, INT_MAX, 0);
	}
	aa = get(n, m);
	add(aa << 1, aa << 1 | 1, 1, matrix[n][m]);
	add(aa << 1, aa << 1 | 1, INT_MAX, 0);
	S = 0;
	T = n * m * 2 + 7;
	add(S, get(1, 1) << 1, k, 0);
	add(get(n, m) << 1 | 1, T, k, 0);
	printf("%d\n", Max_Cost_Max_Flow());
	return 0;
}
