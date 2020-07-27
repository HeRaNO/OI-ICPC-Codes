#include <bits/stdc++.h>
using namespace std;

int T;
double a,b,c,k,l,p,q,x,y;

inline double Int(double x)
{
	return a*x*x*x/3-(2*a*b+k)*x*x/2+(a*b*b+c-l)*x;
}

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%lf %lf",&b,&c);
		scanf("%lf %lf",&p,&q);
		scanf("%lf %lf",&x,&y);
		a=(q-c)/((p-b)*(p-b));
		k=(y-q)/(x-p);l=y-k*x;
		printf("%.2lf\n",Int(x)-Int(p));
	}
	return 0;
}