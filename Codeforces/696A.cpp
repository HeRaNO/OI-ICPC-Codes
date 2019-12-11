#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=1e5+10,MAXM=2e6+10;
const int INF=INT_MAX,MOD=1e9+7,mod=998244353;

map<ll,ll> mp;

int getdep(ll u)
{
	int ans=0;
	while(u)
	{
		u>>=1;
		ans++;
	}
	return ans;
}

int main()
{
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int o;
		ll u,v,w;
		scanf("%d",&o);
		if(o==1)
		{
			scanf("%lld%lld%lld",&u,&v,&w);
			if(u<v)swap(u,v);
			int uu=getdep(u),vv=getdep(v);
			while(uu>vv)
			{
				mp[u]+=w;
				u>>=1;
				uu--;
			}
			while(u!=v)
			{
				mp[u]+=w;
				mp[v]+=w;
				u>>=1;
				v>>=1;
			}
		}
		else
		{
			scanf("%lld%lld",&u,&v);
			ll ans=0;
			if(u<v)swap(u,v);
			int uu=getdep(u),vv=getdep(v);
			while(uu>vv)
			{
				ans+=mp[u];
				u>>=1;
				uu--;
			}
			while(u!=v)
			{
				ans+=mp[u];
				ans+=mp[v];
				u>>=1;
				v>>=1;
			}
			printf("%lld\n",ans);
		}
	}
}
