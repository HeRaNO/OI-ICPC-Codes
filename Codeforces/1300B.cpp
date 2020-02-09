#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

int T,n,a[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n*2;i++) scanf("%d",&a[i]);
		sort(a+1,a+n*2+1);
		printf("%d\n",a[n+1]-a[n]);
	}
	return 0;
}