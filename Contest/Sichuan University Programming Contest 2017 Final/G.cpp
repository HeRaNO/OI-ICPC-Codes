#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int T,n,m,u[MAXN],v[MAXN],in[MAXN],a[MAXN];
long long ans;
vector <int> g[MAXN];

inline bool cmp(int x,int y)
{
	return in[x]!=in[y]?in[x]>in[y]:x<y;
}

inline long long f(int x)
{
	return 1LL*x*(x-1)/2;
}

unordered_map<long long,int> mp;

inline void Solve()
{
	mp.clear();
	scanf("%d %d",&n,&m);ans=0;
	for (int i=1;i<=n;i++) g[i].clear(),in[i]=0,a[i]=0;
	for (int i=1;i<=m;i++)
	{
		scanf("%d %d",&u[i],&v[i]);
		++in[u[i]];++in[v[i]];
	}
	for (int i=1;i<=m;i++)
		if (cmp(u[i],v[i])) g[u[i]].push_back(v[i]);
		else g[v[i]].push_back(u[i]);
	for (int i=1;i<=n;i++)
	{
		for (int j:g[i]) a[j]=i;
		for (int j:g[i])
		{
			for (int k:g[j]) if (a[k]==i)
			{
				long long u=i,v=j,w=k;
				if(u>v)swap(u,v);
				if(v>w)swap(v,w);
				if(u>v)swap(u,v);
				if(v>w)swap(v,w);
				mp[u*100000000+v]++;
				mp[u*100000000+w]++;
				mp[v*100000000+w]++;
			}
		}
	}
	for(auto j:mp)
	{
		ans+=f(j.second);
	}
	printf("%lld\n",ans);
	return ;
}

int main()
{
	//freopen("input.txt","r",stdin);
	scanf("%d",&T);
	while (T--) Solve();
	return 0;
}