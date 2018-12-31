#include <cstdio>
#include <cstring>
#define MAXN 50010
using namespace std;

struct link
{
	int to;
	long long val;
	int nxt;
};

link e[MAXN * 2];
int edge_num[MAXN], cnt;
int n, u, v;
long long ans, w, dp[MAXN];

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

long long mymax(long long a, long long b)
{
	return a > b ? a : b;
}

long long TreeDP(int node, int father)
{
	long long res = 0;
	for (int i = edge_num[node]; ~i; i = e[i].nxt)
		if (e[i].to != father) res = mymax(res, TreeDP(e[i].to, node) + e[i].val);
	return res;
}

int main()
{
	//freopen("tour.in","r",stdin);freopen("tour.out","w",stdout);
	memset(edge_num, -1, sizeof edge_num);
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		scanf("%d %d %lld", &u, &v, &w);
		add(u, v, w);
		ans += 2 * w;
	}
	ans -= TreeDP(1, 1);
	printf("%lld\n", ans);
	return 0;
}
