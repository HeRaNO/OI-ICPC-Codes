#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<queue>
using namespace std;
#define ll long long
#define RG register
#define MAX 100005
inline int read()
{
	RG int x=0,t=1;RG char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')t=-1,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	return x*t;
}
struct Line{int v,next;}e[MAX*3];
int h[MAX],cnt=1,n,m;
inline void Add(int u,int v){e[cnt]=(Line){v,h[u]};h[u]=cnt++;}
int dep[MAX],fa[MAX],a[MAX];
int tp[MAX],un[MAX];
void dfs(int u,int ff)
{
	fa[u]=ff;dep[u]=dep[ff]+1;
	for(int i=h[u];i;i=e[i].next)
		if(!dep[e[i].v])dfs(e[i].v,u);
}
void jump(int u,int v){int x=v;while(x!=u)tp[x]=u,un[x]=v,x=fa[x];}
int f0[MAX],f1[MAX],g0[MAX],g1[MAX];
void dp(int u)
{
	f1[u]=a[u];
	if(u!=un[u])g1[u]=a[u];
	for(int i=h[u];i;i=e[i].next)
	{
		int v=e[i].v;if(dep[u]+1!=dep[v])continue;
		dp(v);
		if(un[u]!=un[v])g0[u]+=f1[v],g1[u]+=g0[v];
		else g0[u]+=g1[v],g1[u]+=g0[v];
		if(tp[v]!=u)f0[u]+=f1[v],f1[u]+=f0[v];
		else f0[u]+=f1[v],f1[u]+=g0[v];
	}
	f1[u]=max(f1[u],f0[u]);
	g1[u]=max(g1[u],g0[u]);
}
int main()
{
	freopen("independent.in","r",stdin);
	freopen("independent.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read();
		Add(u,v);Add(v,u);
	}
	dfs(1,0);
	for(int u=1;u<=n;++u)
		for(int i=h[u];i;i=e[i].next)
			if(dep[u]<dep[e[i].v]&&fa[e[i].v]!=u)
				jump(u,e[i].v);
	dp(1);
	printf("%d\n",f1[1]);
	return 0;
}