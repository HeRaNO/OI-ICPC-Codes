#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,x,odd=0,even=0;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if (x&1) ++odd;
		else ++even;
	}
	if (odd==even) printf("%d\n",n);
	else if (odd>even)
	{
		int t=odd-even,ans=even<<1;
		if (t%3==0) ans+=t/3*2;
		if (t%3==1) ans+=t/3*2-1;
		if (t%3==2) ans+=t/3*2+1;
		printf("%d\n",ans);
	}
	else printf("%d\n",odd<<1|1);
	return 0;
}