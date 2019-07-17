#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int n,T,x,y,a[MAXN],ans,g,l;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d %d",&n,&x,&y);ans=0;g=-1;l=-1;
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		if (y%x){puts("-1");continue;}
		if (n==1)
		{
			if (x!=y) puts("-1");
			else
			{
				if (y!=a[1]) puts("1");
				else puts("0");
			}
			continue;
		}
		for (int i=1;i<=n;i++)
		{
			if (a[i]%x||y%a[i]) ++ans;
			else
			{
				if (!~g) g=a[i];
				else g=__gcd(a[i],g);
				if (!~l) l=y/a[i];
				else l=__gcd(l,y/a[i]);
			}
		}
		int p=0;
		if (l!=1) ++p;
		if (g!=x) ++p;
		if (ans>=p) printf("%d\n",ans);
		else printf("%d\n",p<=n?p:-1);
	}
	return 0;
}