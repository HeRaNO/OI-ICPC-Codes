#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=0x7fffffff,MAXM=2e6+10,MAXN=5e5+10;
const int MOD=1e9+7;
const ll llINF=~(1ll<<63);
const ll mod=998244353;

ll n,m,k;

ll getinv(ll x)
{
	ll p=mod-2,ans=1;
	x%=mod;
	while(p)
	{
		if(p&1)(ans*=x)%=mod;
		(x*=x)%=mod;
		p>>=1;
	}
	return ans;
}

ll a[MAXM];

int main()
{
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)scanf("%lld",&a[i]);
	sort(a+1,a+m+1);
	a[m+1]=n+1;
	int l=1;
	ll ans=0;
	for(int i=1;i<=m;i++)
	{
		if(i-l+1==k)
		{
			(ans+=(a[l]-a[l-1])*(a[i+1]-a[i])%mod)%=mod;
			l++;
		}
	}
	if(!k)
	{
		ans=0;
		for(int i=1;i<=m+1;i++)
			(ans+=((a[i]-a[i-1]-1)*(a[i]-a[i-1])/2)%mod)%=mod;
	}
	ll inv=getinv(n*(n+1)/2)%mod;
	(ans*=inv)%=mod;
	printf("%lld",ans);
	return 0;
}