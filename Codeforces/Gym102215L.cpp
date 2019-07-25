#include <bits/stdc++.h>
using namespace std;

const double pi=acos(-1.0);

int a,b,c,d,e,f;
double alpha;

int main()
{
	scanf("%d %d %d",&a,&b,&c);
	scanf("%d %d %d",&d,&e,&f);
	alpha=atan2(e-b,d-a);
	double x1=a+c*cos(alpha),y1=b+c*sin(alpha);
	double x2=d+f*cos(alpha+pi),y2=e+f*sin(alpha+pi);
	double r=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	double x=(x1+x2)/2.0,y=(y1+y2)/2.0;
	printf("%.12lf %.12lf %.12lf\n",x,y,r/2.0);
	return 0;
}