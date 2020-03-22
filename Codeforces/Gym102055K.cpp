#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll P=(1LL<<30)+3LL;
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(!b)
	{
		x=1;
		y=0;
		return a;
	}
	ll gcd=exgcd(b,a%b,x,y);
	int p=x;
	x=y;
	y=p-(a/b)*y;
	return gcd;
}
inline ll mi(ll a,ll b,ll mod)
{
	ll ret=1;a%=mod;
	while(b)
	{
		if(b&1)ret*=a,ret%=mod;
		a=a*a,a%=mod;
		b>>=1;
	}
	return ret;
}
inline ll cal_reverse(ll a,ll mod)
{
	ll x,y;
	ll gcd=exgcd(a,mod,x,y);
	if(gcd==1)return (x%mod+mod)%mod;
	else return -1;
}

ll p,q;
inline void fenjie(ll n)
{
	for(ll i=sqrt(n);i;--i)
	{
		if(n%i==0)
		{
			p=i;
			q=n/i;
			return;
		}
	}
}
ll n,c;

int main()
{
	int Test;
	cin>>Test;
	int kase=0;
	while(Test--)
	{
		printf("Case %d: ",++kase);
		scanf("%lld%lld",&n,&c);
		fenjie(n);
		ll rev=cal_reverse(P,(p-1)*(q-1));
		ll pp=mi(c,rev,p);
		ll qq=mi(c,rev,q);
		qq-=pp;qq+=q;qq%=q;
		ll inv=mi(p,q-2,q);
		ll ans=(((qq*inv%q)*p)%n+pp)%n;
		printf("%lld\n",ans);
	}
	return 0;
}
