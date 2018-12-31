#pragma GCC optimize("O2")
#include <cstdio>
#include <cstring>
#define MAXN 200005
#define MAXK 1000005
#define INF 0x7f7f7f7f
using namespace std;

struct link
{
	int to, val, nxt;
};

link e[MAXN << 1];
int head[MAXN], cnt;
int n, k, u, v, w, G, T, SIZE, ans = INF;
int dis[MAXN], siz[MAXN], mx[MAXN], dp[MAXK], dep[MAXN];
bool vis[MAXN];

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

inline void add(int u, int v, int w)
{
	e[cnt] = (link)
	{
		v, w, head[u]
	};
	head[u] = cnt++;
	e[cnt] = (link)
	{
		u, w, head[v]
	};
	head[v] = cnt++;
}

inline void DFS_size_and_G(int x, int father)
{
	siz[x] = 1;
	mx[x] = 0;
	for (int i = head[x]; ~i; i = e[i].nxt)
		if (e[i].to != father && !vis[e[i].to])
		{
			DFS_size_and_G(e[i].to, x);
			siz[x] += siz[e[i].to];
			mx[x] = mymax(mx[x], siz[e[i].to]);
		}
	mx[x] = mymax(mx[x], SIZE - siz[x]);
	if (mx[x] < mx[G]) G = x;
	return ;
}

inline void TreeDP(int x, int father, int dist, int deep)
{
	dis[x] = dist;
	dep[x] = deep;
	if (dis[x] <= k && dp[k - dis[x]] != INF)
		ans = mymin(ans, dp[k - dis[x]] + dep[x]);
	for (int i = head[x]; ~i; i = e[i].nxt)
		if (e[i].to != father && !vis[e[i].to])
			TreeDP(e[i].to, x, dist + e[i].val, deep + 1);
	return ;
}

inline void Update(int x, int father, bool del)
{
	if (dis[x] <= k)
	{
		if (del)
		{
			dp[dis[x]] = INF;
			dis[x] = 0;
			dep[x] = 0;
		}
		else dp[dis[x]] = mymin(dp[dis[x]], dep[x]);
	}
	for (int i = head[x]; ~i; i = e[i].nxt)
		if (e[i].to != father && !vis[e[i].to])
			Update(e[i].to, x, del);
	return ;
}

inline void TreeDC(int x)
{
	vis[x] = true;
	dp[0] = 0;
	for (int i = head[x]; ~i; i = e[i].nxt)
		if (!vis[e[i].to])
		{
			TreeDP(e[i].to, x, e[i].val, 1);
			Update(e[i].to, x, false);
		}
	for (int i = head[x]; ~i; i = e[i].nxt)
		if (!vis[e[i].to]) Update(e[i].to, x, true);
	for (int i = head[x]; ~i; i = e[i].nxt)
		if (!vis[e[i].to])
		{
			mx[0] = SIZE = siz[e[i].to];
			G = 0;
			DFS_size_and_G(e[i].to, x);
			TreeDC(G);
		}
	vis[x] = false;
	return ;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return ;
}

int main()
{
	memset(head, -1, sizeof head);
	memset(dp, 0x7f, sizeof dp);
	read(n);
	read(k);
	for (int i = 1; i < n; i++)
	{
		read(u);
		read(v);
		read(w);
		add(u + 1, v + 1, w);
	}
	SIZE = mx[0] = n;
	G = 0;
	DFS_size_and_G(1, -1);
	TreeDC(G);
	printf("%d\n", ans == INF ? -1 : ans);
	return 0;
}