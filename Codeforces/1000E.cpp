#include <bits/stdc++.h>
#define MAXN 300010
#define MAXM 300010
#define fi first
#define se second
using namespace std;

struct link
{
	int to,nxt;
};

link e[MAXM<<1],g[MAXN<<1];
int head[MAXN],cnt,headg[MAXN],cnt2,scc_cnt;
int n,m,T,S,u,v,ans,dfn[MAXN],low[MAXN],sta[MAXN],top,bel[MAXN];
int dep[MAXN],p;
pair <int,int> a[MAXN];

inline void add(int u,int v)
{
	a[++p]=make_pair(u,v);
	e[cnt]=(link){v,head[u]};head[u]=cnt++;
	e[cnt]=(link){u,head[v]};head[v]=cnt++;
}

inline void addedge(int u,int v)
{
	g[cnt2]=(link){v,headg[u]};headg[u]=cnt2++;
	g[cnt2]=(link){u,headg[v]};headg[v]=cnt2++;
}

inline void Tarjan(int x,int f)
{
	dfn[x]=low[x]=++T;sta[++top]=x;
	for (int i=head[x];~i;i=e[i].nxt)
	{
		if (e[i].to==f) continue;
		if (dfn[e[i].to]) low[x]=min(low[x],dfn[e[i].to]);
		else
		{
			Tarjan(e[i].to,x);
			low[x]=min(low[x],low[e[i].to]);
		}
	}
	if (dfn[x]==low[x])
	{
		int t;scc_cnt++;
		do
		{
			t=sta[top--];
			bel[t]=scc_cnt;
		}
		while (t!=x);
	}
	return ;
}

void dfs(int x,int f)
{
	for (int i=headg[x];~i;i=g[i].nxt)
		if (g[i].to!=f) dep[g[i].to]=dep[x]+1,dfs(g[i].to,x);
	return ;
}

inline void read(int &x)
{
	x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return ;
}

int main()
{
	memset(head,-1,sizeof head);memset(headg,-1,sizeof headg);
	read(n);read(m);
	for (int i=1;i<=m;i++){read(u);read(v);add(u,v);}
	Tarjan(1,0);
	for (int i=1;i<=m;i++) if (bel[a[i].fi]!=bel[a[i].se]) addedge(bel[a[i].fi],bel[a[i].se]);
	dep[S=1]=0;dfs(1,0);
	for (int i=1;i<=scc_cnt;i++) if (dep[i]>dep[S]) S=i;
	dep[S]=0;dfs(S,0);
	for (int i=1;i<=scc_cnt;i++) ans=max(ans,dep[i]);
	printf("%d\n",ans);
	return 0;
}