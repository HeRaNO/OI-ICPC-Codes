#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e3+10,MAXM=1e4+10;
const int MOD=1e9+7,INF=~(1<<31);
const ll llINF=1999999999999999999;

int main()
{
	ll a,b;
	while(scanf("%lld%lld",&a,&b)==2)
	{
		ll temp=__gcd(a,b);
		b*=temp;
		ll t=a*a-4*b;
		if(t<0)
		{
			puts("No Solution");
			continue;
		}
		ll tt=sqrt(t);
		if(tt*tt!=t)
		{
			puts("No Solution");
			continue;
		}
		ll x=a+tt,y=a-tt;
		if(x%2||y%2||y<=0)
		{
			puts("No Solution");
			continue;
		}
		printf("%lld %lld\n",y/2,x/2);
	}
	return 0;
}