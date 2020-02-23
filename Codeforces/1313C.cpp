#include <bits/stdc++.h>
#define MAXN 500005
using namespace std;

int x[1<<21];
int n,a[MAXN],m[MAXN],now;
long long ans,f[MAXN],g[MAXN];

inline void BuildTree(int u,int l,int r)
{
	if (l+1==r){x[u]=::m[l];return ;}
	int m=l+r>>1;BuildTree(u<<1,l,m);BuildTree(u<<1|1,m,r);
	x[u]=min(x[u<<1],x[u<<1|1]);
	return ;
}

inline void modify(int u,int p,int v,int pl,int pr)
{
	if (pl+1==pr){x[u]=v;return ;}
	int m=pl+pr>>1;
	if (p<m) modify(u<<1,p,v,pl,m);
	else modify(u<<1|1,p,v,m,pr);
	x[u]=min(x[u<<1],x[u<<1|1]);
	return ;
}

inline int ql(int u,int l,int r,int v,int pl,int pr)
{
	if (pl+1==pr) return x[u]<=v?pl:-1;
	if (x[u]>v) return -1;
	int m=pl+pr>>1;
	if (r<=m) return ql(u<<1,l,r,v,pl,m);
	else if (m<=l) return ql(u<<1|1,l,r,v,m,pr);
	else
	{
		int er=ql(u<<1,l,m,v,pl,m);
		if (~er) return er;
		return ql(u<<1|1,m,r,v,m,pr);
	}
}

inline int qr(int u,int l,int r,int v,int pl,int pr)
{
	if (pl+1==pr) return x[u]<=v?pl:-1;
	if (x[u]>v) return -1;
	int m=pl+pr>>1;
	if (r<=m) return qr(u<<1,l,r,v,pl,m);
	else if (m<=l) return qr(u<<1|1,l,r,v,m,pr);
	else
	{
		int rr=qr(u<<1|1,m,r,v,m,pr);
		if (~rr) return rr;
		return qr(u<<1,l,m,v,pl,m);
	}
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&m[i]);
	BuildTree(1,0,n+2);
	for (int i=1;i<=n;i++)
	{
		int pos=qr(1,0,i,m[i],0,n+2);
		if (!~pos||pos==n+1) f[i]=1LL*i*m[i];
		else f[i]=f[pos]+1LL*(i-pos)*m[i];
	}
	for (int i=n;i;i--)
    {
        int pos=ql(1,i+1,n+2,m[i],0,n+2);
        if (!~pos||pos==n+1) g[i]=1LL*(n-i+1)*m[i];
        else g[i]=g[pos]+1LL*(pos-i)*m[i];
    }
    for (int i=1;i<=n;++i)
        if (f[i]+g[i]-m[i]>ans)
        {
            ans=f[i]+g[i]-m[i];
            now=i;
        }
	a[now]=m[now];int mn=a[now];
	for (int i=now-1;i;i--)
	{
		mn=min(mn,m[i]);
		a[i]=mn;
	}
	mn=a[now];
	for (int i=now+1;i<=n;i++)
	{
		mn=min(mn,m[i]);
		a[i]=mn;
	}
	for (int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ');
	return 0;
}