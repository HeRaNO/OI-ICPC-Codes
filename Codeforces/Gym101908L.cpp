#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int n,T,R=1,u,v,a,b;
int in[MAXN],top[MAXN],fa[MAXN],dep[MAXN],siz[MAXN],mx[MAXN];
int x[1<<18],lazy[1<<18];
vector <int> g[MAXN];

inline void dfs1(int x)
{
	siz[x]=1;mx[x]=-1;
	for (auto v:g[x])
		if (fa[x]!=v)
		{
			fa[v]=x;dep[v]=dep[x]+1;
			dfs1(v);
			siz[x]+=siz[v];
			if (!~mx[x]||siz[mx[x]]<siz[v]) mx[x]=v;
		}
	return ;
}

inline void dfs2(int x,int t)
{
	in[x]=R++;top[x]=t;
	if (~mx[x]) dfs2(mx[x],t);
	for (auto v:g[x]) if (v!=fa[x]&&v!=mx[x]) dfs2(v,v);
	return ;
}

inline void add(int u,int l,int r,int v)
{
	x[u]+=(r-l)*v;lazy[u]+=v;
	return ;
}

inline void PushDown(int u,int l,int r)
{
	if (!lazy[u]) return ;
	int m=l+r>>1;
	add(u<<1,l,m,lazy[u]);add(u<<1|1,m,r,lazy[u]);lazy[u]=0;
	return ;
}

inline void modify(int u,int l,int r,int v,int pl,int pr)
{
	if (l==pl&&r==pr){add(u,l,r,v);return ;}
	int m=pl+pr>>1;PushDown(u,pl,pr);
	if (r<=m) modify(u<<1,l,r,v,pl,m);
	else if (m<=l) modify(u<<1|1,l,r,v,m,pr);
	else
	{
		modify(u<<1,l,m,v,pl,m);
		modify(u<<1|1,m,r,v,m,pr);
	}
	x[u]=x[u<<1]+x[u<<1|1];
	return ;
}

inline int query(int u,int l,int r,int pl,int pr)
{
	if (l==pl&&r==pr) return x[u];
	int m=pl+pr>>1;PushDown(u,pl,pr);
	if (r<=m) return query(u<<1,l,r,pl,m);
	else if (m<=l) return query(u<<1|1,l,r,m,pr);
	else return query(u<<1,l,m,pl,m)+query(u<<1|1,m,r,m,pr);
}

inline void C(int l,int r,int v)
{
	while (top[l]!=top[r])
	{
		if (dep[top[l]]<dep[top[r]]) swap(l,r);
		modify(1,in[top[l]],in[l]+1,v,1,n+1);
		l=fa[top[l]];
	}
	if (in[l]>in[r]) swap(l,r);
	modify(1,in[l],in[r]+1,v,1,n+1);
	return ;
}

inline int Q(int l,int r)
{
	int res=0;
	while (top[l]!=top[r])
	{
		if (dep[top[l]]<dep[top[r]]) swap(l,r);
		res+=query(1,in[top[l]],in[l]+1,1,n+1);
		l=fa[top[l]];
	}
	if (in[l]>in[r]) swap(l,r);
	res+=query(1,in[l],in[r]+1,1,n+1);
	return res;
}

int main()
{
	scanf("%d %d",&n,&T);
	for (int i=1;i<n;i++)
	{
		scanf("%d %d",&u,&v);
		g[u].push_back(v);g[v].push_back(u);
	}
	dfs1(1);dfs2(1,1);
	while (T--)
	{
		scanf("%d %d %d %d",&u,&v,&a,&b);
		C(u,v,1);
		printf("%d\n",Q(a,b));
		C(u,v,-1);
	}
	return 0;
}