#include <cstdio>
#include <climits>
#include <cstring>
#define MAXN 50000
#define MAXM 100000
using namespace std;

struct link
{
	int to;
	int val;
	int nxt;
};

link e[MAXM];
int edge_num[MAXN];
int n, m, ans, p, cnt;
int u, v, w;
char str[5];
bool vis[MAXN];

void add(int u, int v, long long w)
{
	e[cnt] = (link)
	{
		v, w, edge_num[u]
	};
	edge_num[u] = cnt++;
	e[cnt] = (link)
	{
		u, w, edge_num[v]
	};
	edge_num[v] = cnt++;
}

void dfs(int node, int len)
{
	vis[node] = true;
	if (len > ans)
	{
		ans = len;
		p = node;
	}
	for (int i = edge_num[node]; ~i; i = e[i].nxt)
		if (!vis[e[i].to]) dfs(e[i].to, len + e[i].val);
}
int main()
{
	while (~scanf("%d %d", &n, &m))
	{
		memset(edge_num, -1, sizeof(edge_num));
		cnt = 0;
		for (int i = 1; i <= m; i++)
		{
			scanf("%d %d %d %s", &u, &v, &w, str);
			add(u, v, w);
		}
		memset(vis, false, sizeof(vis));
		dfs(1, 0);
		memset(vis, false, sizeof(vis));
		dfs(p, 0);
		printf("%d\n", ans);
	}
	return 0;
}
