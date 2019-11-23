#include <bits/stdc++.h>
#define MAXN 1005
using namespace std;

int T,n,m;
pair <int,int> a[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&n,&m);int ans=0;
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&a[i].first);
			a[i].second=i;
			ans+=a[i].first;
		}
		if (m<n||n==2) puts("-1");
		else
		{
			sort(a+1,a+n+1);
			printf("%d\n",(ans<<1)+(m-n)*(a[1].first+a[2].first));
			for (int i=1;i<n;i++)
				printf("%d %d\n",a[i].second,a[i+1].second);
			printf("%d %d\n",a[n].second,a[1].second);
			for (int i=n+1;i<=m;i++)
				printf("%d %d\n",a[1].second,a[2].second);
		}
	}
	return 0;
}