#include <bits/stdc++.h>
#define MAXN 400005
#define MAXM 1600005
#define fi first
#define se second
using namespace std;

struct edge
{
	int to,val,nxt;
};

struct Tax
{
	long long d;int u;
	Tax(){}
	Tax(long long _,int __):d(_),u(__){}
	bool operator < (const Tax &a)const{
		return d>a.d;
	}
};

edge e[MAXM];
int head[MAXN],cnt;
int n,m,S,T,u,v,w;
vector <pair<int,int> > g[MAXN>>2];
long long dis[MAXN];
bool vis[MAXN];
priority_queue <Tax> q;

inline void add(int u,int v,int w)
{
	e[cnt]=(edge){v,w,head[u]};head[u]=cnt++;
}

inline long long Dijkstra()
{
	memset(dis,0x3f,sizeof dis);
	q.push(Tax(0,S));dis[S]=0;
	while (!q.empty())
	{
		Tax x=q.top();q.pop();
		if (vis[x.u]) continue;vis[x.u]=true;
		for (int i=head[x.u];~i;i=e[i].nxt)
			if (dis[e[i].to]>dis[x.u]+e[i].val)
			{
				dis[e[i].to]=dis[x.u]+e[i].val;
				q.push(Tax(dis[e[i].to],e[i].to));
			}
	}
	return dis[T];
}

int main()
{
	memset(head,-1,sizeof head);
	scanf("%d %d",&n,&m);S=0;T=m<<1|1;
	for (int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		if (u==1) add(S,(i<<1)-1,w);if (v==n) add((i<<1)-1,T,w);
		if (v==1) add(S,i<<1,w);if (u==n) add(i<<1,T,w);
		g[u].push_back({w,(i<<1)-1});
		g[v].push_back({w,i<<1});
		add((i<<1)-1,i<<1,w);add(i<<1,(i<<1)-1,w);
	}
	for (int i=1;i<=n;i++)
	{
		if (!g[i].size()) continue;
		sort(g[i].begin(),g[i].end());
		for (int j=1;j<g[i].size();j++)
		{
			add(g[i][j-1].se,g[i][j].se,g[i][j].fi-g[i][j-1].fi);
			add(g[i][j].se,g[i][j-1].se,0);
		}
	}
	printf("%lld\n",Dijkstra());
	return 0;
}