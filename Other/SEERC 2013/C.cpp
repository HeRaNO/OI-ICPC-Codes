#include <bits/stdc++.h>
#define MAXN 10001
using namespace std;

int n,m,l,r,a[MAXN][MAXN];

int main()
{
	//freopen("c.in","r",stdin);
	fread(&n,4,1,stdin);fread(&m,4,1,stdin);
	//printf("n=%d m=%d\n",n,m);
	for (int i=0;i<n;i++) fread(a[i],4,m,stdin);
	while (fread(&l,4,1,stdin))
	{
		fread(&r,4,1,stdin);int ans=0;
		//printf("l=%d r=%d\n",l,r);
		for (int i=0;i<n;i++)
		{
			if (a[i][0]>r) break;
			int ll=lower_bound(a[i],a[i]+m,l)-a[i];
			int rr=upper_bound(a[i],a[i]+m,r)-a[i];
			//printf("i=%d ll=%d rr=%d\n",i,ll,rr);
			if (rr<=ll) continue;
			ans+=rr-ll;
		}
		printf("%d\n",ans);
	}
	return 0;
}