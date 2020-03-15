#include <bits/stdc++.h>
#define MAXN 500005
#define MAXM 2005
using namespace std;

int T,n,m,o[MAXM],u[MAXM],v[MAXM],k[MAXM];
int w[MAXN],siz[MAXN],top[MAXN],dep[MAXN];
long long a[MAXN];
vector <int> g[MAXN];
bool q[MAXN],bq[MAXN];

inline void add(int u,int v)
{
	g[u].push_back(v);g[v].push_back(u);
	return ;
}

inline void dfs(int x,int fa,int deep)
{
	int cnt=0,pos=0;
	dep[x]=deep;w[x]=x;siz[x]=1;
	for (auto v:g[x])
		if (v!=fa)
		{
			dfs(v,x,deep+1);
			if (q[v])
			{
				q[x]=true;
				++cnt;pos=w[v];
			}
		}
	if (!q[x]) return ;
	if (!bq[x]&&cnt==1)
	{
		if (bq[pos]) top[pos]=x;
		else
		{
			w[x]=pos;++siz[pos];
		}
		return ;
	}
	bq[x]=true;
	for (auto v:g[x]) if (v!=fa&&q[v]) top[w[v]]=x;
	return ;
}

inline void modify(int o,int l,int r,int k)
{
	while (true)
	{
		if (dep[l]<dep[r]) swap(l,r);
		if (o==1) a[l]+=k;
		else if (o==2) a[l]^=k;
		else if (a[l]>k) a[l]-=k;
		if (l==r) break;
		l=top[l];
	}
	return ;
}

inline long long query(int o,int l,int r,int k)
{
	long long res=0,mx=1LL<<63,mn=~(1LL<<63);
	while (true)
	{
		if (dep[l]<dep[r]) swap(l,r);
		if (o==4) res+=a[l]*siz[l];
		else if (o==5) res^=(siz[l]&1)?a[l]:0;
		else if (o==6){mx=max(mx,a[l]);mn=min(mn,a[l]);res=mx-mn;}
		else{mn=min(mn,abs(a[l]-k));res=mn;}
		if (l==r) break;
		l=top[l];
	}
	return res;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&n,&m);
		memset(a,0,sizeof a);memset(q,0,sizeof q);memset(bq,0,sizeof bq);
		for (int i=1;i<=n;i++) g[i].clear();
		for (int i=1,x,y;i<n;i++) scanf("%d %d",&x,&y),add(x,y);
		for (int i=1;i<=m;i++)
		{
			scanf("%d %d %d",&o[i],&u[i],&v[i]);
			if (!(o[i]>=4&&o[i]<=6)) scanf("%d",&k[i]);
			q[u[i]]=q[v[i]]=true;
			bq[u[i]]=bq[v[i]]=true;
		}
		dfs(1,-1,0);
		for (int i=1;i<=m;i++)
		{
			if (o[i]<=3) modify(o[i],u[i],v[i],k[i]);
			else printf("%lld\n",query(o[i],u[i],v[i],k[i]));
		}
	}
	return 0;
}