#include <bits/stdc++.h>
using namespace std;

int n,a[1001],mx,mn=~(1<<31);

int main()
{
	int ans=~(1<<31),pans=0;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		mn=min(mn,a[i]);
		mx=max(mx,a[i]);
	}
	for (int i=mn;i<=mx;i++)
	{
		int cnt=0;
		for (int j=1;j<=n;j++)
			if (abs(i-a[j])>1)
			{
				if (a[j]>i) cnt+=a[j]-i-1;
				else cnt+=i-a[j]-1;
			}
		if (cnt<ans)
		{
			ans=cnt;
			pans=i;
		}
	}
	printf("%d %d\n",pans,ans);
	return 0;
}