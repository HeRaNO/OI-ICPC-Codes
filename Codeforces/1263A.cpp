#include <bits/stdc++.h>
using namespace std;

int T,a[4],ans;

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		for (int i=1;i<=3;i++) scanf("%d",&a[i]);
		sort(a+1,a+4);ans=a[1];
		int t=a[3]-a[2];a[3]-=min(a[1],t);
		if (a[1]>t)
		{
			a[1]-=t;
			a[2]-=((a[1]+1)>>1);
		}
		ans+=min(a[3],a[2]);
		printf("%d\n",ans);
	}
	return 0;
}