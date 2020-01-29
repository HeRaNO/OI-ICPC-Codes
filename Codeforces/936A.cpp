#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x.begin(),x.end())
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef double db;
const int MAXN=6e5+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;

int main()
{
	ll k,d,t;
	cin>>k>>d>>t;
	d*=(k+d-1)/d;
	t*=2;
	ll q=k+d;
	ll ans=t/q;
	db res=0;
	if(t-ans*q>k*2)
	{
		res=ans*d;
		res+=(t-k-ans*q);
	}
	else res=ans*d+((db)t-ans*q)/2;
	printf("%.8lf",res);
	return 0;
}