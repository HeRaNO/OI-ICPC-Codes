#include <cstdio>
#include <cstring>
#define MAXM 3010
#define MAXN 1010
using namespace std;

struct link
{
	int to;
	int nxt;
};

struct rabbit
{
	int len;
	bool in_cir;
};

link e[MAXM];
rabbit a[MAXN];
int n, m, k, u, v;
int edge_num[MAXN], cnt, cnt1;
int in[MAXN], root, t;
bool vis[MAXN];

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}
inline int calc(int len, int t)
{
	if (len <= 0) return 0;
	return (len - 1) / (t * 2 + 1) + 1;
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

void dfs(int node)
{
	vis[node] = true;
	a[cnt1].len++;
	for (int i = edge_num[node]; ~i; i = e[i].nxt)
	{
		if (!vis[e[i].to]) dfs(e[i].to);
		else if (e[i].to == root && node != t) a[cnt1].in_cir = true;
	}
}

bool check(int limit)
{
	int mind = n + 1;
	for (int i = 1; i <= cnt1; i++)
		for (int j = 0; j <= a[i].len && j <= limit; j++)
		{
			int tot;
			if (!a[i].in_cir) tot = calc(a[i].len - j - limit, limit);
			else tot = calc(a[i].len - 2 * limit, limit);
			tot++;
			for (int k = 1; k <= cnt1; k++)
				if (k != i)
				{
					if (!a[k].in_cir) tot += calc(a[k].len + j - limit, limit);
					else tot += calc(a[k].len + 2 * (j - limit), limit);
				}
			mind = mymin(mind, tot);
		}
	return mind <= k;
}

int binary()
{
	int left = 0, right = n + 1, middle;
	while (right - left > 1)
	{
		middle = (left + right) >> 1;
		if (check(middle)) right = middle;
		else left = middle;
	}
	return right;
}

int main()
{
	memset(edge_num, -1, sizeof edge_num);
	memset(vis, false, sizeof vis);
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d", &u, &v);
		in[u]++;
		in[v]++;
		if (in[u] > 2) root = u;
		if (in[v] > 2) root = v;
		add(u, v);
	}
	vis[root] = true;
	for (int i = edge_num[root]; ~i; i = e[i].nxt)
		if (!vis[e[i].to])
		{
			t = e[i].to;
			cnt1++;
			a[cnt1] = (rabbit)
			{
				0, 0
			};
			dfs(e[i].to);
		}
	printf("%d\n", binary());
	return 0;
}
