#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
#define lowbit(x) x&-x
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const int MAXN=6e5+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=998244353,mod=998244353;
const int Lim=(1<<19);

ll n,a[MAXN],c,t;

bool check(ll m)
{
	ll tmp=c,now=0;
	for(int i=1;i<=n;i++)
	{
		if(now<a[i])
		{
			now=t*m;
			tmp--;
		}
		if(now<a[i])return false;
		now-=a[i];
	}
	return tmp>=0;
}

int main()
{
	scanf("%lld%lld%lld",&n,&c,&t);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	ll l=0,r=1e9,ans=1e9;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans;
	return 0;
}
