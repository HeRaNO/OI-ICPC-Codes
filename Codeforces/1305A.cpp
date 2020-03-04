#include <bits/stdc++.h>
using namespace std;

int T,n,a[105],b[105];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=1;i<=n;i++) scanf("%d",&b[i]);
		sort(a+1,a+n+1);sort(b+1,b+n+1);
		for (int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ');
		for (int i=1;i<=n;i++) printf("%d%c",b[i],i==n?'\n':' ');
	}
	return 0;
}