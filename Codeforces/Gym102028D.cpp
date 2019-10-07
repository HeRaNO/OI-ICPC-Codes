#include <bits/stdc++.h>
using namespace std;

const double cov=acos(-1.0)/180.0;

int a,b,r,d,T;
double alpha,w;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d %d %d",&a,&b,&r,&d);
		alpha=d*cov;w=sqrt((a+r)*(a+r)+b*b);
		if (alpha>acos((a+r)/w)) printf("%.12lf\n",w-r);
		else printf("%.12lf\n",(a+r)*cos(alpha)+b*sin(alpha)-r);
	}
	return 0;
}