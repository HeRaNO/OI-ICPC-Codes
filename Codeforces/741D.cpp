#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(a,b) memset(a,b,sizeof(a))
const int N=500050;
const int inf=0x3f3f3f3f;
inline int idx(char c){return c-'a';}
inline int tr(char c){return 1<<idx(c);}
int n,ans[N];
struct edge
{
	int v;
	int nxt;
	int w;
}e[N];
int head[N],ecnt;
inline void ad(int u,int v,int w)
{
	e[++ecnt].v=v;e[ecnt].nxt=head[u];head[u]=ecnt;
	e[ecnt].w=w;
}
int dep[N],son[N],siz[N],xors[N],p[(1<<22)+5];
void dfs(int u)
{
	siz[u]=1;
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		dep[v]=dep[u]+1;
		xors[v]^=xors[u];
		dfs(v);
		siz[u]+=siz[v];
		if(siz[son[u]]<siz[v])son[u]=v;
	}
}
void upd(int now,int u)
{
	ans[now]=max(ans[now],dep[u]+p[xors[u]]);
	for(int i=0;i<22;++i)
	{
		ans[now]=max(ans[now],dep[u]+p[(1<<i)^xors[u]]);
	}
	for(int i=head[u];i;i=e[i].nxt)
	{
		upd(now,e[i].v);
	}
}

void Undo(int u)
{
	p[xors[u]]=-inf;
	for(int i=head[u];i;i=e[i].nxt)Undo(e[i].v);
}

void Insert(int u)
{
	p[xors[u]]=max(p[xors[u]],dep[u]);
	for(int i=head[u];i;i=e[i].nxt)Insert(e[i].v);
}

void Dfs(int u)
{
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v!=son[u])
		{
			Dfs(v);
			Undo(v);
		}
	}
	if(son[u])Dfs(son[u]);
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v!=son[u])
		{
			upd(u,v);
			Insert(v);
		}
	}
	p[xors[u]]=max(p[xors[u]],dep[u]);
	ans[u]=max(ans[u],dep[u]+p[xors[u]]);
	for(int i=0;i<22;++i)
	{
		ans[u]=max(ans[u],dep[u]+p[(1<<i)^xors[u]]);
	}
	ans[u]=ans[u]-(dep[u]<<1);
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		ans[u]=max(ans[u],ans[v]);
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<=(1<<22);++i)p[i]=-inf;
	ecnt=1;
	for(int i=2;i<=n;++i)
	{
		int pp;char c;
		cin>>pp>>c;
		ad(pp,i,tr(c));
		xors[i]=tr(c);
	}
	dfs(1);
	Dfs(1);
	for(int i=1;i<=n;++i)
		printf("%d ",ans[i]);
	return 0;
}
