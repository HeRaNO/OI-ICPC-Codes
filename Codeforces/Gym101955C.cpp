#include <bits/stdc++.h>
#define ll long long
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
int a[55];
ll fac[55];
int n,k;
ll mod;

int main()
{
	int Test;scanf("%d",&Test);
	for(int T=1;T<=Test;++T)
	{
		scanf("%d%d%lld",&n,&k,&mod);
		printf("Case #%d: ",T);
		fac[0]=1;
		for(ll i=1;i<=50;++i)fac[i]=fac[i-1]*i,fac[i]%=mod;
		if(k>=n-1){printf("%lld\n",fac[n]);continue;}
		ll t=fac[k];
		ll t1=(n-k)*(n-k-1);t1%=mod;
		ll t2=(n-k)*k;t2%=mod;
		ll ans=(t*((1+t1+t2)%mod))%mod;
		printf("%lld\n",ans);
	}
	return 0;
}