#include <bits/stdc++.h>
#define MAXN 100005
#define MAXM 200005
using namespace std;

struct link
{
	int to,val,nxt;
};

link e[MAXM<<1],g[MAXN<<1];
int head[MAXN],cnt;
int headg[MAXN],cnt2;
int n,m,T,TT,u,v,w;
int dfn[MAXN],low[MAXN],f[MAXN],cntt[MAXN];
set <int> cut[MAXN];
char a[MAXN];
long long ans;

inline int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

inline void add(int u,int v,int w)
{
	e[cnt]=(link){v,w,head[u]};head[u]=cnt++;
	e[cnt]=(link){u,w,head[v]};head[v]=cnt++;
}

inline void addedge(int u,int v,int w)
{
	g[cnt2]=(link){v,w,headg[u]};headg[u]=cnt2++;
}

inline void Tarjan(int x,int f)
{
	dfn[x]=low[x]=++T;
	for (int i=head[x];~i;i=e[i].nxt)
		if (e[i].to!=f)
		{
			if (dfn[e[i].to]) low[x]=min(low[x],dfn[e[i].to]);
			else
			{
				Tarjan(e[i].to,x);
				low[x]=min(low[x],low[e[i].to]);
				if (low[e[i].to]>dfn[x])
				{
					cut[x].insert(e[i].to);
					cut[e[i].to].insert(x);
				}
			}
		}
	return ;
}

inline int dfs(int x,int f)
{
	int cc=0;
	for (int i=headg[x];~i;i=g[i].nxt)
		if (g[i].to!=f)
		{
			int t=dfs(g[i].to,x);
			cc+=t;ans+=1LL*abs(t)*g[i].val;
		}
	return cc+cntt[x];
}

int main()
{
	scanf("%d",&TT);
	while (TT--)
	{
		T=0;ans=0;cnt=0;cnt2=0;
		memset(dfn,0,sizeof dfn);memset(low,0,sizeof low);
		memset(head,-1,sizeof head);memset(headg,-1,sizeof headg);
		memset(cntt,0,sizeof cntt);
		scanf("%d %d",&n,&m);
		for (int i=1;i<=n;i++) cut[i].clear(),f[i]=i;
		scanf("%s",a+1);
		for (int i=1;i<=m;i++)
		{
			scanf("%d %d %d",&u,&v,&w);
			add(u,v,w);
		}
		Tarjan(1,-1);
		for (int i=1;i<=n;i++)
			for (int j=head[i];~j;j=e[j].nxt)
				if (!cut[i].count(e[j].to))
				{
					int fx=getf(i),fy=getf(e[j].to);
					if (fx!=fy) f[fy]=fx;
				}
		for (int i=1;i<=n;i++)
			for (int j=head[i];~j;j=e[j].nxt)
				if (getf(i)!=getf(e[j].to))
					addedge(getf(i),getf(e[j].to),e[j].val);
		for (int i=1;i<=n;i++)
		{
			if (a[i]=='A') cntt[getf(i)]++;
			if (a[i]=='H') cntt[getf(i)]--;
		}
		dfs(getf(1),-1);
		printf("%lld\n",ans);
	}
	return 0;
}