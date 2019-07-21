#include <bits/stdc++.h>
#define MAXN 21
using namespace std;

int T,n,m,k,x[MAXN],y[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d %d",&n,&m,&k);
		for (int i=0;i<k;i++) scanf("%d %d",&x[i],&y[i]);
		long long ans=1LL*(n+1)*n/2*(m+1)*m/2;
		for (int i=1;i<(1<<k);i++)
		{
			int mxx=-1,mxy=-1,mnx=n+1,mny=m+1;
			for (int j=0;j<k;j++)
				if (i&(1<<j))
				{
					mxx=max(mxx,x[j]);mnx=min(mnx,x[j]);
					mxy=max(mxy,y[j]);mny=min(mny,y[j]);
				}
			long long now=1LL*mnx*(n-mxx+1)*mny*(m-mxy+1);
			if (__builtin_popcount(i)&1) ans-=now;
			else ans+=now;
		}
		printf("%lld\n",ans);
	}
	return 0;
}