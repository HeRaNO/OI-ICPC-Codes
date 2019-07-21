#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
 
long long n,a[MAXN],b[MAXN],dp[MAXN][3];
 
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (int i=1;i<=n;i++) scanf("%lld",&b[i]);
	dp[1][0]=a[1];dp[1][1]=b[1];
	for (int i=2;i<=n;i++)
	{
		dp[i][0]=max(dp[i-1][1],dp[i-1][2])+a[i];
		dp[i][1]=max(dp[i-1][0],dp[i-1][2])+b[i];
		dp[i][2]=max(dp[i-1][0],dp[i-1][1]);
	}
	printf("%lld\n",max(dp[n][0],max(dp[n][1],dp[n][2])));
	return 0;
}