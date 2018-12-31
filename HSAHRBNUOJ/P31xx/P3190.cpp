#include <cstdio>
#include <climits>
#include <cstring>
#include <algorithm>
#define MAXN 30010
#define MAXM 500010
using namespace std;

struct edge
{
	int from;
	int to;
	int val;
	bool type;
};

struct link
{
	int to;
	int val;
	int nxt;
};

edge edges[MAXM];
link e[2 * MAXN];
int n, m, k, T, cnt;
int u, v, w1, w2, maxdep;
int father[MAXN];
int edge_num[MAXN];
int LCAFather[MAXN][30], LCAVal[MAXN][30];
int dep[MAXN], _2pow[31];

bool cmp(edge a, edge b)
{
	return a.val < b.val;
}

int getfather(int x)
{
	return father[x] == x ? x : father[x] = getfather(father[x]);
}

void add(int u, int v, int w)
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

int mymax(int a, int b)
{
	return a > b ? a : b;
}

bool kruskal_judge(int limit)
{
	for (int i = 1; i <= n; i++) father[i] = i;
	int cnt = 0;
	for (int i = 1; i <= m && edges[i].val <= limit; i++)
		if (edges[i].type)
		{
			int x = getfather(edges[i].from);
			int y = getfather(edges[i].to);
			if (x != y) father[y] = x, cnt++;
		}
	if (cnt < k) return false;
	for (int i = 1; i <= m && edges[i].val <= limit; i++)
	{
		int x = getfather(edges[i].from);
		int y = getfather(edges[i].to);
		if (x != y) father[y] = x, cnt++;
	}
	return cnt == n - 1;
}

void make_graph(int limit)
{
	memset(edge_num, -1, sizeof(edge_num));
	for (int i = 1; i <= n; i++) father[i] = i;
	int cnt = 0;
	for (int i = 1; i <= m && edges[i].val <= limit; i++)
		if (edges[i].type)
		{
			int x = getfather(edges[i].from);
			int y = getfather(edges[i].to);
			if (x != y)
			{
				father[y] = x;
				cnt++;
				add(edges[i].from, edges[i].to, edges[i].val);
			}
		}
	for (int i = 1; i <= m && edges[i].val <= limit; i++)
	{
		int x = getfather(edges[i].from);
		int y = getfather(edges[i].to);
		if (x != y)
		{
			father[y] = x;
			cnt++;
			add(edges[i].from, edges[i].to, edges[i].val);
		}
	}
	return ;
}

int binary()
{
	int left = 1, right = INT_MAX, middle;
	while (left < right)
	{
		middle = (left + right) >> 1;
		if (kruskal_judge(middle)) right = middle;
		else left = middle + 1;
	}
	make_graph(right);
	return right;
}

void dfs(int node, int pre_father, int val, int deep)
{
	LCAFather[node][0] = pre_father;
	LCAVal[node][0] = val;
	dep[node] = deep;
	for (int i = edge_num[node]; ~i; i = e[i].nxt)
		if (e[i].to != pre_father)
			dfs(e[i].to, node, e[i].val, deep + 1);
}

void LCA()
{
	for (int j = 1; j <= maxdep; j++)
		for (int i = 1; i <= n; i++)
		{
			LCAFather[i][j] = LCAFather[LCAFather[i][j - 1]][j - 1];
			LCAVal[i][j] = mymax(LCAVal[i][j - 1], LCAVal[LCAFather[i][j - 1]][j - 1]);
		}
	return ;
}

int query(int u, int v)
{
	int ans = 0;
	if (dep[u] > dep[v]) swap(u, v);
	for (int i = maxdep; ~i; i--)
	{
		if (_2pow[i] <= dep[v] - dep[u])
		{
			ans = mymax(ans, LCAVal[v][i]);
			v = LCAFather[v][i];
		}
	}
	for (int i = maxdep; ~i; i--)
	{
		if (LCAFather[v][i] != LCAFather[u][i])
		{
			ans = mymax(ans, mymax(LCAVal[u][i], LCAVal[v][i]));
			u = LCAFather[u][i];
			v = LCAFather[v][i];
		}
	}
	if (u != v) ans = mymax(ans, mymax(LCAVal[u][0], LCAVal[v][0]));
	return ans;
}

int main()
{
	freopen("route.in", "r", stdin);
	freopen("route.out", "w", stdout);
	scanf("%d %d %d", &n, &k, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d %d %d", &u, &v, &w1, &w2);
		edges[(i << 1) - 1].from = edges[i << 1].from = u;
		edges[(i << 1) - 1].to = edges[i << 1].to = v;
		edges[(i << 1) - 1].type = true;
		edges[(i << 1) - 1].val = w1;
		edges[i << 1].type = false;
		edges[i << 1].val = w2;
	}
	m <<= 1;
	sort(edges + 1, edges + m + 1, cmp);
	printf("%d\n", binary());
	_2pow[0] = 1;
	for (maxdep = 0; _2pow[maxdep] <= n; maxdep++) _2pow[maxdep + 1] = _2pow[maxdep] << 1;
	for (int i = 1; i <= n; i++)
		if (!LCAFather[i][0]) dfs(i, 0, INT_MAX, 1);
	LCA();
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &u, &v);
		printf("%d\n", query(u, v));
	}
	return 0;
}
