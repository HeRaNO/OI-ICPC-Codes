#include <bits/stdc++.h>
using namespace std;

const double pi=acos(-1.0);
int T,r,v,x,y;

inline double f(double x)
{
	return r*sin(x/r)+x;
}

int main()
{
	scanf("%d %d %d",&T,&r,&v);
	double C=2*pi*r;
	while (T--)
	{
		scanf("%d %d",&x,&y);
		int k=(double)(y-x)/C;
		double d=(y-x)-C*k;d/=2.0;
		double l=0,r=d;
		for (int i=1;i<=50;i++)
		{
			double mid=(l+r)/2.0;
			if (f(mid)<d) l=mid;
			else r=mid;
		}
		printf("%.12lf\n",(l*2+C*k)/v);
	}
	return 0;
}