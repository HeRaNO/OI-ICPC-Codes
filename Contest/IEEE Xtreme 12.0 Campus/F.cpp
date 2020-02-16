#include <bits/stdc++.h>
using namespace std;

double mx,ans,f;int n;

int main()
{
	scanf("%d",&n);
	for (int i=2;i<n;i++)
	{
		if (i&1)
		{
			mx=max(mx,cos((double)(i-2)/2.0));
			f=2.0*sin(i/2.0)*mx+sin(n-i);
		}
		else f=2*sin(i/2)+sin(n-i);
		ans=max(ans,f);
	}
	printf("%.9lf\n",ans);
	return 0;
}