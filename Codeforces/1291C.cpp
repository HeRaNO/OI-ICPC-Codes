#include <bits/stdc++.h>
#define MAXN 3505
using namespace std;

int n,m,k,T,a[MAXN],ans;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d %d",&n,&m,&k);ans=0;
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		if (k>=m-1)
		{
			for (int i=1;i<=m;i++) ans=max(ans,a[i]);
			for (int i=n-m+1;i<=n;i++) ans=max(ans,a[i]);
		}
		else
		{
			for (int i=0;i<=k;i++)
			{
				int t=~(1<<31),l=i,r=k-i;
				for (int j=0;j<=m-k-1;j++)
				{
					int x=j,y=m-k-x-1;
					t=min(t,max(a[l+x+1],a[n-r-y]));
				}
				ans=max(ans,t);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}