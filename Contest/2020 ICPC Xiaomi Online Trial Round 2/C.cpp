#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

const int M=1000000007;
int n,m;
long long a[MAXN],b[MAXN],sum[MAXN];
long long mx[1<<19],x[1<<19],lazy[1<<19];

inline void BuildTree(int u,int l,int r)
{
	lazy[u]=0;
	if (l+1==r)
	{
		mx[u]=a[l]+sum[l+1];
		x[u]=b[l];
		return ;
	}
	int m=l+r>>1;BuildTree(u<<1,l,m);BuildTree(u<<1|1,m,r);
	mx[u]=max(mx[u<<1],mx[u<<1|1]);
	x[u]=x[u<<1]+x[u<<1|1];
	return ;
}

inline void PushDown(int u)
{
	if (!lazy[u]) return ;
	mx[u<<1]+=lazy[u];mx[u<<1|1]+=lazy[u];
	lazy[u<<1]+=lazy[u];lazy[u<<1|1]+=lazy[u];
	lazy[u]=0;return ;
}

inline void modifyA(int u,int p,long long v,int pl,int pr)
{
	if (pl+1==pr)
	{
		mx[u]+=v-a[p];
		a[p]=v;
		return ;
	}
	int m=pl+pr>>1;PushDown(u);
	if (p<m) modifyA(u<<1,p,v,pl,m);
	else modifyA(u<<1|1,p,v,m,pr);
	mx[u]=max(mx[u<<1],mx[u<<1|1]);
	x[u]=x[u<<1]+x[u<<1|1];
	return ;
}

inline void modifyB(int u,int l,int r,long long v,int pl,int pr)
{
	if (pl==l&&pr==r)
	{
		mx[u]+=v;lazy[u]+=v;
		return ;
	}
	int m=pl+pr>>1;PushDown(u);
	if (r<=m) modifyB(u<<1,l,r,v,pl,m);
	else if (m<=l) modifyB(u<<1|1,l,r,v,m,pr);
	else
	{
		modifyB(u<<1,l,m,v,pl,m);
		modifyB(u<<1|1,m,r,v,m,pr);
	}
	mx[u]=max(mx[u<<1],mx[u<<1|1]);
	x[u]=x[u<<1]+x[u<<1|1];
	return ;
}

inline void modifyBA(int u,int p,long long v,int pl,int pr)
{
	if (pl+1==pr)
	{
		x[u]=v;
		return ;
	}
	int m=pl+pr>>1;PushDown(u);
	if (p<m) modifyBA(u<<1,p,v,pl,m);
	else modifyBA(u<<1|1,p,v,m,pr);
	mx[u]=max(mx[u<<1],mx[u<<1|1]);
	x[u]=x[u<<1]+x[u<<1|1];
	return ;
}

inline long long query(int u,int l,int r,int pl,int pr)
{
	if (l==pl&&r==pr) return mx[u];
	int m=pl+pr>>1;PushDown(u);
	if (r<=m) return query(u<<1,l,r,pl,m);
	else if (m<=l) return query(u<<1|1,l,r,m,pr);
	else return max(query(u<<1,l,m,pl,m),query(u<<1|1,m,r,m,pr));
}

inline long long querysuf(int u,int l,int r,int pl,int pr)
{
	if (l==pl&&r==pr) return x[u];
	int m=pl+pr>>1;PushDown(u);
	if (r<=m) return querysuf(u<<1,l,r,pl,m);
	else if (m<=l) return querysuf(u<<1|1,l,r,m,pr);
	else return querysuf(u<<1,l,m,pl,m)+querysuf(u<<1|1,m,r,m,pr);
}

int main()
{
	while (scanf("%d %d",&n,&m)==2)
	{
		for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
		for (int i=1;i<=n;i++) scanf("%lld",&b[i]);
		sum[n+1]=0;
		for (int i=n;~i;i--) sum[i]=sum[i+1]+b[i];
		BuildTree(1,0,n+1);
		while (m--)
		{
			int o,x,y;
			scanf("%d %d",&o,&x);
			if (o!=3)
			{
				scanf("%d",&y);
				if (o==1) modifyA(1,x,y,0,n+1);
				else if (o==2)
				{
					modifyB(1,0,x,y-b[x],0,n+1);
					modifyBA(1,x,y,0,n+1);
					b[x]=y;
				}
			}
			else
			{
				long long p=query(1,0,x+1,0,n+1),q=0;
				if (x<n) q=querysuf(1,x+1,n+1,0,n+1);
				printf("%lld\n",p-q);
			}
		}
	}
	return 0;
}