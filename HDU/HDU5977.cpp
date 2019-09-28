#include <bits/stdc++.h>
#define MAXN 50005
using namespace std;

struct link
{
	int to,nxt;
};

link e[MAXN<<1];
int head[MAXN], cnt;
int n, k, u, v, w, G, SIZE, T;
long long ans;
int siz[MAXN], dis[MAXN], mx[MAXN], h[1024], a[MAXN];
bool vis[MAXN];

inline void add(int u, int v)
{
	e[cnt] = (link){v, head[u]}; head[u] = cnt++;
	e[cnt] = (link){u, head[v]}; head[v] = cnt++;
}

inline void DFS_size_and_G(int x, int f)
{
	siz[x] = 1;
	mx[x] = 0;
	for (int i = head[x]; ~i; i = e[i].nxt)
		if (e[i].to != f && !vis[e[i].to])
		{
			DFS_size_and_G(e[i].to, x);
			siz[x] += siz[e[i].to];
			mx[x] = max(mx[x], siz[e[i].to]);
		}
	mx[x] = max(mx[x], SIZE - siz[x]);
	if (mx[x] < mx[G]) G = x;
	return ;
}

inline void DFS_col(int x, int f, int col)
{
	dis[T++] = col; ++h[col];
	siz[x] = 1;
	for (int i = head[x]; ~i; i = e[i].nxt)
		if (e[i].to != f && !vis[e[i].to])
		{
			DFS_col(e[i].to, x, col | (1 << a[e[i].to]));
			siz[x] += siz[e[i].to];
		}
	return ;
}

inline long long Calculate(int x, int dist)
{
	T = 0; long long res = 0;
	memset(h, 0, sizeof h);
	DFS_col(x, -1, dist);
	for (int i = 0; i < T; i++)
	{
		--h[dis[i]];
		res += h[(1 << k) - 1];
		for (int s = dis[i] ; s; s = (s - 1) & dis[i])
			res += h[((1 << k) - 1) ^ s];
		++h[dis[i]];
	}
	return res;
}

inline void TreeDC(int x)
{
	ans += Calculate(x, 1 << a[x]);
	vis[x] = true;
	for (int i = head[x]; ~i; i = e[i].nxt)
		if (!vis[e[i].to])
		{
			ans -= Calculate(e[i].to, (1 << a[x]) | (1 << a[e[i].to]));
			mx[0] = SIZE = siz[e[i].to];
			G = 0;
			DFS_size_and_G(e[i].to, x);
			TreeDC(G);
		}
	vis[x] = false;
	return ;
}

int main()
{
	while (scanf("%d%d",&n,&k)==2)
	{
		memset(head,-1,(n+1)*sizeof (int));cnt=0;ans=0;
		memset(vis,false,(n+1)*sizeof (int));
		for (int i=1;i<=n;i++) scanf("%d",&a[i]),--a[i];
		for (int i=1;i<n;i++)
		{
			scanf("%d%d",&u,&v);
			add(u,v);
		}
		if (k==1)
		{
			printf("%lld\n",1LL*n*n);
			continue;
		}
		SIZE = mx[0] = n;
		G = 0;
		DFS_size_and_G(1, -1);
		TreeDC(G);
		printf("%lld\n",ans);
	}
	return 0;
}