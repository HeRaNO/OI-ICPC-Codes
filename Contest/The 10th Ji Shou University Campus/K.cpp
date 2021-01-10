#include <bits/stdc++.h>
using namespace std;

int n,m,a[1005];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&m);
	for (int i=1,x;i<=m;i++)
	{
		scanf("%d",&x);
		int nowp=a[x];
		int mx=0,sum=0;
		for (int j=1;j<=n;j++)
		{
			sum+=a[j];
			mx=max(mx,a[j]);
		}
		if (5*(mx-nowp)>sum) return puts("BUG"),0;
		--a[x];
	}
	puts("PASS");
	return 0;
}