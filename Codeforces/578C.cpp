#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

int n,a[MAXN];
double b[MAXN];

inline double check(double x)
{
	double now=0,ans=1<<31;
	for (int i=1;i<=n;i++) b[i]=a[i]-x;
	for (int i=1;i<=n;i++)
	{
		now=(now+b[i])>b[i]?(now+b[i]):b[i];
		if (ans<now) ans=now;
	}
	now=0;
	for (int i=1;i<=n;i++)
	{
		b[i]=-b[i];
		now=(now+b[i])>b[i]?(now+b[i]):b[i];
		if (ans<now) ans=now;
	}
	return ans;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	double l=-1e4,r=1e4;
	for (int i=1;i<=100;i++)
	{
		double lmid=l+(r-l)/3.0,rmid=r-(r-l)/3.0;
		if (check(lmid)>check(rmid)) l=lmid;
		else r=rmid;
	}
	printf("%.8lf\n",check((l+r)/2.0));
	return 0;
}