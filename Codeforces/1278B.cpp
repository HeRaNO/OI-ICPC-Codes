#include <bits/stdc++.h>
using namespace std;

int T,a,b,lim,p[100000];

int main()
{
	for (int i=1;;i++)
	{
		p[i]=p[i-1]+i;
		if (p[i]>2e9)
		{
			lim=i;break;
		}
	}
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&a,&b);
		if (a>b) swap(a,b);
		int x=b-a;
		int ans=lower_bound(p,p+lim,x)-p;
		while ((p[ans]-x)%2!=0) ++ans;
		printf("%d\n",ans);
	}
	return 0;
}