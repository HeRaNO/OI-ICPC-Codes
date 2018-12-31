#include <cstdio>
#include <cstring>
#define MAXN 1010
#define MAXM 2000010
using namespace std;

struct link
{
	int to;
	int nxt;
};

link e[MAXM];
int T, n, m, x;
int edge_num[MAXN];
int sta[MAXM], top, cnt, ans, ans1;
int dfn[MAXN], low[MAXN], belong[MAXN];
bool vis[MAXN];
int in[MAXN], out[MAXN];

void add(int u, int v)
{
	e[cnt] = (link)
	{
		v, edge_num[u]
	};
	edge_num[u] = cnt++;
}

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

void Tarjan(int x)
{
	dfn[x] = low[x] = ++T;
	sta[++top] = x;
	for (int i = edge_num[x]; ~i; i = e[i].nxt)
	{
		if (vis[e[i].to]) continue;
		if (dfn[e[i].to]) low[x] = mymin(low[x], dfn[e[i].to]);
		else
		{
			Tarjan(e[i].to);
			low[x] = mymin(low[x], low[e[i].to]);
		}
	}
	if (dfn[x] == low[x])
	{
		int t;
		ans++;
		do
		{
			t = sta[top--];
			vis[t] = true;
			belong[t] = ans;
		}
		while (t != x);
	}
}

int main()
{
	memset(vis, false, sizeof(vis));
	memset(edge_num, -1, sizeof(edge_num));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &x);
			if (x) add(i, j);
		}
	for (int i = 1; i <= n; i++) if (!vis[i]) Tarjan(i);
	for (int i = 1; i <= n; i++)
		for (int j = edge_num[i]; ~j; j = e[j].nxt)
			if (belong[i] != belong[e[j].to])
				in[belong[e[j].to]]++;
	for (int i = 1; i <= ans; i++) ans1 += !in[i];
	printf("%d\n", ans1);
	return 0;
}
