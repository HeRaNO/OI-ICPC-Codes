#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

int n,cas;
double p,fac[MAXN];

int main()
{
	for (int i=1;i<200005;i++)
		fac[i]=fac[i-1]+log(i);
	while (scanf("%d %lf",&n,&p)==2)
	{
		double ans1=0.0,ans2=0.0;
		for (int i=0;i<n;i++)
		{
			double now=fac[n+i]-fac[i]-fac[n];
			now+=i*log(1.0-p)+(n+1)*log(p);
			ans1+=(n-i)*exp(now);
			now=fac[n+i]-fac[i]-fac[n];
			now+=i*log(p)+(n+1)*log(1.0-p);
			ans2+=(n-i)*exp(now);
		}
		printf("Case %d: %.6lf\n",++cas,ans1+ans2);
	}
	return 0;
}