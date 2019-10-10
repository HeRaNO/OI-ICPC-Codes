#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int T,n,r,a[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&r);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);a[n+1]=0;
		sort(a+1,a+n+1);
		int ans=0,t=0;
		for (int i=n;i>=1;i--)
		{
			if (a[i]==a[i+1]) continue;
			if (a[i]>t){t+=r;++ans;}
		}
		printf("%d\n",ans);
	}
	return 0;
}