#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[30][30]=
{
	{66, 390, 1800, 6120, 13680, 15120},
	{390, 3198, 13176, 27000, 13680, 15120},
	{1800, 13176 ,24336, 4320},
	{6120, 27000, 4320, 4320},
	{13680, 13680},
	{15120 ,15120},
};

const int MOD=1e9+7;
ll ksm(ll x,int v)
{
	ll ans=1;
	while(v)
	{
		if(v&1)(ans=ans*x%MOD);
		x=x*x%MOD;
		v>>=1;
	}
	return ans;
}

void solve()
{
	int n,m;
	scanf("%d%d",&n,&m);
	ll ans=ksm(3,n*m);
	if(n==1||m==1)
	{
		printf("%lld\n",0);
		return;
	}
	ll res=0;
	if(n<=10&&m<=10)
	{
		res=a[n-2][m-2];
		printf("%lld\n",(ans-res+MOD)%MOD);
	}
	else printf("%lld\n",ans);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
