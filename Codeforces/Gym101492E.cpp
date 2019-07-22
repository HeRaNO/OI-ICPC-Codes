#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

int n;
long long a[MAXN],ans;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	if (n==1) return printf("%lld\n",a[1]),0;
	if (n&1)
	{
		ans+=a[1]+a[2]+a[3];
		for (int i=5;i<=n;i+=2)
			ans+=min(a[1]+a[i]+a[2]*2,a[1]*2+a[i]+a[i-1]);
	}
	else
	{
		ans+=a[2];
		for (int i=4;i<=n;i+=2)
			ans+=min(a[1]+a[i]+a[2]*2,a[1]*2+a[i]+a[i-1]);
	}
	printf("%lld\n",ans);
	return 0;
}