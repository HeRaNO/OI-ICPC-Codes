#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

struct Link
{
	int u,v,w;
	Link(){}
	Link(int _,int __,int ___):u(_),v(__),w(___){}
};

Link e[MAXN];
long long x[1<<18],lazy[1<<18];
int n,T,R,m,u,v,w;
int in[MAXN],dep[MAXN],siz[MAXN],mx[MAXN],top[MAXN],fa[MAXN];
vector <int> g[MAXN];
char o[10];

inline void dfs1(int x)
{
	siz[x]=1;mx[x]=-1;
	for (auto v:g[x])
		if (v!=fa[x])
		{
			dep[v]=dep[x]+1;fa[v]=x;
			dfs1(v);
			siz[x]+=siz[v];
			if (!~mx[x]||siz[v]>siz[mx[x]]) mx[x]=v;
		}
	return ;
}

inline void dfs2(int x, int t)
{
	top[x]=t;in[x]=R++;
	if (~mx[x]) dfs2(mx[x],t);
	for (auto v:g[x]) if (v!=mx[x]&&v!=fa[x]) dfs2(v,v);
	return ;
}

inline void add(int u,int l,int r,long long v)
{
	x[u]+=(r-l)*v;lazy[u]+=v;
	return ;
}

inline void PushDown(int u,int l,int r)
{
	if (!lazy[u]) return ;
	int m=l+r>>1;
	add(u<<1,l,m,lazy[u]);add(u<<1|1,m,r,lazy[u]);
	lazy[u]=0;return ;
}

inline void modify(int u,int l,int r,int v,int pl,int pr)
{
	if (pl==l&&pr==r){add(u,l,r,v);return ;}
	PushDown(u,pl,pr);int m=pl+pr>>1;
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

inline long long query(int u,int l,int r,int pl,int pr)
{
	if (l==pl&&r==pr) return x[u];
	PushDown(u,pl,pr);int m=pl+pr>>1;
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
	if (in[l]<in[r]) modify(1,in[l]+1,in[r]+1,v,1,n+1);
	return ;
}

inline long long Q(int l,int r)
{
	long long res=0;
	while (top[l]!=top[r])
	{
		if (dep[top[l]]<dep[top[r]]) swap(l,r);
		res+=query(1,in[top[l]],in[l]+1,1,n+1);
		l=fa[top[l]];
	}
	if (in[l]>in[r]) swap(l,r);
	if (in[l]<in[r]) res+=query(1,in[l]+1,in[r]+1,1,n+1);
	return res;
}

inline void Solve()
{
	scanf("%d %d",&n,&m);R=1;
	memset(x,0,sizeof x);memset(lazy,0,sizeof lazy);
	for (int i=1;i<=n;i++) g[i].clear();
	for (int i=1;i<n;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		g[u].push_back(v);g[v].push_back(u);
		e[i]=Link(u,v,w);
	}
	dfs1(1);dfs2(1,1);
	for (int i=1;i<n;i++) C(e[i].u,e[i].v,e[i].w);
	while (m--)
	{
		scanf("%s %d %d",o,&u,&v);
		if (o[0]=='A')
		{
			scanf("%d",&w);
			C(u,v,w);
		}
		else printf("%lld\n",Q(u,v));
	}
	return ;
}

int main()
{
	scanf("%d",&T);
	while (T--) Solve();
	return 0;
}