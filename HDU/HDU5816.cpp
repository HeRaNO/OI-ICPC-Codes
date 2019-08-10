#include <bits/stdc++.h>
typedef long long ll;
const int MAXN=1505;
using namespace std;

int a[25],n,m,p,cnt[(1<<20)+5];
ll fac[25],ans,tot;
ll dp[(1<<20)+5];

bool getans(int x)
{
	int ans=0;
	for(int i=0;i<m;i++)
	{
		if((1<<i)&x)
			ans+=a[i];
	}
	if(ans>=p) return true;
	return false;
}

int _next(int x)
{
	int ans=0;
	for(int i=0;i<m;i++)
	{
		if((1<<i)&x)
			ans++;
	}
	return cnt[x]-2*ans+1;
}

void init()
{
	ans=tot=0;
	memset(dp,0,sizeof(dp));
}

int main()
{
	fac[0]=1;
	for(int i=1;i<=23;i++)
		fac[i]=fac[i-1]*i;
	for(int i=0;i<(1<<20);i++)
		for(int j=0;j<20;j++)
			if((1<<j)&i) cnt[i]++;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		init();
		scanf("%d%d%d",&p,&n,&m);
		for(int i=0;i<m;i++)
			scanf("%d",&a[i]);
		int sum=m+n;
		int maxn=(1<<sum)-1;
		dp[0]=1;
		if(getans(maxn))
		{
			for(int i=0;i<=maxn;i++)
			if(dp[i])
			{
				if(i==maxn||_next(i)==0)
				{
					if(getans(i))
						ans+=fac[sum-cnt[i]]*dp[i];
				}
				else
				{
					for (int j=0;j<sum;j++) if(!((1<<j)&i)) dp[i|(1<<j)]+=dp[i];
				}
			}
		}
		tot=fac[sum];
		ll temp=__gcd(ans,tot);
		tot/=temp;
		ans/=temp;
		printf("%lld/%lld\n",ans,tot);
	}
	return 0;
}