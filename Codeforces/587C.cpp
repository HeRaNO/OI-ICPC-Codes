#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int t[21];

struct Data
{
	int n,x[11];
	Data(){n=0;}
	Data merge(const Data &a,const int &v)const{
		Data res;
		int i=1,j=1,pos=1;
		while (i<=n&&j<=a.n) 
		{
			if (x[i]<a.x[j]) t[pos++]=x[i++];
			else t[pos++]=a.x[j++];
		}
		while (i<=n) t[pos++]=x[i++];
		while (j<=a.n) t[pos++]=a.x[j++];
		res.n=min(n+a.n,v);
		for (int i=1;i<=res.n;i++) res.x[i]=t[i];
		return res;
	}
	void push_back(int p){if (n<10) x[++n]=p;return ;}
}res;

int pos[MAXN],top[MAXN],fa[MAXN];
int in[MAXN],dep[MAXN],siz[MAXN],mx[MAXN];
int n,m,q,R=1,u,v,p;
Data x[1<<18];
vector <int> g[MAXN],a[MAXN];

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

inline void dfs2(int x,int t)
{
	top[x]=t;pos[R]=x;in[x]=R++;
	if (~mx[x]) dfs2(mx[x],t);
	for (auto v:g[x]) if (v!=mx[x]&&v!=fa[x]) dfs2(v,v);
	return ;
}

inline void BuildTree(int u,int l,int r)
{
	if (l+1==r)
	{
		for (auto p:a[pos[l]]) x[u].push_back(p);
		return ;
	}
	int m=l+r>>1;BuildTree(u<<1,l,m);BuildTree(u<<1|1,m,r);
	x[u]=x[u<<1].merge(x[u<<1|1],10);
	return ;
}

inline void query(int u,int l,int r,int v,int pl,int pr)
{
	if (l==pl&&r==pr)
	{
		res=res.merge(x[u],v);
		return ;
	}
	int m=pl+pr>>1;
	if (r<=m) query(u<<1,l,r,v,pl,m);
	else if (m<=l) query(u<<1|1,l,r,v,m,pr);
	else
	{
		query(u<<1,l,m,v,pl,m);
		query(u<<1|1,m,r,v,m,pr);
	}
	return ;
}

inline void C(int l,int r,int a)
{
	res.n=0;
	while (top[l]!=top[r])
	{
		if (dep[top[l]]<dep[top[r]]) swap(l,r);
		query(1,in[top[l]],in[l]+1,a,1,n+1);
		l=fa[top[l]];
	}
	if (in[l]>in[r]) swap(l,r);
	query(1,in[l],in[r]+1,a,1,n+1);
	printf("%d",res.n);
	for (int i=1;i<=res.n;i++) printf(" %d",res.x[i]);
	puts("");
	return ;
}

int main()
{
	scanf("%d %d %d",&n,&m,&q);
	for (int i=1;i<n;i++)
	{
		scanf("%d %d",&u,&v);
		g[u].push_back(v);g[v].push_back(u);
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%d",&u);
		a[u].push_back(i);
	}
	dfs1(1);dfs2(1,1);
	BuildTree(1,1,n+1);
	while (q--)
	{
		scanf("%d %d %d",&u,&v,&p);
		C(u,v,p);
	}
	return 0;
}