#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 1005
#define MAXM 100010
using namespace std;

struct link
{
	int to;long long val;int nxt;
};

struct node
{
	long long d; int u;
	bool operator < (const node &a)const
	{
		return d > a.d;
	}
};

struct Kth_Shortest_Path
{
	long long h, g; int pos;
	bool operator < (const Kth_Shortest_Path &a)const
	{
		return h + g > a.h + a.g;
	}
};

link e[MAXM], g[MAXM];
int head[MAXN], cnt1, hg[MAXN], cnt2;
int n, m, k, u, v, w, s, t; long long dis[MAXN];
bool vis[MAXN];
priority_queue <node> q;
priority_queue <Kth_Shortest_Path> Q;

inline void add(int u, int v, long long w)
{
	e[cnt1] = (link){v, w, head[u]};head[u] = cnt1++;
	g[cnt2] = (link){u, w, hg[v]};hg[v] = cnt2++;
}

inline void Dijkstra(int S)
{
	for (int i=1;i<=n;i++) dis[i]=1e15;
	q.push((node){0, S});dis[S] = 0;
	while (!q.empty())
	{
		node x = q.top();
		q.pop();
		if (vis[x.u]) continue;
		vis[x.u] = true;
		for (int i = hg[x.u]; ~i; i = g[i].nxt)
		{
			if (dis[g[i].to] > dis[x.u] + g[i].val)
			{
				dis[g[i].to] = dis[x.u] + g[i].val;
				q.push((node){dis[g[i].to], g[i].to});
			}
		}
	}
	return ;
}

inline long long Astar(int S, int T, int k)
{
	int K=0;long long ans=-1;
	if (dis[S] == 1e15) return -1;
	if (S==T) ++k;
	Q.push((Kth_Shortest_Path){dis[S], 0LL, S});
	while (K<k)
	{
		if (Q.empty()) return -1;
		Kth_Shortest_Path u = Q.top(); Q.pop();
		if (u.pos == T) ++K, ans=u.g;
		for (int i = head[u.pos]; ~i; i = e[i].nxt)
			Q.push((Kth_Shortest_Path){dis[e[i].to], u.g + e[i].val, e[i].to});
	}
	return ans;
}

inline void read(int &x)
{
	x=0;char ch=getchar();bool f=false;
	while (ch<'0'||ch>'9'){if (ch=='-') f=true;ch=getchar();}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	if (f) x=-x;return ;
}

int main()
{
	memset(head, -1, sizeof head); memset(hg, -1, sizeof hg);
	read(n);read(m);read(k);read(s);read(t);
	for (int i = 1; i <= m; i++)
	{
		read(u);read(v);read(w);add(u, v, w);
	}
	Dijkstra(t);
	printf("%lld\n",Astar(s,t,k));
	return 0;
}