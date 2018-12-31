#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 200
#define MAXM 10010
using namespace std;

struct link
{
	int to;
	int nxt;
};

link e[MAXM], ans[MAXM];
int n, m, cnt, u, v, T, ccnt;
int edge_num[MAXN];
int dfn[MAXN], low[MAXN];
bool g[MAXN][MAXN], out[MAXN][MAXN];

bool cmp(link a, link b)
{
	if (a.to == b.to) return a.nxt < b.nxt;
	return a.to < b.to;
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

void Tarjan(int x, int father)
{
	dfn[x] = low[x] = ++T;
	for (int i = edge_num[x]; ~i; i = e[i].nxt)
	{
		if (!dfn[e[i].to])
		{
			Tarjan(e[i].to, x);
			low[x] = mymin(low[x], low[e[i].to]);
			if (low[e[i].to] > dfn[x]) ans[++ccnt] = (link)
			{
				x, e[i].to
			};
		}
		else if (e[i].to != father) low[x] = mymin(low[x], dfn[e[i].to]);
	}
}

int main()
{
	memset(g, false, sizeof(g));
	memset(out, false, sizeof(out));
	memset(edge_num, -1, sizeof(edge_num));
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d", &u, &v);
		add(u, v);
	}
	Tarjan(1, 1);
	for (int i = 1; i <= ccnt; i++) if (ans[i].to > ans[i].nxt) swap(ans[i].to, ans[i].nxt);
	sort(ans + 1, ans + ccnt + 1, cmp);
	for (int i = 1; i <= ccnt; i++) printf("%d %d\n", ans[i].to, ans[i].nxt);
	return 0;
}
