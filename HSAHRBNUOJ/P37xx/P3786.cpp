#include <cstdio>
#include <cstring>
#define MAXN 20010
using namespace std;

struct link
{
	int to, val, nxt;
};

link e[MAXN << 1];
int head[MAXN], cnt;
int n, u, v, w, G, SIZE, all, ans, t;
int siz[MAXN], dis[3], dp[3], mx[MAXN];
bool vis[MAXN];

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

inline int gcd(int a, int b)
{
	return !b ? a : gcd(b, a % b);
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
		if (!vis[e[i].to] && e[i].to != father)
		{
			DFS_size_and_G(e[i].to, x);
			siz[x] += siz[e[i].to];
			mx[x] = mymax(mx[x], siz[e[i].to]);
		}
	mx[x] = mymax(mx[x], SIZE - siz[x]);
	if (mx[x] < mx[G]) G = x;
	return ;
}

inline void DFS_dis(int x, int father, int dist)
{
	dis[dist]++;
	siz[x] = 1;
	for (int i = head[x]; ~i; i = e[i].nxt)
		if (e[i].to != father && !vis[e[i].to])
		{
			DFS_dis(e[i].to, x, (dist + e[i].val) % 3);
			siz[x] += siz[e[i].to];
		}
	return ;
}

inline void Calculate()
{
	for (int i = 0; i < 3; i++) ans += dis[i] * dp[(3 - i) % 3];
	for (int i = 0; i < 3; i++)
	{
		dp[i] += dis[i];
		dis[i] = 0;
	}
	return ;
}

inline void TreeDC(int x)
{
	vis[x] = true;
	dp[0] = 1;
	for (int i = 1; i < 3; i++) dp[i] = 0;
	for (int i = head[x]; ~i; i = e[i].nxt)
		if (!vis[e[i].to])
		{
			DFS_dis(e[i].to, x, e[i].val % 3);
			Calculate();
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
	//freopen("cckk.in","r",stdin);freopen("cckk.out","w",stdout);
	memset(head, -1, sizeof head);
	read(n);
	all = n * n;
	for (int i = 1; i < n; i++)
	{
		read(u);
		read(v);
		read(w);
		add(u, v, w);
	}
	SIZE = mx[0] = n;
	G = 0;
	DFS_size_and_G(1, -1);
	TreeDC(G);
	ans = (ans << 1) + n;
	t = gcd(ans, all);
	printf("%d/%d\n", ans / t, all / t);
	return 0;
}