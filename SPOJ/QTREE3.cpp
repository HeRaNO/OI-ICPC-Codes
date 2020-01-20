#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

struct link
{
	int to,nxt;
};

link e[MAXN<<1];
int head[MAXN],cnt;
int n,T,R=1,o,u,v;
int in[MAXN],siz[MAXN],mx[MAXN],top[MAXN],dep[MAXN],fa[MAXN];
int x[1<<18];

inline void add(int u,int v)
{
	e[cnt]=(link){v,head[u]};head[u]=cnt++;
	e[cnt]=(link){u,head[v]};head[v]=cnt++;
}

inline void dfs1(int x)
{
	siz[x]=1;mx[x]=-1;
	for (int i=head[x];~i;i=e[i].nxt)
		if (e[i].to!=fa[x])
		{
			fa[e[i].to]=x;dep[e[i].to]=dep[x]+1;
			dfs1(e[i].to);
			siz[x]+=siz[e[i].to];
			if (!~mx[x]||siz[mx[x]]<siz[e[i].to]) mx[x]=e[i].to;
		}
	return ;
}

inline void dfs2(int x,int t)
{
	top[x]=t;in[x]=R++;
	if (~mx[x]) dfs2(mx[x],t);
	for (int i=head[x];~i;i=e[i].nxt)
		if (e[i].to!=mx[x]&&e[i].to!=fa[x])
			dfs2(e[i].to,e[i].to);
	return ;
}

inline void modify(int u,int v,int w,int pl,int pr)
{
	if (pl+1==pr) 
	{
		x[u]=x[u]?0:w;
		return ;
	}
	int m=pl+pr>>1;
	if (v<m) modify(u<<1,v,w,pl,m);
	else modify(u<<1|1,v,w,m,pr);
	if (x[u<<1]) x[u]=x[u<<1];
	else x[u]=x[u<<1|1];
	return ;
}

inline int query(int u,int l,int r,int pl,int pr)
{
	if (pl==l&&pr==r) return x[u];
	int m=pl+pr>>1;
	if (r<=m) return query(u<<1,l,r,pl,m);
	else if (m<=l) return query(u<<1|1,l,r,m,pr);
	else
	{
		int t=query(u<<1,l,m,pl,m);
		if (t) return t;
		return query(u<<1|1,m,r,m,pr);
	}
}

inline int Q(int l,int r=1)
{
	int res=-1,t;
	while (top[l]!=top[r])
	{
		if (dep[top[l]]<dep[top[r]]) swap(l,r);
		t=query(1,in[top[l]],in[l]+1,1,n+1);
		if (t) res=t;
		l=fa[top[l]];
	}
	if (in[l]>in[r]) swap(l,r);
	t=query(1,in[l],in[r]+1,1,n+1);
	if (t) res=t;
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
	memset(head,-1,sizeof head);
	read(n);read(T);
	for (int i=1;i<n;i++) read(u),read(v),add(u,v);
	dfs1(1);dfs2(1,1);
	while (T--)
	{
		read(o);read(u);
		if (!o) modify(1,in[u],u,1,n+1);
		else printf("%d\n",Q(u));
	}
	return 0;
}