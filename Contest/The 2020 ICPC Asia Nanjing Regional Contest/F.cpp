#include <bits/stdc++.h>
using namespace std;

int n,m,_p;
double p;

inline double fpow(double a,int b)
{
	double r=1;
	for (;b;b>>=1,a*=a) if (b&1) r*=a;
	return r;
}

double f(double x)
{
	return (n*x+m)/(1.0-fpow(1.0-p,x));
}

inline void Solve()
{
	scanf("%d %d %d",&n,&m,&_p);
	p=_p/10000.0;
	int l=1,r=5000000;
	while (r-l>=10)
	{
		int lmid=(l+l+r)/3;
		int rmid=(l+r+r)/3;
		if (f(lmid)<f(rmid)) r=rmid;
		else l=lmid;
	}
	double ans=1e18;
	int k=-1;
	for (int i=max(1,l-10);i<=r+10;i++)
	{
		double now=f(i);
		if (ans>now)
		{
			ans=now;
			k=i;
		}
	}
	printf("%.10lf\n",ans);
	return ;
}

int main()
{
	int T;
	scanf("%d",&T);
	while (T--) Solve();
	return 0;
}
