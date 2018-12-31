#include <cstdio>
#include <cstring>
#define MAXN 2001000
#define MOD 10007
using namespace std;

struct link
{
	int to;
	int nxt;
};

link e[2 * MAXN];
int edge_num[MAXN], cnt;
int n, u, v;
int val[MAXN];
int ans, amt;
int dp[MAXN], dp_sum[MAXN];

int mymax(int a, int b)
{
	return a > b ? a : b;
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

void dfs(int node, int father)
{
	dp[node] = dp_sum[node] = 0;
	for (int i = edge_num[node]; ~i; i = e[i].nxt)
		if (e[i].to != father)
		{
			dfs(e[i].to, node);
			ans = mymax(mymax(ans, val[node] * dp[e[i].to]), val[e[i].to] * dp[node]);
			amt = (amt + val[node] * dp_sum[e[i].to] + val[e[i].to] * dp_sum[node]) % MOD;
			dp_sum[node] = (dp_sum[node] + val[e[i].to]) % MOD;
			dp[node] = mymax(dp[node], val[e[i].to]);
		}
}

int main()
{
	memset(edge_num, -1, sizeof(edge_num));
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		scanf("%d %d", &u, &v);
		add(u, v);
	}
	for (int i = 1; i <= n; i++) scanf("%d", &val[i]);
	dfs(1, -1);
	amt *= 2;
	amt %= MOD;
	printf("%d %d\n", ans, amt);
	return 0;
}
