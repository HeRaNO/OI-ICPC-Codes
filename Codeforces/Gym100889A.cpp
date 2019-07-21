#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;

int T,n,a[MAXN],ans;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);ans=0;
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for (int i=1;i<=n/2;i++) ans+=a[n+1-i]-a[i];
		printf("%d\n",ans);
	}
	return 0;
}