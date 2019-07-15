#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;

int n,a[MAXN],ans;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	n=unique(a+1,a+n+1)-(a+1);
	for (int i=1;i<n;i++)
		for (int j=a[i];j<a[n];j+=a[i])
		{
			int pt=lower_bound(a+i+1,a+n+1,j+a[i])-(a+1);
			ans=max(ans,a[pt]%a[i]);
		}
	printf("%d\n",ans);
	return 0;
}