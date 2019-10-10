#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

int T,h,n,a[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&h,&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);a[n+1]=0;
		int ans=0;
		for (int i=1;i<n;i++)
		{
			a[i]=a[i+1]+1;
			if (a[i+2]+2<a[i]){++ans;a[i+1]=a[i+2]+1;}
			else if (a[i+2]+2==a[i]) ++i;
		}
		printf("%d\n",ans);
	}
	return 0;
}