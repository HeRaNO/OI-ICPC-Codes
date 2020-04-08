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

ll dp[2][MAXN],n,k,l;
ll a[MAXN],b[MAXN];

int upp(int i)
{
	return upper_bound(b,b+n,i)-b-1;
}

int main()
{
	scanf("%lld%lld%lld",&n,&l,&k);
	for(int i=0;i<n;i++)scanf("%lld",&a[i]),b[i]=a[i];
	for(int i=0;i<n;i++)dp[1][i]++;
	sort(b,b+n);
	ll ans=0;
	l--;
	for(int i=0;i<min(k,l/n+1);i++)
	{
		int u=i&1;
		dp[u][0]=0;
		for(int j=0;j<n;j++)
		{
			(dp[u][j]+=dp[u^1][upp(b[j])])%=MOD;
			dp[u][j+1]=dp[u][j];
		}
		(ans+=(l/n-i)%MOD*dp[u][n-1]%MOD)%=MOD;
		for(int j=0;j<=l%n;j++)
		{
			(ans+=dp[u^1][upp(a[j])])%=MOD;
		}
	}
	printf("%lld",ans%MOD);
	return 0;
}
