#include <bits/stdc++.h>
using namespace std;

int n,a[200010],pa[200010],pb[200010],qa[200010],qb[200010];
int ans;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	{
		if (i&1) pa[i]=pa[i-1]+a[i];
		else pa[i]=pa[i-1];
		if (!(i&1)) pb[i]=pb[i-1]+a[i];
		else pb[i]=pb[i-1];
	}
	for (int i=n;i;i--)
	{
		if (i&1) qa[i]=qa[i+1]+a[i];
		else qa[i]=qa[i+1];
		if (!(i&1)) qb[i]=qb[i+1]+a[i];
		else qb[i]=qb[i+1];
	}
	for (int i=1;i<=n;i++)
		if (pa[i-1]+qb[i+1]==pb[i-1]+qa[i+1]) ++ans;
	printf("%d\n",ans);
	return 0;
}
