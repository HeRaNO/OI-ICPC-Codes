#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 50010
using namespace std;

struct link
{
	int to;
	long long val;
	int nxt;
};

int n, m;
int u, v;
long long w;
int one_son_num;
long long sum_val;
int army[MAXN];
//Input&Perwork

link e[2 * MAXN];
int edge_num[MAXN], cnt;
//Link_Table

int father[MAXN];
long long dis[MAXN];
//LCA

int second_floor[MAXN];
long long second_to_first[MAXN];
long long leaf_to_second[MAXN];
//DFS

bool vis[MAXN];
bool go[MAXN];
long long rest[MAXN];
int cur[MAXN], pre[MAXN];
int match[MAXN];
bool can[MAXN];
//check

bool cmp(int a, int b)
{
	return dis[a] < dis[b];
}

bool cmp1(int a, int b)
{
	return second_to_first[a] > second_to_first[b];
}

bool cmp2(int a, int b)
{
	return a > b;
}

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

void dfs1(int node, int nowfather, long long len)
{
	father[node] = nowfather;
	dis[node] = len;
	for (int i = edge_num[node]; ~i; i = e[i].nxt)
		if (e[i].to != nowfather)
			dfs1(e[i].to, node, len + e[i].val);
}

void dfs2(int node, bool have_branch, int bigfather, long long len)
{
	second_floor[node] = bigfather;
	if (!have_branch)
	{
		int cntson = 0;
		for (int i = edge_num[node]; ~i; i = e[i].nxt)
			if (e[i].to != father[node])
			{
				cntson++;
				if (cntson == 2)
				{
					have_branch = true;
					break;
				}
			}
	}
	leaf_to_second[node] = len;
	for (int i = edge_num[node]; ~i; i = e[i].nxt)
		if (e[i].to != father[node])
			if (have_branch) dfs2(e[i].to, have_branch, bigfather, len + e[i].val);
			else dfs2(e[i].to, have_branch, bigfather, 0);
}

bool check(long long time)
{
	for (int i = edge_num[1]; ~i; i = e[i].nxt)
	{
		can[e[i].to] = false;
		cur[e[i].to] = 0;
	}
	rest[0] = 0;
	for (int i = 1; i <= m; i++)
	{
		if (time > dis[army[i]])
		{
			rest[++rest[0]] = time - dis[army[i]];
			pre[rest[0]] = cur[second_floor[army[i]]];
			cur[second_floor[army[i]]] = rest[0];
			vis[rest[0]] = false;
		}
		else
		{
			if (!can[second_floor[army[i]]] && time >= leaf_to_second[army[i]])
				can[second_floor[army[i]]] = true;
		}
	}
	match[0] = 0;
	for (int i = edge_num[1]; ~i; i = e[i].nxt)
		if (!can[e[i].to]) match[++match[0]] = e[i].to;
	if (match[0] > rest[0]) return false;
	sort(match + 1, match + match[0] + 1, cmp1);
	sort(rest + 1, rest + rest[0] + 1, cmp2);
	for (int i = 1, j = 1; i <= match[0] && j <= rest[0]; i++)
	{
		while (vis[cur[match[i]]]) cur[match[i]] = pre[cur[match[i]]];
		if (cur[match[i]]) vis[cur[match[i]]] = true;
		else
		{
			if (rest[j] < second_to_first[match[i]]) return false;
			vis[j] = true;
		}
		while (vis[j]) j++;
	}
	return true;
}

long long binary()
{
	long long left = 0, right = sum_val;
	while (left + 1 != right)
	{
		long long middle = (left + right) >> 1;
		if (check(middle)) right = middle;
		else left = middle;
	}
	return right;
}

int main()
{
	memset(edge_num, -1, sizeof(edge_num));
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		scanf("%d %d %lld", &u, &v, &w);
		add(u, v, w);
		sum_val += w;
	}
	dfs1(1, -1, 0);
	for (int i = edge_num[1]; ~i; i = e[i].nxt)
	{
		one_son_num++;
		second_to_first[e[i].to] = e[i].val;
		dfs2(e[i].to, false, e[i].to, 0);
	}
	scanf("%d", &m);
	if (one_son_num > m)
	{
		printf("-1\n");
		return 0;
	}
	for (int i = 1; i <= m; i++) scanf("%d", &army[i]);
	sort(army + 1, army + m + 1, cmp);
	printf("%lld\n", binary());
	return 0;
}
