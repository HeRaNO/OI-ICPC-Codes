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

ll a[MAXN];
int n;

int main()
{
	cin>>n;
	for(int i=n;i;i--)scanf("%lld",&a[i]);
	sort(a+1,a+n+1,greater<ll>());
	for(int i=1;i<=n;i++)
	{
		if(a[i]<0)
		{
			cout<<a[i];
			return 0;
		}
		ll p=sqrt(a[i]);
		if(p*p==a[i])continue;
		cout<<a[i];
		return 0;
	}
	return 0;
}
