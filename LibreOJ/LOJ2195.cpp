#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

struct Tree
{
	int ls,rs,s,mx;
}tr[MAXN*40];

int n,q,R,tot,w[MAXN],c[MAXN],rt[MAXN],fa[MAXN];
int siz[MAXN],mx[MAXN],in[MAXN],dep[MAXN],top[MAXN];
vector <int> g[MAXN];

void dfs1(int x)
{
	siz[x]=1;mx[x]=-1;
	for (int v:g[x])
		if (v!=fa[x])
		{
			dep[v]=dep[x]+1;fa[v]=x;
			dfs1(v);
			siz[x]+=siz[v];
			if (!~mx[x]||siz[v]>siz[mx[x]]) mx[x]=v;
		}
	return ;
}

void dfs2(int x,int t)
{
	top[x]=t;in[x]=++R;
	if (~mx[x]) dfs2(mx[x],t);
	for (int v:g[x])
		if (v!=mx[x]&&v!=fa[x]) dfs2(v,v);
	return ;
}

void setW(int &u,int x,int w,int pl,int pr)
{
	if (!u) u=++tot;
	if (pl==pr)
	{
		tr[u].s=tr[u].mx=w;
		return ;
	}
	int mid=pl+pr>>1;
	if (x<=mid) setW(tr[u].ls,x,w,pl,mid);
	else setW(tr[u].rs,x,w,mid+1,pr);
	tr[u].s=tr[tr[u].ls].s+tr[tr[u].rs].s;
	tr[u].mx=max(tr[tr[u].ls].mx,tr[tr[u].rs].mx);
	return ;
}

int querySum(int u,int l,int r,int pl,int pr)
{
	if (!u) return 0;
	if (l==pl&&r==pr) return tr[u].s;
	int mid=pl+pr>>1;
	if (r<=mid) return querySum(tr[u].ls,l,r,pl,mid);
	else if (mid<l) return querySum(tr[u].rs,l,r,mid+1,pr);
	else return querySum(tr[u].ls,l,mid,pl,mid)+querySum(tr[u].rs,mid+1,r,mid+1,pr);
}

int queryMax(int u,int l,int r,int pl,int pr)
{
	if (!u) return 0;
	if (l==pl&&r==pr) return tr[u].mx;
	int mid=pl+pr>>1;
	if (r<=mid) return queryMax(tr[u].ls,l,r,pl,mid);
	else if (mid<l) return queryMax(tr[u].rs,l,r,mid+1,pr);
	else return max(queryMax(tr[u].ls,l,mid,pl,mid),queryMax(tr[u].rs,mid+1,r,mid+1,pr));
}

inline int qsum(int c,int l,int r)
{
	int res=0;
	while (top[l]!=top[r])
	{
		if (dep[top[l]]<dep[top[r]]) swap(l,r);
		res+=querySum(rt[c],in[top[l]],in[l],1,n);
		l=fa[top[l]];
	}
	if (in[l]>in[r]) swap(l,r);
	res+=querySum(rt[c],in[l],in[r],1,n);
	return res;
}

inline int qmax(int c,int l,int r)
{
	int res=0;
	while (top[l]!=top[r])
	{
		if (dep[top[l]]<dep[top[r]]) swap(l,r);
		res=max(queryMax(rt[c],in[top[l]],in[l],1,n),res);
		l=fa[top[l]];
	}
	if (in[l]>in[r]) swap(l,r);
	res=max(queryMax(rt[c],in[l],in[r],1,n),res);
	return res;
}

inline void read(int &x)
{
	x=0;char ch=getchar();
	while (ch<'0'||ch>'9')
	{
		if (ch=='C')
		{
			x=getchar()=='C'?0:1;
			return ;
		}
		if (ch=='Q')
		{
			x=getchar()=='S'?2:3;
			return ;
		}
		ch=getchar();
	}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return ;
}

int main()
{
	read(n);read(q);
	for (int i=1;i<=n;i++) read(w[i]),read(c[i]);
	for (int i=2,x,y;i<=n;i++)
	{
		read(x);read(y);
		g[x].push_back(y);g[y].push_back(x);
	}
	dfs1(1);dfs2(1,1);
	for (int i=1;i<=n;i++) setW(rt[c[i]],in[i],w[i],1,n);
	while (q--)
	{
		int o,x,y;read(o);read(x);read(y);
		if (o==0)
		{
			setW(rt[c[x]],in[x],0,1,n);
			c[x]=y;
			setW(rt[c[x]],in[x],w[x],1,n);
		}
		else if (o==1)
		{
			setW(rt[c[x]],in[x],y,1,n);
			w[x]=y;
		}
		else if (o==2)
			printf("%d\n",qsum(c[x],x,y));
		else
			printf("%d\n",qmax(c[x],x,y));
	}
	return 0;
}
