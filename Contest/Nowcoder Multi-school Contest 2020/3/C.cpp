#include <bits/stdc++.h>
using namespace std;

const double eps=1e-3;

struct point
{
	double x, y;
	point() {}
	point(double _x, double _y):
		x(_x), y(_y) {}
	point operator - (const point &p) const {
		return point(x - p.x, y - p.y);
	}
	double operator ^ (const point &p) const {
		return x * p.x + y * p.y;
	}
	double operator * (const point &p) const {
		return x * p.y - y * p.x;
	}
}p[20];

inline double getDis(point p){return p^p;}

int T,n=20;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		int i;
		for (i=0;i<20;i++) scanf("%lf %lf",&p[i].x,&p[i].y);
		for (i=0;i<20;i++)
			if (fabs(getDis(p[i]-p[(i+1)%n])-36)<=eps)
				break;
		if (fabs(getDis(p[i]-p[(i-1+n)%n])-81)<=eps)
		{
			if ((p[(i-1+n)%n]-p[i])*(p[(i+1)%n]-p[i])<=eps)
				puts("left");
			else puts("right");
		}
		else
		{
			if ((p[i]-p[(i+1)%n])*(p[(i+2)%n]-p[(i+1)%n])<=eps)
				puts("right");
			else puts("left");
		}
	}
	return 0;
}