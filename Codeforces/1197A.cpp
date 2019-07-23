#include <bits/stdc++.h>
#define MAXN 200010
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
		printf("%d\n",min(a[n-1]-1,n-2));
	}
	return 0;
}