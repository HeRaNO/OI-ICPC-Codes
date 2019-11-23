#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353LL;
ll n,m,k;
ll fac[300050];
ll inv[300050];
inline ll mi(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1)ret=ret*a,ret%=mod;
		a=a*a,a%=mod;
		b>>=1;
	}
	return ret%mod;
}
ll ans;

int main()
{
	fac[0]=1;inv[0]=1;
	for(int i=1;i<=300000;++i)
	{
		fac[i]=fac[i-1]*i;
		fac[i]%=mod;
		inv[i]=mi(fac[i],mod-2);
	}
	int Test;scanf("%d",&Test);
	while(Test--)
	{
		scanf("%lld%lld%lld",&n,&m,&k);
		ans=0;
		ll sum=(fac[m+k-1]*inv[k])%mod*inv[m-1]%mod;
		ll flag=-1;
		for(ll i=1;i<=min(k/n,m);++i)
		{
			ll A=(fac[m]*inv[i])%mod*inv[m-i]%mod;
			ll B=(fac[m+k-1-i*n]*inv[m-1])%mod*inv[k-i*n]%mod;
			ll C=(A*B)%mod;
			sum=(sum+flag*C+mod)%mod;
			flag=-flag;
		}
		printf("%lld\n",sum);
	}
	return 0;
}