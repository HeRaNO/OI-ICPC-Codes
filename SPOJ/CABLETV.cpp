#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 110
#define INT_MAX 2147483000
using namespace std;

int map[MAXN][MAXN], flow[MAXN][MAXN];
int parent[MAXN];
int a, b;
int n, m;
bool first = true;

int mymin(int a, int b)
{
	return a < b ? a : b;
}

int bfs(int n, int start, int end)
{
	int a[MAXN], i, v;
	queue <int> q;
	memset(a, 0, sizeof(a));
	memset(parent, -1, sizeof(parent));
	q.push(start);
	a[start] = INT_MAX;
	while (!q.empty())
	{
		v = q.front();
		q.pop();
		for (i = 0; i < n; i++)
		{
			if (!a[i] && map[v][i] > flow[v][i])
			{
				q.push(i);
				parent[i] = v;
				a[i] = mymin(a[v], map[v][i] - flow[v][i]);
			}
		}
		if (v == end) break;
	}
	return a[end];
}

int EdmondsKarp(int n, int sp, int fp)
{
	int tmp;
	int maxflow = 0;
	memset(flow, 0, sizeof(flow));
	while (tmp = bfs(n, sp, fp))
	{
		for (int i = fp; i != sp; i = parent[i])
		{
			flow[i][parent[i]] -= tmp;
			flow[parent[i]][i] += tmp;
		}
		maxflow += tmp;
	}
	return maxflow;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &n, &m);
		memset(map, 0, sizeof(map));
		for (int i = 0; i < n; i++) map[i][i + n] = 1;
		for (int i = 0; i < m; i++)
		{
			scanf(" (%d,%d)", &a, &b);
			map[a + n][b] = map[b + n][a] = INT_MAX;
		}
		int ans = INT_MAX;
		for (int i = 1; i < n; i++)
			ans = mymin(ans, EdmondsKarp(n * 2, n, i));
		if (ans == INT_MAX) printf("%d\n", n);
		else printf("%d\n", ans);
	}
	return 0;
}
