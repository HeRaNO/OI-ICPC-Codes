#include <cstdio>
#include <cstring>
#define MAXN 300010
using namespace std;

struct link
{
	int to;
	int val;
	int nxt;
};

link e[MAXN * 2];
int edge_num[MAXN], cnt;
int n, u, v, w;
long long val[MAXN], mx1, mx2, now;
long long dp1[MAXN], dp2[MAXN];
long long f[MAXN], g[MAXN], ans[MAXN];

inline long long mymax(long long a, long long b)
{
	return a > b ? a : b;
}
inline long long mymin(long long a, long long b)
{
	return a < b ? a : b;
}

inline void add(int u, int v, int w)
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

void dfs1(int node, int father)
{
	long long mx = 0LL;
	for (int i = edge_num[node]; ~i; i = e[i].nxt)
		if (e[i].to != father)
		{
			dfs1(e[i].to, node);
			if (dp1[e[i].to] - 2 * e[i].val > 0)
			{
				dp1[node] += dp1[e[i].to] - 2 * e[i].val;
				mx = mymax(mx, e[i].val + dp2[e[i].to] - dp1[e[i].to]);
			}
			else mx = mymax(mx, dp2[e[i].to] - e[i].val);
		}
	dp1[node] += val[node];
	dp2[node] = dp1[node] + mx;
	return ;
}

void dfs2(int node, int father, int len)
{
	ans[node] = mymax(dp1[node] + mymax(g[node] - len, 0LL), dp2[node] + mymax(f[node] - len * 2, 0LL));
	long long mx1 = 0LL, mx2 = 0LL, now;
	for (int i = edge_num[node]; ~i; i = e[i].nxt)
		if (e[i].to != father)
		{
			if (dp1[e[i].to] - 2 * e[i].val > 0) now = e[i].val + dp2[e[i].to] - dp1[e[i].to];
			else now = dp2[e[i].to] - e[i].val;
			if (now > mx1)
			{
				mx2 = mx1;
				mx1 = now;
			}
			else if (now > mx2) mx2 = now;
		}
	if (f[node] - 2 * len > 0) now = len + g[node] - f[node];
	else now = g[node] - len;
	if (now > mx1)
	{
		mx2 = mx1;
		mx1 = now;
	}
	else if (now > mx2) mx2 = now;
	for (int i = edge_num[node]; ~i; i = e[i].nxt)
		if (e[i].to != father)
		{
			f[e[i].to] = dp1[node] - mymax(0LL, dp1[e[i].to] - 2 * e[i].val) + mymax(0LL, f[node] - 2 * len);
			if (dp1[e[i].to] - 2 * e[i].val > 0) now = e[i].val + dp2[e[i].to] - dp1[e[i].to];
			else now = dp2[e[i].to] - e[i].val;
			if (now == mx1) g[e[i].to] = f[e[i].to] + mx2;
			else g[e[i].to] = f[e[i].to] + mx1;
		}
	for (int i = edge_num[node]; ~i; i = e[i].nxt)
		if (e[i].to != father) dfs2(e[i].to, node, e[i].val);
}

int main()
{
	//freopen("treasure.in","r",stdin);freopen("treasure.out","w",stdout);
	memset(edge_num, -1, sizeof edge_num);
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		scanf("%d %d %d", &u, &v, &w);
		add(u, v, w);
	}
	for (int i = 1; i <= n; i++) scanf("%d", &val[i]);
	dfs1(1, 1);
	for (int i = edge_num[1]; ~i; i = e[i].nxt)
		if (dp1[e[i].to] - 2 * e[i].val > 0) f[e[i].to] = dp1[1] - (dp1[e[i].to] - 2 * e[i].val);
		else f[e[i].to] = dp1[1];
	for (int i = edge_num[1]; ~i; i = e[i].nxt)
	{
		if (dp1[e[i].to] - 2 * e[i].val > 0) now = e[i].val + dp2[e[i].to] - dp1[e[i].to];
		else now = dp2[e[i].to] - e[i].val;
		if (now > mx1)
		{
			mx2 = mx1;
			mx1 = now;
		}
		else if (now > mx2) mx2 = now;
	}
	for (int i = edge_num[1]; ~i; i = e[i].nxt)
	{
		if (dp1[e[i].to] - 2 * e[i].val > 0) now = e[i].val + dp2[e[i].to] - dp1[e[i].to];
		else now = dp2[e[i].to] - e[i].val;
		if (now == mx1) g[e[i].to] = f[e[i].to] + mx2;
		else g[e[i].to] = f[e[i].to] + mx1;
	}
	ans[1] = dp2[1];
	for (int i = edge_num[1]; ~i; i = e[i].nxt) dfs2(e[i].to, 1, e[i].val);
	for (int i = 1; i <= n; i++) printf("%lld\n", ans[i]);
	return 0;
}
