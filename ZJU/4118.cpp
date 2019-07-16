#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

int T,n;
long long a[MAXN],s,ans,avg;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);ans=0LL;s=0LL;
		for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
		for (int i=1;i<=n;i++) s+=a[i];
		avg=s/n;
		for (int i=1;i<=n;i++) if (a[i]>avg) ans+=(a[i]-avg);
		printf("%lld\n",ans);
	}
	return 0;
}