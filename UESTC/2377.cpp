#include <bits/stdc++.h>
#define MAXN 1000005
#define MAXM 100005
using namespace std;

struct node
{
	int l,r,ls,rs,x;
}tr[MAXN*45];

int n,m,o,v,w,x,y,a[MAXN];
int rt[MAXM],tot;

int build(int ll,int rr)
{
	int p=++tot;tr[p].l=ll;tr[p].r=rr;
	if (ll==rr){tr[p].x=a[ll];return p;}
	int m=ll+rr>>1;
	tr[p].ls=build(ll,m);tr[p].rs=build(m+1,rr);
	return p;
}

int modify(int u,int x,int v)
{
	int p=++tot;tr[p]=tr[u];
	if (tr[p].l==tr[p].r){tr[p].x=v;return p;}
	int m=tr[p].l+tr[p].r>>1;
	if (x<=m) tr[p].ls=modify(tr[p].ls,x,v);
	else tr[p].rs=modify(tr[p].rs,x,v);
	return p;
}

int query(int u,int x)
{
	if (tr[u].l==tr[u].r) return tr[u].x;
	int m=tr[u].l+tr[u].r>>1;
	if (x<=m) return query(tr[u].ls,x);
	else return query(tr[u].rs,x);
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
	for (int i=1;i<=n;i++) read(a[i]);
	rt[v]=build(1,n);
	while (m--)
	{
		read(o);read(w);read(x);
		if (o==1) read(y),rt[++v]=modify(rt[w],x,y);
		else printf("%d\n",query(rt[w],x));
	}
	return 0;
}