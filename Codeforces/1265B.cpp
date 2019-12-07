#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

int T,n,a[MAXN],x,l,r;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);l=n+1;r=0;
		for (int i=1;i<=n;i++) scanf("%d",&x),a[x]=i;
		for (int i=1;i<=n;i++)
		{
			l=min(l,a[i]);r=max(r,a[i]);
			if (r-l+1==i) putchar('1');
			else putchar('0');
		}
		putchar('\n');
	}
	return 0;
}