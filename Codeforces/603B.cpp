#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N=300050;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
ll p,k;
ll m=1;
inline ll mi(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1)ret*=a,ret%=mod;
		a*=a,a%=mod;
			b>>=1;
	}
	return ret;
}

int main()
{
	cin>>p>>k;
	if(k==0)return cout<<mi(p,p-1)<<endl,0;
	if(k==1)return cout<<mi(p,p)<<endl,0;
	ll x=k;
	while(x!=1)
	{
		m++;
		x*=k,x%=p;
	}
	cout<<mi(p,p/m)<<endl;
	return 0;
}
