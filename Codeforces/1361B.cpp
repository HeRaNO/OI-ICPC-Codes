#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;

const long long MOD=1e9+7;

int T,n,p,a[MAXN];

inline long long fpow(long long a,long long b)
{
	long long r=1;
	for (;b;b>>=1,(a*=a)%=MOD) if (b&1) (r*=a)%=MOD;
	return r;
}

inline long long qpow(long long r,long long a,long long b)
{
	if (!r) return 0;
	while (b)
	{
		if (b&1) r*=a;
		if (a>1e6||r>1e6) return -1;
		a*=a;b>>=1;
	}
	if (r>1e6) return -1;
	return r;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&n,&p);long long now=0;bool f=false;
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1,greater<int>());a[n+1]=0;
		for (int i=1;i<=n&&!f;i++)
		{
			for (;a[i]==a[i+1]&&i<n;i++) now<=0?++now:--now;
			now<=0?++now:--now;
			long long r=qpow(now,p,a[i]-a[i+1]);
			if (!~r)
			{
				long long ans=fpow(p,a[i])*now%MOD;
				for (int j=i+1;j<=n;j++)
					ans=(ans-fpow(p,a[j])+MOD)%MOD;
				printf("%lld\n",ans);
				f=true;
			}
			now=r;
		}
		if (!f) printf("%lld\n",now);
	}
	return 0;
}