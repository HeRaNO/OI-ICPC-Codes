#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int mx=1<<31,mxd=1<<31,n,x,d,h;
		scanf("%d %d",&n,&x);
		for (int i=1;i<=n;i++)
		{
			scanf("%d %d",&d,&h);
			mx=max(mx,d-h);
			mxd=max(mxd,d);
		}
		if (x<=mxd) puts("1");
		else if (mx<=0) puts("-1");
		else printf("%d\n",(x-mxd+mx-1)/mx+1);
	}
	return 0;
}