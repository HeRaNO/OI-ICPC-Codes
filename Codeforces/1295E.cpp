#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

int n,a[MAXN],p[MAXN],b[MAXN];
long long x[1<<19],lazy[1<<19],c[MAXN],ans=~(1LL<<63);

inline void BuildTree(int u,int l,int r)
{
	if (l+1==r){x[u]=c[l];return ;}
	int m=l+r>>1;BuildTree(u<<1,l,m);BuildTree(u<<1|1,m,r);
	x[u]=min(x[u<<1],x[u<<1|1]);
	return ;
}

inline void add(int u,long long v)
{
	x[u]+=v;lazy[u]+=v;
	return ;
}

inline void PushDown(int u)
{
	if (!lazy[u]) return ;
	add(u<<1,lazy[u]);add(u<<1|1,lazy[u]);
	lazy[u]=0;
	return ;
}

inline void addSeg(int u,int l,int r,int v,int pl,int pr)
{
	if (pl==l&&pr==r) return add(u,v),void();
	int m=pl+pr>>1;PushDown(u);
	if (r<=m) addSeg(u<<1,l,r,v,pl,m);
	else if (m<=l) addSeg(u<<1|1,l,r,v,m,pr);
	else
	{
		addSeg(u<<1,l,m,v,pl,m);
		addSeg(u<<1|1,m,r,v,m,pr);
	}
	x[u]=min(x[u<<1],x[u<<1|1]);
	return ;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&p[i]);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) b[p[i]]=a[i];
	for (int i=1;i<=n;i++) c[i]=c[i-1]+b[i];
	BuildTree(1,0,n+1);
	for (int i=1;i<n;i++)
	{
		addSeg(1,0,p[i],a[i],0,n+1);
		addSeg(1,p[i],n+1,-a[i],0,n+1);
		ans=min(ans,x[1]);
	}
	printf("%lld\n",ans);
	return 0;
}