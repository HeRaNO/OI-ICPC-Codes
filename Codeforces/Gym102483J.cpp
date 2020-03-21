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
typedef long long ll;
typedef pair<ll,ll> pii;
typedef double db;
const int MAXN=3e6+10,MAXM=2e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
const int inv2=5e8+4;
const double Pi=acos(-1);

ll a[MAXN],ans=0,t=0;
int n;

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%lld",&a[i]);
	sort(a,a+n,greater<ll>());
	ll last=a[1],sum=a[0]-a[1],ans=0,now=1,maxnow=llINF;
	a[n]=-INF;
	if(a[1]==a[0])return printf("%lld",a[0]-a[2]),0;
	for(int i=1;i<n;i++)
	{
		if(a[i]!=a[i+1])
		{
			if(maxnow>=last-a[i])
			{
				ans+=now*(last-a[i]);
				sum-=(now-1)*(last-a[i]);
				now=((int)log2(i))+1;
				if(now>1)maxnow=sum/(now-1);
				last=a[i];
			}
			else break;
		}
	}
	if(now>1)ans+=now*maxnow+sum-maxnow*(now-1);
	else ans+=now*(sum+1);
	cout<<ans;
	return 0;
}
