#include <bits/stdc++.h>
#define ll long long
#define ls id << 1
#define rs id << 1 | 1
#define mem(array, value, size, type) memset(array, value, ((size) + 5) * sizeof(type))
#define memarray(array, value) memset(array, value, sizeof(array))
#define pb(x) push_back(x)
#define st(x) (1LL << (x))
#define pii pair<int, int>
#define mp(a, b) make_pair((a), (b))
#define Flush fflush(stdout)
using namespace std;
const int N = 500050;
const int inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f;
const ll mod = 998244353LL;
clock_t TIME_START, TIME_END;
void program_end()
{
#ifdef ONLINE
	// printf("\nTime used: %.6lf(s)\n", ((double)TIME_END - TIME_START) / CLOCKS_PER_SEC);
  //  system("pause");
#endif
}
int n, m;
int f[N];
int Find(int x) { return x == f[x] ? x : f[x] = Find(f[x]); }
int ans[N], vis[N];
struct edge
{
	int x, y;
	ll w;
	int id;
} edges[N];
struct Edge
{
	int u, v, id;
	int nxt;
} e[N];
int head[N], ecnt;
inline void ad(int u, int v, int id)
{
	e[++ecnt].u = u;
	e[ecnt].v = v;
	e[ecnt].nxt = head[u];
	head[u] = ecnt;
	e[ecnt].id = id;
}
bool cmp(const edge &A, const edge &B)
{
	return A.w < B.w;
}
void print(int id)
{
	if (id == 0)
		puts("none");
	else if (id == 1)
		puts("at least one");
	else
		puts("any");
}
int dfn[N], low[N];
void tarjan(int u, int fa, int tim)
{
	vis[u] = 1;
	low[u] = dfn[u] = tim;
	for (int i = head[u]; i; i = e[i].nxt)
	{
		int v = e[i].v;
		if (vis[v] == 1 && e[i].id != fa)
			low[u] = min(low[u], dfn[v]);
		else if (!vis[v])
		{
			tarjan(v, e[i].id, tim + 1);
			low[u] = min(low[u], low[v]);
			if (low[v] > dfn[u])
				ans[edges[e[i].id].id] = 2;
		}
	}
	vis[u] = -1;
}
int p[N];

void solve()
{
	ecnt = 0;
	for (int i = 1; i <= n; ++i)
		f[i] = i, low[i] = dfn[i] = 0, head[i] = 0;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d%d%lld", &edges[i].x, &edges[i].y, &edges[i].w);
		edges[i].id = i;
		ans[i] = 0;
		p[i] = 0;
	}
	sort(edges + 1, edges + m + 1, cmp);
	edges[m + 1].w = 0;
	for (int i = 1; i <= m; ++i)
	{
		int noww = edges[i].w;
		int j;
		for (j = i; j <= m + 1; ++j)
			if (edges[j].w != noww)
			{
				j--;
				break;
			}
		for (int k = i; k <= j; ++k)
		{
			int x = edges[k].x, y = edges[k].y;
			int fx = Find(x), fy = Find(y);
			if (fx == fy)
				continue;
			ans[edges[k].id] = 1;
			ad(fx, fy, k);
			ad(fy, fx, k);
			p[k] = fx;
		}
		for (int k = i; k <= j; ++k)
		{
			if (vis[p[k]] == 0 && p[k] != 0)
				tarjan(p[k], 0, 1);
		}
		for (int k = i; k <= j; ++k)
		{
			int x = edges[k].x, y = edges[k].y;
			int fx = Find(x), fy = Find(y);
			if (fx == fy)
				continue;
			head[fx] = head[fy] = 0;
			vis[fx] = vis[fy] = 0;
			f[fx] = fy;
		}
		i = j;
		ecnt = 0;
	}
	for (int i = 1; i <= m; ++i)
		print(ans[i]);
}

int main()
{
	// TIME_START = clock();
	int Test = 1;
	// cin >> Test;
	while (~scanf("%d%d", &n, &m))
		solve();
	// TIME_END = clock();
	program_end();
	return 0;
}
/*
4 5
1 2 101
1 3 100
2 3 2
2 4 2
3 4 1
*/