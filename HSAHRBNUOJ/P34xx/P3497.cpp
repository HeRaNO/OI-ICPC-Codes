#include <cstdio>
#include <cstring>
#define MAXN 100010
#define MOD 1000000007LL
using namespace std;

struct link
{
	int to;
	int nxt;
};

link e[MAXN * 2];
int edge_num[MAXN], cnt;
int n, x;
bool color[MAXN];
long long dp[2][MAXN];

inline void add(int u, int v)
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

inline void read(int &x)
{
	x = 0;
	int f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	x *= f;
	return ;
}

void dfs(int x, int father)
{
	dp[0][x] = 1;
	dp[1][x] = 0;
	for (int i = edge_num[x]; ~i; i = e[i].nxt)
		if (e[i].to != father)
		{
			dfs(e[i].to, x);
			dp[1][x] = (dp[1][x] * dp[0][e[i].to]) % MOD;
			dp[1][x] = (dp[1][x] + dp[0][x] * dp[1][e[i].to]) % MOD;
			dp[0][x] = (dp[0][x] * dp[0][e[i].to]) % MOD;
		}
	if (color[x]) dp[1][x] = dp[0][x];
	else dp[0][x] = (dp[0][x] + dp[1][x]) % MOD;
	return ;
}

int main()
{
	memset(edge_num, -1, sizeof edge_num);
	read(n);
	for (int i = 1; i < n; i++)
	{
		read(x);
		add(i, x);
	}
	for (int i = 0; i < n; i++) read(x), color[i] = x;
	dfs(0, 0);
	printf("%lld\n", dp[1][0]);
	return 0;
}
