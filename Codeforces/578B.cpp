#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
#define lowbit(x) x&-x
#define pb push_back
#define ls (id<<1)
#define rs (id<<1|1)
#define Rint register int
#define UNI(x) sort(ALL(x)),x.resize(unique(ALL(x))-x.begin())
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
const int MAXN=2e6+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
const int inv2=5e8+4;
const db Pi=acos(-1);

ll a[MAXN];
ll n,k,x;
ll num[MAXN];

int main()
{
	scanf("%lld%lld%lld",&n,&k,&x);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<35;j++)if(1&(a[i]>>j))num[j]++;
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<35;j++)if(1&(a[i]>>j))num[j]--;
		ll tmp=0,tmp1=0;
		for(int j=0;j<35;j++)if(num[j])tmp1|=(1ll<<j);
		tmp=a[i];
		for(int j=1;j<=k;j++)tmp*=x;
		tmp|=tmp1;
		ans=max(ans,tmp);
		for(int j=0;j<35;j++)if(1&(a[i]>>j))num[j]++;
	}
	cout<<ans;
	return 0;
}
