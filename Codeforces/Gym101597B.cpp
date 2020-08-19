#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-7;

struct point
{
	double x, y;
	point() {}
	point(double _x, double _y):
		x(_x), y(_y) {}
	point operator + (const point &p) const {
		return point(x + p.x, y + p.y);
	}
	point operator - (const point &p) const {
		return point(x - p.x, y - p.y);
	}
	point operator * (double rate) const {
		return point(x * rate, y * rate);
	}
	point operator / (double rate) const {
		return point(x / rate, y / rate);
	}
	bool operator < (const point &p) const {
		if (p.x != x) return p.x > x;
		else return p.y > y;
	}
	bool operator != (const point &p) const {
		return fabs(x-p.x)>eps&&fabs(y-p.y)>eps;
	}
	double length() const {
		return sqrt(x * x + y * y);
	}
	double operator ^ (const point &p) const {
		return x * p.x + y * p.y;
	}
	double operator * (const point &p) const {
		return x * p.y - y * p.x;
	}
	double Polar_Angle() const {
		return atan2(y, x);
	}
	point Rotate(double alpha) const {
		return point(x * cos(alpha) - y * sin(alpha), x * sin(alpha) + y * cos(alpha));
	}
	point norm() const {
		return point(-y, x);
	}
	point unit(double r) const {
		double d = sqrt(x * x + y * y);
		return point(x / d * r, y / d * r);
	}
};

int n,x,y;
point A,B,C,l;
vector <point> v;
double ans;

int main()
{
	scanf("%d %d",&x,&y);A=point(x,y);
	scanf("%d %d",&x,&y);B=point(x,y);
	scanf("%d %d",&x,&y);C=point(x,y);
	scanf("%d",&n);
	l=B-A;l=l.unit(1);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if (i==1||i==n) v.push_back(A+l*x);
	}
	scanf("%d",&n);
	l=C-B;l=l.unit(1);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if (i==1||i==n) v.push_back(B+l*x);
	}
	scanf("%d",&n);
	l=A-C;l=l.unit(1);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if (i==1||i==n) v.push_back(C+l*x);
	}
	for (auto i:v)
		for (auto j:v)
			for (auto k:v)
				ans=max(ans,fabs((j-i)*(k-i)));
	printf("%.9lf\n",ans/2.0);
	return 0;
}