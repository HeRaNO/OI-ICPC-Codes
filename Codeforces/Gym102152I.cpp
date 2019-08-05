#include <bits/stdc++.h>
#define MAXN 10010
using namespace std;

int T,n,k,a[MAXN],ans;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&n,&k);ans=0;a[0]=~(1<<31);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);int i;
		for (i=1;i<=n&&k;i++)
		{
			if (a[i]>=0) break;
			a[i]=-a[i];--k;
		}
		if (abs(a[i])>abs(a[i-1])) --i;
		while (k) a[i]=-a[i],--k;
		for (i=1;i<=n;i++) ans+=a[i];
		printf("%d\n",ans);
	}
	return 0;
}