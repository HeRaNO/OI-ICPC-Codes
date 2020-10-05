#include <bits/stdc++.h>
using namespace std;

int main()
{
	int cas=0,n;
	while (scanf("%d",&n)==1&&n)
	{
		double ans=0;
		for (int i=1;i<=n;i++)
		{
			int c,b,l,na;
			scanf("%d %d %d %d",&c,&b,&l,&na);
			double kc=c/85.0,kb=b/85.0,kl=l/85.0;
			double p=c*0.8+b*1.0+l*1.2+na*0.8;
			double q=kc*7.5+kb*24+kl*32+(kc+kb+kl)*8+na*0.2;
			ans+=p-q;
		}
		printf("Case #%d: RM%.2lf\n",++cas,ans);
	}
	return 0;
}
