#include <cstdio>
#include <cstring>
#define MAXN 10010
#define MAXM 20010
using namespace std;

struct link
{
	int to;
	int nxt;
};

link e[MAXM];
int edge_num[MAXN];
int dp[MAXN];
int n, cnt;
int u, v;
bool flag = false;

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

int dfs(int node, int father)
{
	int maxson = 0, sumson = 1;
	dp[node] = 0;
	for (int i = edge_num[node]; ~i; i = e[i].nxt)
	{
		if (e[i].to == father) continue;
		int res = dfs(e[i].to, node);
		maxson = mymax(maxson, res);
		sumson += res;
	}
	dp[node] = mymax(n - sumson, maxson);
	return sumson;
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
	dfs(1, -1);
	for (int i = 1; i <= n; i++)
	{
		if (2 * dp[i] <= n)
		{
			flag = true;
			printf("%d\n", i);
		}
	}
	if (!flag) printf("NONE\n");
	return 0;
}
