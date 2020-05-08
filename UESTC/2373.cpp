#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

const int M=170001;

int x[1<<18],lazy[1<<18];
int n,m,R=1,o,u,v,w,a[MAXN];
int in[MAXN],pos[MAXN],top[MAXN],fa[MAXN],dep[MAXN],siz[MAXN],mx[MAXN];
vector <int> g[MAXN];

inline void fassign(int &x,int y){x=y;if (x>=M) x-=M;return ;}
inline int fadd(int &x,int y){x+=y;if (x>=M) x-=M;return x;}

inline void add(int u,int v)
{
	g[u].push_back(v);g[v].push_back(u);
	return ;
}

inline void dfs1(int x)
{
	siz[x]=1;mx[x]=-1;
	for (auto v:g[x])
		if (fa[x]!=v)
		{
			fa[v]=x;dep[v]=dep[x]+1;dfs1(v);
			siz[x]+=siz[v];
			if (!~mx[x]||siz[mx[x]]<siz[v]) mx[x]=v;
		}
	return ;
}

inline void dfs2(int x,int t)
{
	in[x]=R;pos[R++]=x;top[x]=t;
	if (~mx[x]) dfs2(mx[x],t);
	for (auto v:g[x]) if (v!=fa[x]&&v!=mx[x]) dfs2(v,v);
	return ;
}

inline void BuildTree(int u,int l,int r)
{
	if (l+1==r){x[u]=a[pos[l]];return ;}
	int m=l+r>>1;BuildTree(u<<1,l,m);BuildTree(u<<1|1,m,r);
	fassign(x[u],x[u<<1]+x[u<<1|1]);
	return ;
}

inline void add(int u,int l,int r,int v)
{
	fadd(x[u],1LL*(r-l)*v%M);
	fadd(lazy[u],v);
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
	PushDown(u,pl,pr);int m=pl+pr>>1;
	if (r<=m) modify(u<<1,l,r,v,pl,m);
	else if (m<=l) modify(u<<1|1,l,r,v,m,pr);
	else
	{
		modify(u<<1,l,m,v,pl,m);
		modify(u<<1|1,m,r,v,m,pr);
	}
	fassign(x[u],x[u<<1]+x[u<<1|1]);
	return ;
}

inline int query(int u,int l,int r,int pl,int pr)
{
	if (l==pl&&r==pr) return x[u];
	PushDown(u,pl,pr);int m=pl+pr>>1;
	if (r<=m) return query(u<<1,l,r,pl,m);
	else if (m<=l) return query(u<<1|1,l,r,m,pr);
	int res=0;
	fassign(res,query(u<<1,l,m,pl,m)+query(u<<1|1,m,r,m,pr));
	return res;
}

inline void C(int x,int y,int v)
{
	while (top[x]!=top[y])
	{
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
		modify(1,in[top[x]],in[x]+1,v,1,n+1);
		x=fa[top[x]];
	}
	if (in[x]>in[y]) swap(x,y);
	modify(1,in[x],in[y]+1,v,1,n+1);
	return ;
}

inline int Q(int x,int y)
{
	int res=0;
	while (top[x]!=top[y])
	{
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
		fadd(res,query(1,in[top[x]],in[x]+1,1,n+1));
		x=fa[top[x]];
	}
	if (in[x]>in[y]) swap(x,y);
	fadd(res,query(1,in[x],in[y]+1,1,n+1));
	return res;
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
	read(n);read(m);
	for (int i=1;i<=n;i++) read(a[i]),a[i]%=M;
	for (int i=1;i<n;i++) read(u),read(v),add(u,v);
	dfs1(1);dfs2(1,1);BuildTree(1,1,n+1);
	while (m--)
	{
		read(o);read(u);read(v);
		if (o==1) read(w),C(u,v,w);
		else printf("%d\n",Q(u,v));
	}
	return 0;
}