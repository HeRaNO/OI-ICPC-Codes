#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;

int T,n,a[MAXN],b[MAXN],c;
long long ans;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);a[0]=a[n+1]=c=0;ans=0;
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=1;i<=n;i++) b[i]=a[i-1]<a[i]?b[i-1]+1:1;
		for (int i=n;i;i--) ans+=max(b[i],a[i+1]<a[i]?(++c):(c=1));
		printf("%lld\n",ans);
	}
	return 0;
}