#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f,MAXN=1e5+10;
const double pi=acos(-1.0);

ll a[MAXN],b[MAXN],c[MAXN];
ll dp[2][105][6000];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(dp,0,sizeof(dp));
		int n;
		scanf("%d",&n);
		int upbound=n*(n+1)/2;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
		}
		int now=1;
		dp[now][1][n]=a[n];
		for(int i=n-1;i>=1;i--)
		{
			now^=1;
			for(int j=n-i;j>=0;j--)
			{
				int u=(2*n+1-j)*j/2,d=(2*i+j+1)*j/2;
				for(int k=d;k<=u;k++)
				{
					dp[now][j][k]=max(dp[now][j][k],dp[now^1][j][k]+max(b[i]*(k-j*i),c[i]*j));
					dp[now][j+1][k+i]=max(dp[now][j+1][k+i],a[i]+dp[now^1][j][k]);
				}
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++)
			for(int k=0;k<=upbound;k++)
			{
				ans=max(ans,dp[now][i][k]);
			}
		printf("%lld\n",ans);
	}
	return 0;
}