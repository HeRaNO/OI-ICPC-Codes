#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x.begin(),x.end())
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const int MAXN=6e5+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=998244353,mod=998244353;
const int Lim=1<<20;

ll n,a[MAXN],b[MAXN];
ll dp[3005][3005];

int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)b[i]=(a[i]-=i);
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)
	{
		ll minn=llINF;
		for(int j=1;j<=n;j++)
		{
			minn=min(minn,dp[i-1][j]);
			dp[i][j]=minn+abs(a[i]-b[j]);
		}
	}
	ll ans=llINF;
	for(int i=1;i<=n;i++)ans=min(ans,dp[n][i]);
	cout<<ans;
	return 0;
}