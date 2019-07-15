#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;

const int M=998244353;

int n,a[MAXN],dp[MAXN],C[MAXN][MAXN],ans;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	C[0][0]=1;
	for (int i=1;i<=n;i++)
	{
		C[i][0]=C[i][i]=1;
		for (int j=1;j<=i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%M;
	}
	dp[n+1]=1;
	for (int i=n;i;i--)
	{
		if (a[i]<=0) continue;
		for (int j=i+a[i]+1;j<=n+1;j++)
			(dp[i]+=1LL*dp[j]*C[j-i-1][a[i]]%M)%=M;
	}
	for (int i=1;i<=n;i++) (ans+=dp[i])%=M;
	printf("%d\n",ans);
	return 0;
}