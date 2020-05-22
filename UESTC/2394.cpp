#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

const int Z=1e5;

struct Line
{
	long long k,b;int x;
	Line(){}
	Line(long long _,long long __,int ___):
		k(_),b(__),x(___){}
	long long getY(int x) {
		return k*x+b;
	}
}tr[MAXN<<2];

int ls[MAXN<<2],rs[MAXN<<2],rt[MAXN],tot;
int n,u,v,a[MAXN],b[MAXN],pool[MAXN],top;
long long f[MAXN];
vector <int> g[MAXN];

inline int newnode()
{
	if (top) return pool[top--];
	return ++tot;
}

inline void delnode(int &x)
{
	pool[++top]=x;ls[x]=rs[x]=0;tr[x]=Line(0,0,0);x=0;
	return ;
}

inline void insert(int &x,int l,int r,Line p)
{
	if (!x){tr[x=newnode()]=p;return ;}
	if (p.getY(l)<=tr[x].getY(l)&&p.getY(r)<=tr[x].getY(r))
	{
		tr[x]=p;return ;
	}
	if (p.getY(l)>=tr[x].getY(l)&&p.getY(r)>=tr[x].getY(r)) return ;
	int m=l+r>>1;
	if (p.getY(m)<tr[x].getY(m)) swap(p,tr[x]);
	insert(ls[x],l,m,p);insert(rs[x],m+1,r,p);
	return ;
}

inline int merge(int x,int y,int l,int r)
{
	if (!x||!y) return x+y;
	int m=l+r>>1;
	ls[x]=merge(ls[x],ls[y],l,m);
	rs[x]=merge(rs[x],rs[y],m+1,r);
	insert(x,l,r,tr[y]);delnode(y);
	return x;
}

Line query(int u,int l,int r,int x)
{
	if (l==r) return tr[u];int m=l+r>>1;
	Line k;
	if (x<=m) k=query(ls[u],l,m,x);
	else k=query(rs[u],m+1,r,x);
	return ((!k.x)||(k.getY(x)>tr[u].getY(x)))?tr[u]:k;
}

inline void TreeDP(int x,int fa)
{
	for (auto v:g[x])
		if (v!=fa)
		{
			TreeDP(v,x);
			rt[x]=merge(rt[x],rt[v],0,Z<<1);
		}
	int v=query(rt[x],0,Z<<1,a[x]+Z).x;
	f[x]=f[v]+1LL*b[v]*a[x];
	insert(rt[x],0,Z<<1,Line(b[x],f[x]-1LL*b[x]*Z,x));
	return ;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	for (int i=1;i<n;i++)
	{
		scanf("%d %d",&u,&v);
		g[u].push_back(v);g[v].push_back(u);
	}
	TreeDP(1,-1);
	for (int i=1;i<=n;i++) printf("%lld%c",f[i],i==n?'\n':' ');
	return 0;
}