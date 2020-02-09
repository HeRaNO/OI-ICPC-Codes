#include <bits/stdc++.h>
#define MAXN 105
using namespace std;

int T,n,a[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);int ne=0,po=0,ans=0;
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=1;i<=n;i++)
		{
			if (a[i]<0) ne-=a[i];
			if (a[i]>0) po+=a[i];
			if (!a[i]) ++ans,++po;
		}
		printf("%d\n",ans+(ne==po));
	}
	return 0;
}
