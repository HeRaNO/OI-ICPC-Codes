#include <bits/stdc++.h>
using namespace std;

double ans;
double Rm,R,r,x,y,vx,vy;

double dot(double x1,double y1,double x2,double y2)
{
	return x1*x2+y1*y2;
}

double len(double x1,double x2)
{
	return sqrt(x1*x1+x2*x2);
}

int main()
{
	while (~scanf("%lf %lf %lf %lf %lf %lf %lf",&Rm,&R,&r,&x,&y,&vx,&vy))
	{
		double cdis=len(x,y);
		double beta=asin((Rm+r)/cdis);
		double theta=asin((R+r)/cdis);
		double t1=dot(-x,-y,vx,vy);
		double t2=cdis*len(vx,vy);
		double alpha=acos(t1/t2);
		if (alpha<=beta)
		{
			double dis=len(x,y);
			dis=dis*sin(alpha);
			ans=2.0*sqrt((R+r)*(R+r)-dis*dis);
			double t=2.0*sqrt((Rm+r)*(Rm+r)-dis*dis);
			ans-=t;
		}
		else if (alpha<=theta)
		{
			double dis=len(x,y);
			dis=dis*sin(alpha);
			ans=2.0*sqrt((R+r)*(R+r)-dis*dis);
		}
		else ans=0.0;
		printf("%lf\n",ans/len(vx,vy));
	}
	return 0;
}