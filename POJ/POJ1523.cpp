#include <cstdio>
#include <cstring>
#define MAXN 1100
#define MAXM 2100
using namespace std;

struct link
{
	int to;
	int nxt;
};

link e[MAXM];
int edge_num[MAXN], cnt;
int cas, n, root_num, root = 1, dfs_clock;
int u, v;
char c;
bool out;
int pre[MAXN], low[MAXN];
bool iscut[MAXN];
bool vis[MAXN];

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int mymin(int a, int b)
{
	return a < b ? a : b;
}

void add(int u, int v)
{
	e[cnt] = (link)
	{
		v, edge_num[u]
	};
	edge_num[u] = cnt++;
	e[cnt] = (link)
	{
		u, edge_num[v]
	};
	edge_num[v] = cnt++;
}

int findcut(int node)
{
	low[node] = pre[node] = ++dfs_clock;
	for (int i = edge_num[node]; ~i; i = e[i].nxt)
	{
		int v = e[i].to;
		if (!pre[v])
		{
			findcut(v);
			if (node == root) root_num++;
			else
			{
				if (low[v] < low[node]) low[node] = low[v];
				if (low[v] >= pre[node]) iscut[node] = true;
			}
		}
		else if (low[node] > pre[v]) low[node] = pre[v];
	}
}

void dfs(int node)
{
	vis[node] = true;
	for (int i = edge_num[node]; ~i; i = e[i].nxt)
	{
		int v = e[i].to;
		if (!vis[v])
			dfs(v);
	}
}

int main()
{
	while (~scanf("%d", &u) && u)
	{
		memset(edge_num, -1, sizeof(edge_num));
		cnt = 0;
		root_num = 0;
		scanf("%d", &v);
		n = mymax(n, u);
		n = mymax(n, v);
		add(u, v);
		while (~scanf("%d", &u) && u)
		{
			scanf("%d", &v);
			n = mymax(n, u);
			n = mymax(n, v);
			add(u, v);
		}
		if (!n) break;
		int dfs_clock = 0;
		out = false;
		memset(iscut, false, sizeof(iscut));
		memset(pre, 0, sizeof(pre));
		memset(low, 0, sizeof(low));
		findcut(1);
		if (root_num > 1) iscut[root] = true;
		printf("Network #%d\n", ++cas);
		for (int i = 1; i <= n; i++)
		{
			if (iscut[i])
			{
				out = true;
				memset(vis, false, sizeof(vis));
				vis[i] = 1;
				int son = 0;
				for (int j = edge_num[i]; ~j; j = e[j].nxt)
				{
					if (!vis[e[j].to])
					{
						dfs(e[j].to);
						son++;
					}
				}
				printf("  SPF node %d leaves %d subnets\n", i, son);
			}
		}
		if (!out) printf("  No SPF nodes\n");
		printf("\n");
		getchar();
	}
	return 0;
}
