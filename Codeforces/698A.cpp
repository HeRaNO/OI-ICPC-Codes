#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x.begin(),x.end())
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const int MAXN=2e5+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=119;
const int Lim=1<<20;

int dp[MAXN][3],a[MAXN];

int main()
{
	int n;
	memset(dp,0x3f,sizeof(dp));
	scanf("%d",&n);
	dp[0][0]=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n+1;i++)
	{
		dp[i][0]=min(min(dp[i-1][1],dp[i-1][2]),dp[i-1][0])+1;
		if(a[i]>=2)dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
		if(a[i]&1)dp[i][2]=min(dp[i-1][0],dp[i-1][1]);
	}
	cout<<dp[n+1][0]-1;
	return 0;
}
