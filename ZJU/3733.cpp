#include <bits/stdc++.h>
using namespace std;

const double pi=acos(-1.0);

double R,r,h,s;
int f;

int main()
{
	while (~scanf("%lf %lf %lf %d %lf",&R,&r,&h,&f,&s))
	{
		double ans=0,H=h/f,dr=(R-r)/(double)f;
		for (int i=1;i<=f;i++)
		{
			double alpha=atan(s/(H*r*2));
			int b=pi/alpha;
			ans+=2*r*b*tan(pi/b)*H;
			r+=dr;
		}
		printf("%.8lf\n",ans);
	}
	return 0;
}