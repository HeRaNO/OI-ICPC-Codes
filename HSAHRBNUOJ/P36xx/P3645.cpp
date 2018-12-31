#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
#define MOD 1000003LL
using namespace std;

struct link
{
	int to, nxt;
};

link e[MAXN << 1];
int head[MAXN], cnt;
int n, u, v, K, G, SIZE, T, R;
int siz[MAXN], mx[MAXN], father[MAXN];
int dis[MAXN], id[MAXN], inv[MOD], table[MOD], table_tim[MOD];
long long w[MAXN];
bool vis[MAXN];

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}
inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

inline void add(int u, int v)
{
	e[cnt] = (link)
	{
		v, head[u]
	};
	head[u] = cnt++;
	e[cnt] = (link)
	{
		u, head[v]
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

inline void DFS_dis(int x, int father, long long dist)
{
	dis[T] = dist;
	id[T++] = x;
	siz[x] = 1;
	for (int i = head[x]; ~i; i = e[i].nxt)
		if (e[i].to != father && !vis[e[i].to])
		{
			DFS_dis(e[i].to, x, dist * w[e[i].to] % MOD);
			siz[x] += siz[e[i].to];
		}
	return ;
}

inline void Update(int x, int y)
{
	if (x > y) swap(x, y);
	if (u > x || (u == x && v > y)) u = x, v = y;
	return ;
}

inline void Calculate(int x)
{
	int pts;
	for (int i = 0; i < T; i++)
	{
		pts = w[x] * dis[i] % MOD;
		if (K == pts) Update(x, id[i]);
		pts = (long long)K * inv[pts] % MOD;
		if (table_tim[pts] == R) Update(id[i], table[pts]);
	}
	for (int i = 0; i < T; i++)
	{
		if (table_tim[dis[i]] == R) table[dis[i]] = mymin(table[dis[i]], id[i]);
		else
		{
			table_tim[dis[i]] = R;
			table[dis[i]] = id[i];
		}
	}
	return ;
}

inline void TreeDC(int x)
{
	vis[x] = true;
	R++;
	for (int i = head[x]; ~i; i = e[i].nxt)
		if (!vis[e[i].to])
		{
			T = 0;
			DFS_dis(e[i].to, x, w[e[i].to]);
			Calculate(x);
		}
	for (int i = head[x]; ~i; i = e[i].nxt)
		if (!vis[e[i].to])
		{
			SIZE = mx[0] = siz[e[i].to];
			G = 0;
			DFS_size_and_G(e[i].to, x);
			TreeDC(G);
		}
	vis[x] = false;
	return ;
}

inline int read()
{
	int x = 0;
	char ch;
	if ((ch = getchar()) == EOF) return 0;
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return x;
}

int main()
{
	inv[1] = 1;
	for (int i = 2; i < MOD; i++) inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
	while (true)
	{
		n = read();
		if (!n) break;
		K = read();
		memset(head, -1, sizeof head);
		cnt = 0;
		for (int i = 1; i <= n; i++) w[i] = read();
		for (int i = 1; i < n; i++)
		{
			u = read();
			v = read();
			add(u, v);
		}
		SIZE = mx[0] = n;
		G = 0;
		DFS_size_and_G(1, -1);
		u = ~(1 << 31);
		v = u;
		TreeDC(G);
		if (u == ~(1 << 31)) puts("No solution");
		else printf("%d %d\n", u, v);
	}
	return 0;
}