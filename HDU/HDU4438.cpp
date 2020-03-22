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

int n;

void solve()
{
	ll x,y;
	double p,q;
	scanf("%lld%lld%lf%lf",&x,&y,&p,&q);
	double ans1=0,ans2=0;
	ans1+=q*p*(x+y)+(1-q)*x;
	ans2+=p*(1-q)*(x+y)+(q)*y;
	if(ans1>=ans2)
	{
		printf("tiger %.4lf\n",ans1);
	}
	else printf("wolf %.4lf\n",ans2);
	return;
}

int main()
{
	int t,kase=0;
	scanf("%d",&t);
	while(t--)
	{
		solve();
	}
	return 0;
}