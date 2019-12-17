#include <bits/stdc++.h>
using namespace std;

int n,k;
long long ans;

int main()
{
	scanf("%d %d",&n,&k);ans=1LL*n*k;
	for (int l=1,r=0;l<=n;l=r+1)
	{
		if (k/l) r=min(n,k/(k/l));
		else r=n;
		ans-=1LL*(k/l)*(r-l+1)*(l+r)>>1;
	}
	printf("%lld\n",ans);
	return 0;
}