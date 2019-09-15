#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=2e5+10,MAXM=1e6+10;
const int INF=~(1<<31),MOD=1e9+7;

ll a[MAXN];
ll dp[MAXN],f[MAXN];

int main()
{
	int t,n,m;
	scanf("%d",&t);
	for(int kase=1;kase<=t;kase++)
	{
		memset(dp,0,sizeof(dp));
		scanf("%d",&n);
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			sum+=a[i];
		}
		sort(a+1,a+n+1);
		ll ans=0;
		dp[0]=1;
		for(int i=n;i>=1;i--)
		{
			memset(f,0,sizeof(f));
			for(int j=(sum+1)/2+a[n];j>=a[i];j--)
			{
				(dp[j]+=dp[j-a[i]])%=MOD;
				(f[j]+=dp[j-a[i]])%=MOD;
			}
			for(int j=(sum+1)/2;j*2>=sum&&j*2<=sum+a[i];j++)
				(ans+=f[j])%=MOD;
		}
		printf("%lld\n",ans);
	}
	return 0;
}