#include <bits/stdc++.h>
using namespace std;

int T;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		int ans=0,a,b,c,p,q,r;
		scanf("%d %d %d",&p,&q,&r);
		a=max(max(p,q),r);c=min(min(p,q),r);b=p+q+r-a-c;
		if (a) ++ans,--a;
		if (b) ++ans,--b;
		if (c) ++ans,--c;
		if (a&&b) ++ans,--a,--b;
		if (a&&c) ++ans,--a,--c;
		if (b&&c) ++ans,--b,--c;
		if (a&&b&&c) ++ans;
		printf("%d\n",ans);
	}
	return 0;
}