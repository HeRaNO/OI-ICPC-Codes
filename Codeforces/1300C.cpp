#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int T,n,a[MAXN],p;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=30;~i;i--)
	{
		p=0;
		for (int j=1;j<=n;j++)
			if (a[j]&(1<<i))
			{
				if (!p) p=j;
				else p=-1;
			}
		if (p>=1) break;
	}
	if (~p) swap(a[p],a[1]);
	for (int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ');
	return 0;
}