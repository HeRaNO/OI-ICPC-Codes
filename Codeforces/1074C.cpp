#include <bits/stdc++.h>
#define MAXN 300005
using namespace std;

int n,x[MAXN],y[MAXN],mnx=~(1<<31),mny=~(1<<31),mxx=1<<31,mxy=1<<31,ans;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d %d",&x[i],&y[i]);
		mnx=min(mnx,x[i]);mxx=max(mxx,x[i]);
		mny=min(mny,y[i]);mxy=max(mxy,y[i]);
	}
	for (int i=1;i<=n;i++)
	{
		ans=max(ans,abs(mxx-x[i]+mxy-y[i])<<1);
		ans=max(ans,abs(x[i]-mnx+mxy-y[i])<<1);
		ans=max(ans,abs(mxx-x[i]+y[i]-mny)<<1);
		ans=max(ans,abs(x[i]-mnx+y[i]-mny)<<1);
	}
	printf("%d",ans);
	for (int i=4;i<=n;i++) printf(" %d",(mxx-mnx+mxy-mny)<<1);
	putchar('\n');
	return 0;
}