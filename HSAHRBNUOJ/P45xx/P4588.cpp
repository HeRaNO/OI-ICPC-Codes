#pragma GCC optimize("O2")
#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 100001
#define MAXM 200001
#define MAXK 51
using namespace std;

struct link
{
	int to, val, nxt;
};

struct node
{
	int d, u;
	bool operator < (const node &a)const
	{
		return d > a.d;
	}
};

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return ;
}

link e[MAXM], f[MAXM];
int heade[MAXN], headf[MAXN], cnte;
int n, m, P, k, T, u, v, w;
int dp[MAXN][MAXK], dis1[MAXN], disn[MAXN];
bool vis[MAXN], inf;
int in[MAXN], sta[MAXM << 1], top, topo[MAXM << 1], cnt;
priority_queue <node> q;

inline void add(int u, int v, int w)
{
	e[cnte] = (link)
	{
		v, w, heade[u]
	};
	heade[u] = cnte;
	f[cnte] = (link)
	{
		u, w, headf[v]
	};
	headf[v] = cnte++;
}

inline void Dijkstra(int S, int dis[], link e[], int head[])
{
	memset(vis, false, sizeof vis);
	q.push((node)
	{
		0, S
	});
	dis[S] = 0;
	while (!q.empty())
	{
		node x = q.top();
		q.pop();
		if (vis[x.u]) continue;
		vis[x.u] = true;
		for (int i = head[x.u]; ~i; i = e[i].nxt)
			if (dis[e[i].to] > dis[x.u] + e[i].val)
			{
				dis[e[i].to] = dis[x.u] + e[i].val;
				q.push((node)
				{
					dis[e[i].to], e[i].to
				});
			}
	}
	return ;
}

inline void Topology_Sort()
{
	for (int i = 1; i <= n; i++)
		for (int j = heade[i]; ~j; j = e[j].nxt)
			if (dis1[i] + e[j].val == dis1[e[j].to]) in[e[j].to]++;
	for (int i = 1; i <= n; i++) if (!in[i]) sta[++top] = i;
	while (top)
	{
		int u = sta[top--];
		topo[++cnt] = u;
		for (int i = heade[u]; ~i; i = e[i].nxt)
			if (dis1[u] + e[i].val == dis1[e[i].to])
				if (--in[e[i].to] == 0) sta[++top] = e[i].to;
	}
	return ;
}

inline void upd(int &x, int y)
{
	x += y;
	if (x >= P) x -= P;
	return ;
}

inline int DP()
{
	memset(dp, 0, sizeof dp);
	dp[1][0] = 1;
	int ans = 0;
	for (int i = 0; i <= k; i++)
	{
		for (int j = 1; j <= cnt; j++)
			for (int u = heade[topo[j]]; ~u; u = e[u].nxt)
				if (dis1[topo[j]] + e[u].val == dis1[e[u].to])
					upd(dp[e[u].to][i], dp[topo[j]][i]);
		for (int j = 1; j <= n; j++)
			for (int u = heade[j]; ~u; u = e[u].nxt)
				if (dis1[j] + e[u].val != dis1[e[u].to] && dis1[j] + e[u].val + i - dis1[e[u].to] <= k)
					upd(dp[e[u].to][dis1[j] + e[u].val + i - dis1[e[u].to]], dp[j][i]);
	}
	for (int i = 0; i <= k; i++) upd(ans, dp[n][i]);
	return ans;
}

int main()
{
	//freopen("park.in","r",stdin);freopen("park.out","w",stdout);
	read(T);
	while (T--)
	{
		memset(heade, -1, sizeof heade);
		memset(headf, -1, sizeof headf);
		memset(dis1, 0x7f, sizeof dis1);
		memset(disn, 0x7f, sizeof disn);
		memset(in, 0, sizeof in);
		inf = false;
		top = cnt = cnte = 0;
		read(n);
		read(m);
		read(k);
		read(P);
		for (int i = 1; i <= m; i++)
		{
			read(u);
			read(v);
			read(w);
			add(u, v, w);
		}
		Dijkstra(1, dis1, e, heade);
		Dijkstra(n, disn, f, headf);
		Topology_Sort();
		for (int i = 1; i <= n && !inf; i++)
			if (in[i] && dis1[i] + disn[i] <= dis1[n] + k) inf = true;
		if (inf) puts("-1");
		else printf("%d\n", DP());
	}
	return 0;
}