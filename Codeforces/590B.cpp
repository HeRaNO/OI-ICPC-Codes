#include <bits/stdc++.h>
using namespace std;

double x,y,a,b,vm,t,vx,vy,wx,wy;

inline bool check(double pt)
{
	double mx,my;
	if (pt<t){mx=pt*vx;my=pt*vy;}
	else {mx=t*vx+(pt-t)*wx;my=t*vy+(pt-t)*wy;}
	double ax,ay;ax=x+mx;ay=y+my;
	double r=vm*pt;
	return (ax-a)*(ax-a)+(ay-b)*(ay-b)<=vm*pt*vm*pt;
}

int main()
{
	scanf("%lf %lf %lf %lf",&x,&y,&a,&b);
	scanf("%lf %lf",&vm,&t);
	scanf("%lf %lf %lf %lf",&vx,&vy,&wx,&wy);
	double l=0,r=1e9;
	for (int i=1;i<=100;i++)
	{
		double mid=(l+r)/2.0;
		if (check(mid)) r=mid;
		else l=mid;
	}
	printf("%.12lf\n",r);
	return 0;
}