#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

int T,n,a[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);bool f=false;
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=1;i<n&&!f;i++)
			if (abs(a[i]-a[i+1])>=2)
			{
				puts("YES");
				printf("%d %d\n",i,i+1);
				f=true;
			}
		if (!f) puts("NO");
	}
	return 0;
}