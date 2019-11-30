#include <bits/stdc++.h>
using namespace std;

int n,w,k,h;
long long ans,c;

int main()
{
	scanf("%d %d %d",&n,&w,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&h);
		if (h+c>w)
		{
			ans+=(h+c-w);
			c+=k;
		}
	}
	printf("%lld\n",ans);
	return 0;
}