#include <bits/stdc++.h>
#define MAXN 105
using namespace std;

const double pi=acos(-1.0);
const double eps=1e-7;

int n;
double a[MAXN],s,mx;

double check(double r)
{
	r*=2.0;double alpha=0.0;
	for (int i=1;i<=n;i++) alpha+=asin(a[i]/r);
	return alpha*2.0;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%lf",&a[i]);
		s+=a[i];
		mx=max(mx,a[i]);
	}
	for (int i=1;i<=n;i++)
		if (s<=(a[i]*2.0)) return puts("NO CIRCLE"),0;
	if (fabs(check(mx/2.0)-2.0*pi)<eps)
	{
		double ans=mx/2.0;
		if (ans>120.0) puts("TOO BIG");
		else printf("%.4lf\n",ans);
		return 0;
	}
	double l=mx/2.0,r=130;
	for (int i=1;i<=10000;i++)
	{
		double mid=(l+r)/2.0;
		double alpha=2.0*asin(mx/(2.0*mid));
		double beta=check(mid);
		if (beta<alpha+pi)
		{
			if (beta<2.0*alpha) l=mid;
			else r=mid;
		}
		else
		{
			if (beta>2*pi) l=mid;
			else r=mid;
		}
	}
	double ans=(l+r)/2.0;
	double alpha=2.0*asin(mx/(2*ans));
	double beta=check(ans);
	if (beta<alpha+pi) puts("OUTSIDE");
	else if (ans>120) puts("TOO BIG");
	else printf("%.4lf\n",ans);
	return 0;
}