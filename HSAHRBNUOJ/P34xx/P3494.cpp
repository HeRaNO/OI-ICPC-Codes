#include <cstdio>
#include <cstring>
#define MAXN 100010
#define INT_MAX 2147483647
using namespace std;

struct link
{
	int to;
	int nxt;
};

link e[MAXN];
int edge_num[MAXN], cnt;
int n, u, v;
int dp[MAXN], leafcnt;

inline int mymin(int a, int b)
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
}

void dfs1(int x, int father, bool odd)
{
	if (odd) dp[x] = INT_MAX;
	else dp[x] = 0;
	bool leaf = true;
	for (int i = edge_num[x]; ~i; i = e[i].nxt)
		if (e[i].to != father)
		{
			leaf = false;
			dfs1(e[i].to, x, !odd);
			if (odd) dp[x] = mymin(dp[x], dp[e[i].to]);
			else dp[x] += dp[e[i].to];
		}
	if (leaf)
	{
		dp[x] = 1;
		leafcnt++;
	}
	return ;
}

void dfs2(int x, int father, bool odd)
{
	if (odd) dp[x] = 0;
	else dp[x] = INT_MAX;
	bool leaf = true;
	for (int i = edge_num[x]; ~i; i = e[i].nxt)
		if (e[i].to != father)
		{
			leaf = false;
			dfs2(e[i].to, x, !odd);
			if (odd) dp[x] += dp[e[i].to];
			else dp[x] = mymin(dp[x], dp[e[i].to]);
		}
	if (leaf) dp[x] = 1;
	return ;
}

int main()
{
	memset(edge_num, -1, sizeof edge_num);
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		scanf("%d %d", &u, &v);
		add(u, v);
	}
	dfs1(1, 1, true);
	printf("%d ", leafcnt - dp[1] + 1);
	dfs2(1, 1, true);
	printf("%d\n", dp[1]);
	return 0;
}
