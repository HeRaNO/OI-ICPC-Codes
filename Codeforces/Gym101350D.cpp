#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

int T,n,a[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);bool f=true;
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for (int i=2;i<=n&&f;i++) if ((a[i]-a[i-1])&1) f=false;
		puts(f?"yes":"no");
	}
	return 0;
}