#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

int n,m,ans,x,y,T,a[MAXN],c[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);c[0]=ans=0;
		for (int i=1;i<=n;i++) scanf("%d",&a[i]),c[i]=0;
		scanf("%d",&m);
		for (int i=1;i<=m;i++) scanf("%d %d",&x,&y),c[y]=max(c[y],x);
		for (int i=n-1;i;i--) c[i]=max(c[i+1],c[i]);
		for (int i=1;i<=n&&~ans;)
		{
			++ans;
			int j=i,mx=0;
			while (true)
			{
				mx=max(mx,a[j]);
				if (mx>c[j-i+1]) break;
				++j;
			}
			if (j==i) ans=-1;
			i=j;
		}
		printf("%d\n",ans);
	}
	return 0;
}