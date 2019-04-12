#include <bits/stdc++.h>
using namespace std;

int n;
long long a[20],ans=1<<63;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (int l=1;l<=n;l++)
		for (int r=l;r<=n;r++)
		{
			long long s=1;
			for (int i=l;i<=r;i++) s*=a[i];
			ans=max(ans,s);
		}
	if (ans<=0) printf("-1\n");
	else printf("%lld\n",ans);
	return 0;
}
