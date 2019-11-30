#include <bits/stdc++.h>
#define MAXN 50005
using namespace std;

struct node
{
	int l,r,ls,rs,x;
}tr[MAXN*20];

int n,tot,a[MAXN],occ[1<<15|1],rt[MAXN];
long long ans;

int build(int ll,int rr)
{
	int p=++tot;tr[p].l=ll;tr[p].r=rr;
	if (ll==rr) return p;
	int m=ll+rr>>1;
	tr[p].ls=build(ll,m);tr[p].rs=build(m+1,rr);
	return p;
}

int add(int x,int now)
{
	int p=++tot;tr[p]=tr[now];++tr[p].x;
	if (tr[p].l==tr[p].r) return p;
	int m=tr[p].l+tr[p].r>>1;
	if (x<=m) tr[p].ls=add(x,tr[p].ls);
	else tr[p].rs=add(x,tr[p].rs);
	return p;
}

int query(int u,int ll,int rr)
{
	if (tr[u].l==ll&&tr[u].r==rr) return tr[u].x;
	int m=tr[u].l+tr[u].r>>1;
	if (rr<=m) return query(tr[u].ls,ll,rr);
	else if (ll>m) return query(tr[u].rs,ll,rr);
	else return query(tr[u].ls,ll,m)+query(tr[u].rs,m+1,rr);
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
	read(n);rt[0]=build(1,1<<15);
	for (int i=1;i<=n;i++)
	{
		read(a[i]);++occ[a[i]];
		rt[i]=add(a[i],rt[i-1]);
	}
	for (int i=1;i<=(1<<15);i++) occ[i]+=occ[i-1];
	for (int i=2;i<n;i++)
	{
		if (a[i]==1) continue;
		int sma=query(rt[i-1],1,a[i]-1);
		int lar=occ[a[i]-1]-query(rt[i],1,a[i]-1);
		ans+=1LL*sma*lar;
	}
	printf("%lld\n",ans);
	return 0;
}