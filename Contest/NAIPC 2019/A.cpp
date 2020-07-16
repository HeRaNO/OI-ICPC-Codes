#include <bits/stdc++.h>
#define MAXN 2505
using namespace std;

struct point
{
	double x,y;
	point(){}
	point(double _x,double _y):x(_x),y(_y){}
	double operator * (const point &p)const{
		return x*p.y-y*p.x;
	}
};

int n,k;
point p[MAXN];
double ans,P[MAXN];

int main()
{
	scanf("%d %d",&n,&k);
	for (int i=0;i<n;i++) scanf("%lf %lf",&p[i].x,&p[i].y);
	P[0]=(double)(k*(k-1))/(double)(n*(n-1));
	for (int i=1;i<n-1;i++) P[i]=P[i-1]*(double)(n-k+1-i)/(double)(n-1-i);
	for (int i=0;i<n;i++)
		for (int j=i+1;j<i+n;j++)
			ans+=-(p[i]*p[j%n])*P[j-i-1];
	printf("%.9lf\n",ans/2.0);
	return 0;
}