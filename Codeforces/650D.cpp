#include <bits/stdc++.h>
#define MAXN 400005
using namespace std;

int n,m,C,L,a[MAXN],x[MAXN],y[MAXN],f[MAXN],g[MAXN],dp[MAXN];
pair <int,int*> b[MAXN<<1];
int ans,cnt[MAXN];

int binary1(int x)
{
	int l=0,r=ans,m;
	while (l<r)
	{
		m=l+r>>1;
		if (dp[m]<x) l=m+1;
		else r=m;
	}
	return l;
}

int binary2(int x)
{
	int l=0,r=ans,m;
	while (l<r)
	{
		m=l+r>>1;
		if (dp[m]<=x) r=m;
		else l=m+1;
	}
	return l;
}

inline void goLIS()
{
	ans=0;dp[0]=-1;
	for (int i=1;i<=n;i++)
	{
		if (a[i]>dp[ans]) dp[f[i]=++ans]=a[i];
		else dp[f[i]=binary1(a[i])]=a[i];
	}
	L=ans;dp[ans=0]=~(1<<31);
	for (int i=n;i;i--)
	{
		if (a[i]<dp[ans]) dp[g[i]=++ans]=a[i];
		else dp[g[i]=binary2(a[i])]=a[i];
	}
	for (int i=1;i<=n;i++) if (f[i]+g[i]==L+1) ++cnt[f[i]];
	return ;
}

struct node
{
	int ls,rs,x;
}tr[MAXN*45];

int rt[2][MAXN],tot;

int add(int x,int now,int v,int pl,int pr)
{
	int p=++tot;
	tr[p]=tr[now];tr[p].x=max(tr[p].x,v);
	if (pl==pr) return p;int m=pl+pr>>1;
	if (x<=m) tr[p].ls=add(x,tr[p].ls,v,pl,m);
	else tr[p].rs=add(x,tr[p].rs,v,m+1,pr);
	return p;
}

int qmin(int u,int v,int pl,int pr)
{
	if (pl==pr) return tr[u].x;
	int m=pl+pr>>1;
	if (v<=m) return qmin(tr[u].ls,v,pl,m);
	return max(tr[tr[u].ls].x,qmin(tr[u].rs,v,m+1,pr));
}

int qmax(int u,int v,int pl,int pr)
{
	if (pl==pr) return tr[u].x;
	int m=pl+pr>>1;
	if (v>m) return qmax(tr[u].rs,v,m+1,pr);
	return max(tr[tr[u].rs].x,qmax(tr[u].ls,v,pl,m));
}

int main()
{
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]={a[i],&a[i]};
	goLIS();
	for (int i=1;i<=m;i++)
	{
		scanf("%d %d",&x[i],&y[i]);
		b[i+n]={y[i],&y[i]};
	}
	sort(b+1,b+n+m+1);
	for (int i=1;i<=n+m;i++)
	{
		if (b[i].first!=b[i-1].first) ++C;
		*b[i].second=C;
	}
	for (int i=1;i<=n;i++) rt[0][i]=add(a[i],rt[0][i-1],f[i],1,C);
	for (int i=n;i;i--) rt[1][i]=add(a[i],rt[1][i+1],g[i],1,C);
	for (int i=1;i<=m;i++)
	{
		int ans1=L;if (f[x[i]]+g[x[i]]==L+1&&cnt[f[x[i]]]<=1) --ans1;
		int al=y[i]==1?0:qmin(rt[0][x[i]-1],y[i]-1,1,C);
		int ar=y[i]==C?0:qmax(rt[1][x[i]+1],y[i]+1,1,C);
		printf("%d\n",max(ans1,al+ar+1));
	}
	return 0;
}