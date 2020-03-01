#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
const int N=200050;
ll k;int n;
int dp[N];
int pre[N];
ll a[N],b[N],suma[N],sumb[N];

int main()
{
	int Test;cin>>Test;
	while(Test--)
	{
		scanf("%d%lld",&n,&k);
		int ans=inf;
		for(int i=1;i<=n;++i)scanf("%lld",&a[i]),suma[i]=suma[i-1]+a[i];
		for(int i=1;i<=n;++i)scanf("%lld",&b[i]),sumb[i]=sumb[i-1]+b[i];
		memset(dp,inf,(n+5)*sizeof(int));
		memset(pre,0,(n+5)*sizeof(int));
		ans=dp[0];dp[0]=0;
		int j=0;
		for(int i=1;i<=n;++i)
		{
			while(j<i&&(suma[i]-min(suma[j],sumb[j])>=k||sumb[i]-min(suma[j],sumb[j])>=k))j++;
			if(i==j)break;
			pre[i]=j;
			dp[i]=dp[j]+1;
		}
		j=0;
		int pos=0;
		for(int i=0;i<=n;++i)
		{
			if(dp[i]==inf)break;
			ll nowb=sumb[j]-min(suma[i],sumb[i]);
			while(j<n&&nowb<k)j++,nowb+=b[j];
			if(j==n&&nowb<k)break;
			ll nowa=suma[j]-min(suma[i],sumb[i]);
			if(nowa>=k)continue;
			if(dp[i]<ans)
			{
				ans=dp[i];
				pos=i;
			}
		}
		if(ans==inf){puts("-1");continue;}
		printf("%d\n",ans);
		while(pos)
		{
			printf("%d ",pos);
			pos=pre[pos];
		}
		puts("");
	}
	return 0;
}
