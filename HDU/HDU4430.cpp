#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
ll n,k,ans,ansr,ansk;

inline bool check(ll r,ll x)
{
	ll ji=1,sum=0;
	for(int i=1;i<=r;++i)
	{
		ji*=x;
		sum+=ji;
	}
	if(sum==n-1||sum==n)
	{
		if(ans>r*x)
		{
			ans=r*x;
			ansr=r;
			ansk=x;
		}
	}
	if(sum>n)return true;
	else return false;
}

ll r;
void solve()
{
	ans=LLONG_MAX;
	for(int i=1;i<=40;++i)
	{
		ll L=1,R=pow(n,1.0/i),res=-1;
		while(L<=R)
		{
			ll mid=(L+R)>>1;
			if(check(i,mid))R=mid-1,res=R;
			else L=mid+1;
		}
	}
	printf("%lld %lld\n",ansr,ansk);
}

int main()
{
	while(scanf("%lld",&n)==1)solve();
	return 0;
}