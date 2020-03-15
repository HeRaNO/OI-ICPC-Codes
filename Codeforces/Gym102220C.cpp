#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
#define lowbit(x) x&-x
#define pb push_back
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)>>1)
typedef long long ll;
typedef pair<ll,ll> pii;
typedef double db;
const int MAXN=5e5+10,MAXM=2e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
const int inv2=5e8+4;

map<pii,int> mp;
map<pair<ll,pii>,int>mp1;

ll n;
ll ans;

void solve()
{
	ans=0;
	mp.clear();
	mp1.clear();
	scanf("%lld",&n);
	ans=1ll*n*(n-1)/2;
	for(int i=1;i<=n;i++)
	{
		ll x1,y1,x2,y2;
		scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
		if(x1>x2)
		{
			swap(x1,x2);
			swap(y1,y2);
		}
		if(x1==x2&&y1>y2)
		{
			swap(y1,y2);
		}
		ll y=y2-y1;
		ll x=x2-x1;
		ll g=__gcd(abs(y),abs(x));
		ll c=x2*y1-x1*y2;
		y/=g;
		x/=g;
		if(x2-x1)c/=(x2-x1);
		else c/=(y2-y1);
		ans-=mp[{x,y}];
		ans+=mp1[{x,{y,c}}];
		mp[{x,y}]++;
		mp1[{x,{y,c}}]++;
	}
	printf("%lld\n",ans);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		solve();
	}
	return 0;
}
