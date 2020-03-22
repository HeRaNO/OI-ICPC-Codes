#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
ll inv[100050],fac[100050];
inline ll mi(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1)ret*=a,ret%=mod;
		a=a*a,a%=mod;
		b>>=1;
	}
	return ret;
}
ll C(ll n,ll m)
{
	if(n<m)return 0;
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}

ll n,m;
int main()
{
	int Test=1;
	cin>>Test;
	inv[0]=1;fac[0]=1;
	for(int i=1;i<=100000;++i)
	{
		fac[i]=fac[i-1]*i%mod;
		inv[i]=mi(fac[i],mod-2);
	}
	int kase=0;
	while(Test--)
	{
		cin>>n>>m;
		printf("Case %d: ",++kase);
		if(n<3||m<3){puts("0");continue;}
		ll ans=(C(n,3)+C(n,4))%mod;
		ans*=(C(m,3)+C(m,4))%mod;
		ans%=mod;
		printf("%lld\n",ans);
	}
	return 0;
}
