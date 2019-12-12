#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=2e5+10,MAXM=3e6+10;
const int INF=INT_MAX,MOD=1e9+7,mod=998244353;

int n;
int a[MAXN];
int dp[MAXN][2];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	dp[1][0]=dp[1][1]=1;
	for(int i=2;i<=n;i++)
		if(a[i]>a[i-1])dp[i][0]=dp[i-1][0]+1;
		else dp[i][0]=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]>a[i-1])dp[i][1]=max(dp[i][1],dp[i-1][1]+1);
		else dp[i][1]=max(dp[i][1],1);
		if(a[i]>a[i-2])dp[i][1]=max(dp[i-2][0]+1,dp[i][1]);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans,max(dp[i][0],dp[i][1]));
	cout<<ans;
	return 0;
}