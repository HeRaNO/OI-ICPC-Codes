#include <cmath>
#include <cstdio>
using namespace std;

double a,b,l,r;

double F(double x)
{
	bool f=false;
	if (x<0){f=true;x=-x;}
	if (x==0) return 0;
	double t=asin(x/a);
	t=1./4*a*b*(2.0*t+sin(2.0*t));
	if (f) t=-t;
	return t;
}

int main()
{
	scanf("%lf %lf %lf %lf",&a,&b,&l,&r);
	printf("%.3lf\n",2.0*(F(r)-F(l)));
	return 0;
}