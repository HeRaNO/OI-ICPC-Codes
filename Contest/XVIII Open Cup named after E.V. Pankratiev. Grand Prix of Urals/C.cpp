#include <bits/stdc++.h>
#define MAXN 200005
#define fi first
#define se second
using namespace std;

int N,n,m,M,T,x,a[MAXN],cnt[MAXN],lit,ecnt;
int lazy[MAXN],d[MAXN],p;
bool f[MAXN];
pair <int,int> e[MAXN];
vector <pair<int,int> > g[MAXN],G[MAXN];

inline void add(int x,int y,int z)
{
	++d[x];++d[y];M+=2;
	g[x].push_back({y,z});g[y].push_back({x,z});
	return ;
}

inline void addG(int x,int y,int z)
{
	if (d[x]>=M&&d[y]>=M)
	{
		G[x].push_back({y,z});G[y].push_back({x,z});
	}
	return ;
}

int main()
{
	scanf("%d %d %d",&N,&m,&T);
	while (N--)
	{
		scanf("%d",&x);
		if (a[n]!=x) a[++n]=x;
	}
	for (int i=1;i<=n;i++) ++cnt[a[i]];
	for (int i=1;i<=n;i++) e[++p]={min(a[i-1],a[i]),max(a[i-1],a[i])};
	sort(e+1,e+p+1);
	for (int i=1,j;i<=p;i=j)
	{
		for (j=i;j<=p&&e[j]==e[i];++j);
		add(e[i].first,e[i].second,j-i);
	}
	M=(int)sqrt(M);
	for (int i=1,j;i<=p;i=j)
	{
		for (j=i;j<=p&&e[j]==e[i];++j);
		addG(e[i].first,e[i].second,j-i);
	}
	while (T--)
	{
		scanf("%d",&x);
		if (f[x])
		{
			lit-=cnt[x];ecnt-=lazy[x];
			if (d[x]<M)
			{
				for (auto v:g[x])
				{
					lazy[v.fi]-=v.se;
					if (d[v.fi]>=M&&f[v.fi]) ecnt-=v.se;
				}
			}
			else
			{
				for (auto v:G[x]) if (f[v.fi]) ecnt-=v.se;
			}
		}
		else
		{
			lit+=cnt[x];ecnt+=lazy[x];
			if (d[x]<M)
			{
				for (auto v:g[x])
				{
					lazy[v.fi]+=v.second;
					if (d[v.fi]>=M&&f[v.fi]) ecnt+=v.se;
				}
			}
			else
			{
				for (auto v:G[x]) if (f[v.fi]) ecnt+=v.se;
			}
		}
		printf("%d\n",lit-ecnt);f[x]^=1;
	}
	return 0;
}