#include <bits/stdc++.h>
#define MAXN 105
using namespace std;

int T,n,a[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for (int i=n;i;i--) printf("%d%c",a[i],i==1?'\n':' ');
	}
	return 0;
}