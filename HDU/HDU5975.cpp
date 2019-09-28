#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e3+10,MAXM=1e4+10;
const int MOD=1e9+7,INF=~(1<<31);
const ll llINF=1999999999999999999;
#define lowbit(x) x&-x

ll getnum(ll x)
{
	ll ans=0,base=1;
	ans+=x;
	while(x)
	{
		x>>=1;
		ans+=x*base;
		base<<=1;
	}
	return ans;
}

int main()
{
	ll n,m;
	while(scanf("%lld%lld",&n,&m)==2)
	{
		for(int i=1;i<=m;i++)
		{
			int op;
			scanf("%d",&op);
			if(op==2)
			{
				ll ans=0,x;
				scanf("%lld",&x);
				while(x<=n)
				{
					ans++;
					x+=lowbit(x);
				}
				printf("%lld\n",ans);
			}
			else
			{
				ll l,r;
				scanf("%lld%lld",&l,&r);
				printf("%lld\n",getnum(r)-getnum(l-1));
			}
		}
	}
	return 0;
}