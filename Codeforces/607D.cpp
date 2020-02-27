#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

const long long M=1e9+7;

long long x[1<<19],lazy[1<<19];
int n,m,q,o,a[MAXN],v[MAXN],fa[MAXN],in[MAXN],out[MAXN],s[MAXN],T=1;
vector <int> g[MAXN];

inline long long inv(long long a)
{
	long long r=1,b=M-2;
	for (;b;b>>=1,(a*=a)%=M) if (b&1) (r*=a)%=M;
	return r;
}

inline void dfs(int x)
{
	in[x]=T++;
	for (auto v:g[x]) dfs(v);
	out[x]=T;
	return ;
}

inline void BuildTree(int u,int l,int r)
{
	lazy[u]=1;if (l+1==r) return ;
	int m=l+r>>1;BuildTree(u<<1,l,m);BuildTree(u<<1|1,m,r);
	return ;
}

inline void mul(int u,long long v)
{
	(x[u]*=v)%=M;(lazy[u]*=v)%=M;return ;
}

inline void PushDown(int u)
{
	if (lazy[u]!=1) mul(u<<1,lazy[u]),mul(u<<1|1,lazy[u]),lazy[u]=1;
	return ;
}

inline void modify(int u,int p,int v,int pl,int pr)
{
	if (pl+1==pr){x[u]=v;return ;}
	int m=pl+pr>>1;PushDown(u);
	if (p<m) modify(u<<1,p,v,pl,m);
	else modify(u<<1|1,p,v,m,pr);
	x[u]=x[u<<1]+x[u<<1|1];if (x[u]>=M) x[u]-=M;
	return ;
}

inline void mult(int u,int l,int r,long long v,int pl,int pr)
{
	if (l==pl&&r==pr){mul(u,v);return ;}
	PushDown(u);int m=pl+pr>>1;
	if (r<=m) mult(u<<1,l,r,v,pl,m);
	else if (m<=l) mult(u<<1|1,l,r,v,m,pr);
	else
	{
		mult(u<<1,l,m,v,pl,m);
		mult(u<<1|1,m,r,v,m,pr);
	}
	x[u]=x[u<<1]+x[u<<1|1];if (x[u]>=M) x[u]-=M;
	return ;
}

inline long long query(int u,int l,int r,int pl,int pr)
{
	if (l==pl&&r==pr) return x[u];
	PushDown(u);int m=pl+pr>>1;
	if (r<=m) return query(u<<1,l,r,pl,m);
	else if (m<=l) return query(u<<1|1,l,r,m,pr);
	else return (query(u<<1,l,m,pl,m)+query(u<<1|1,m,r,m,pr))%M;
}

int main()
{
	scanf("%d %d",&v[n=1],&q);m=1;
	for (int i=1;i<=q;i++)
	{
		scanf("%d %d",&o,&a[i]);
		if (o==1)
		{
			scanf("%d",&v[++n]);
			fa[n]=a[i];g[a[i]].push_back(n);
		}
		else a[i]=-a[i];
	}
	dfs(1);
	BuildTree(1,1,n+1);modify(1,1,v[1],1,n+1);s[1]=1;
	for (int i=1;i<=q;i++)
	{
		if (a[i]>0)
		{
			++m;
			long long t=query(1,in[fa[m]],in[fa[m]]+1,1,n+1);
			t=t*inv(v[fa[m]])%M*v[m]%M;
			modify(1,in[m],t,1,n+1);
			mult(1,in[fa[m]],out[fa[m]],(s[fa[m]]+1)*inv(s[fa[m]])%M,1,n+1);
			++s[fa[m]];s[m]=1;
		}
		else
		{
			a[i]=-a[i];
			long long t=query(1,in[a[i]],out[a[i]],1,n+1);
			if (a[i]==1) printf("%lld\n",t);
			else
			{
				int f=v[fa[a[i]]]*inv(query(1,in[fa[a[i]]],in[fa[a[i]]]+1,1,n+1))%M;
				printf("%lld\n",t*f%M);
			}
		}
	}
	return 0;
}