#include <cstdio>
#include <cstring>
#define MAXN 200010
using namespace std;

int head[MAXN], nxt[MAXN * 2], to[MAXN * 2], cnt = 0;
int val[MAXN];
int dp[MAXN];
int u, v, n;
int ans;
bool vis[MAXN];

int mymax(int a, int b)
{
	return a > b ? a : b;
}

void dfs(int root)
{
	vis[root] = true;
	for (int i = head[root]; ~i; i = nxt[i])
	{
		if (vis[to[i]]) continue;
		dfs(to[i]);
		dp[root] += mymax(0, dp[to[i]]);
	}
	dp[root] += val[root];
	return ;
}

void add(int u, int v)
{
	nxt[cnt] = head[u];
	to[cnt] = v;
	head[u] = cnt++;
}

int main()
{
	memset(head, -1, sizeof(head));
	memset(vis, false, sizeof(vis));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &val[i]);
	for (int i = 1; i < n; i++)
	{
		scanf("%d %d", &u, &v);
		add(u, v);
		add(v, u);
	}
	dfs(1);
	for (int i = 1; i <= n; i++) ans = mymax(ans, dp[i]);
	printf("%d\n", ans);
	return 0;
}
