// Solution with time complexity O(m ln^2 n)
// Method: Segment Tree Beats!
// Author: HeRaNO
#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int mn[1<<18],se[1<<18],lazy[1<<18];
int n,m,T,ans[MAXN],t[MAXN],x[MAXN],mxX[MAXN],ori[MAXN];
pair <int,int*> b[MAXN];

inline void BuildTree(int u,int l,int r)
{
	lazy[u]=mn[u]=0;se[u]=~(1<<31);
	if (l+1==r) return ;
	int m=l+r>>1;BuildTree(u<<1,l,m);BuildTree(u<<1|1,m,r);
	return ;
}

inline void tag(int u,int v)
{
	if (v<=mn[u]) return ;
	mn[u]=lazy[u]=v;return ;
}

inline void PushUp(int u)
{
	int ls=u<<1,rs=u<<1|1;
	if (mn[ls]==mn[rs])
	{
		mn[u]=mn[ls];
		se[u]=min(se[ls],se[rs]);
	}
	else if (mn[ls]<mn[rs])
	{
		mn[u]=mn[ls];
		se[u]=min(se[ls],mn[rs]);
	}
	else
	{
		mn[u]=mn[rs];
		se[u]=min(mn[ls],se[rs]);
	}
	return ;
}

inline void PushDown(int u)
{
	if (!lazy[u]) return ;
	tag(u<<1,lazy[u]);tag(u<<1|1,lazy[u]);
	return ;
}

inline void changemax(int u,int l,int r,int v,int pl,int pr)
{
	if (v<=mn[u]) return ;
	if (pl==l&&pr==r&&v<se[u]){tag(u,v);return ;}
	if (pl+1==pr) return ;
	int m=pl+pr>>1;PushDown(u);
	if (r<=m) changemax(u<<1,l,r,v,pl,m);
	else if (m<=l) changemax(u<<1|1,l,r,v,m,pr);
	else
	{
		changemax(u<<1,l,m,v,pl,m);
		changemax(u<<1|1,m,r,v,m,pr);
	}
	PushUp(u);
	return ;
}

inline void dfs(int u,int l,int r)
{
	if (l+1==r){ans[l]=mn[u];return ;}
	int m=l+r>>1;PushDown(u);
	dfs(u<<1,l,m);dfs(u<<1|1,m,r);
	return ;
}

inline void Solve(int cas)
{
	scanf("%d %d",&n,&m);T=0;
	for (int i=1;i<=n;i++) scanf("%d %d",&t[i],&x[i]),b[i]={t[i],&t[i]};
	sort(b+1,b+n+1);
	for (int i=1;i<=n;i++)
	{
		if (b[i].first!=b[i-1].first) ori[++T]=b[i].first;
		*b[i].second=T;
	}
	BuildTree(1,1,m+1);
	for (int i=1;i<=T;i++) mxX[i]=0;
	for (int i=1;i<=n;i++) mxX[t[i]]=max(mxX[t[i]],x[i]);
	for (int i=1;i<=T;i++)
		for (int k=0,t=ori[i];2*k*t+1<=m;k++)
			changemax(1,2*k*t+1,min((2*k+1)*t,m)+1,mxX[i],1,m+1);
	dfs(1,1,m+1);
	printf("Case #%d:",cas);
	for (int i=1;i<=m;i++) printf(" %d",ans[i]);
	puts("");
	return ;
}

int main()
{
	int T;scanf("%d",&T);
	for (int i=1;i<=T;i++) Solve(i);
	return 0;
}