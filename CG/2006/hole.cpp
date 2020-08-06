#include <bits/stdc++.h>
#define MAXN 55
using namespace std;

const double eps=1e-6;
const double pi=acos(-1.0);

struct point
{
	double x,y;
	point(){}
	point(double _x,double _y):x(_x),y(_y){}
	point operator + (const point &p)const{
		return point(x+p.x,y+p.y);
	}
	point operator - (const point &p)const{
		return point(x-p.x,y-p.y);
	}
	point operator * (double rate)const{
		return point(x*rate,y*rate);
	}
	double operator ^ (const point &p)const{
		return x*p.x+y*p.y;
	}
	double operator * (const point &p)const{
		return x*p.y-y*p.x;
	}
	double length(){
		return sqrt(x*x+y*y);
	}
};

struct Circle
{
	point c;
	double r;
	Circle(){}
	Circle(point _p,double _r):c(_p),r(_r){}
};

point p[MAXN];
int n;
double S,l,r=1e5;

int dcmp(double x)
{
	if (fabs(x)<eps) return 0;
	return x<0?-1:1;
}

inline double TriangleCircleInsection(Circle C,point A,point B)
{
	point OA=A-C.c,OB=B-C.c;
	point BA=A-B, BC=C.c-B;
	point AB=B-A, AC=C.c-A;
	double DOA=OA.length(),DOB=OB.length(),DAB=AB.length(),r=C.r;
	if (!dcmp(OA*OB)) return 0;
	if (dcmp(DOA-C.r)<0&&dcmp(DOB-C.r)<0) return (OA*OB)*0.5;
	else if (DOB<r&&DOA>=r)
	{
		double x=((BA^BC)+sqrt(r*r*DAB*DAB-(BA*BC)*(BA*BC)))/DAB;
		double TS=(OA*OB)*0.5;
		return asin(TS*(1-x/DAB)*2/r/DOA)*r*r*0.5+TS*x/DAB;
	}
	else if(DOB>=r&&DOA<r)
	{
		double y=((AB^AC)+sqrt(r*r*DAB*DAB-(AB*AC)*(AB*AC)))/DAB;
		double TS=(OA*OB)*0.5;
		return asin(TS*(1-y/DAB)*2/r/DOB)*r*r*0.5+TS*y/DAB;
	}
	else if (fabs(OA*OB)>=r*DAB||(AB^AC)<=0||(BA^BC)<=0)
	{
		if((OA^OB)<0)
		{
			if ((OA*OB)<0) return (-pi-asin((OA*OB)/DOA/DOB))*r*r*0.5;
			else return (pi-asin((OA*OB)/DOA/DOB))*r*r*0.5;
		}
		else return asin((OA*OB)/DOA/DOB)*r*r*0.5;
	}
	else
	{
		double x=((BA^BC)+sqrt(r*r*DAB*DAB-(BA*BC)*(BA*BC)))/DAB;
		double y=((AB^AC)+sqrt(r*r*DAB*DAB-(AB*AC)*(AB*AC)))/DAB;
		double TS=(OA*OB)*0.5;
		return (asin(TS*(1-x/DAB)*2/r/DOA)+asin(TS*(1-y/DAB)*2/r/DOB))*r*r*0.5+TS*((x+y)/DAB-1);
	}
}

inline double check(double r)
{
	double ans=0.0;
	Circle C=Circle(point(0,0),r);
	for (int i=0;i<n;i++) ans+=TriangleCircleInsection(C,p[i],p[(i+1)%n]);
	return fabs(ans);
}

int main()
{
	scanf("%d %lf",&n,&S);
	for (int i=0;i<n;i++) scanf("%lf %lf",&p[i].x,&p[i].y);
	for (int i=1;i<=100;i++)
	{
		double mid=(l+r)/2.0;
		if (check(mid)>S) r=mid;
		else l=mid;
	}
	printf("%.2lf\n",(l+r)/2.0);
	return 0;
}