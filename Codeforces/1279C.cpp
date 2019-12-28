#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int T,n,m,r,x,a[MAXN],c[MAXN];
long long ans;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&n,&m);r=0;ans=0;
		for (int i=1;i<=n;i++) c[i]=0;
		for (int i=1;i<=n;i++) scanf("%d",&a[i]),c[a[i]]=i;
		for (int i=1;i<=m;i++)
		{
			scanf("%d",&x);
			if (c[x]>r) ans+=2*(c[x]-i)+1,r=c[x];
			else ++ans;
		}
		printf("%lld\n",ans);
	}
	return 0;
}