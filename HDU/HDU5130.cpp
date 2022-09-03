#include <bits/stdc++.h>
#define MAXN 505
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

point p[MAXN],A,B;
int n;
double K;

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

int main()
{
	int cas=0;
	while (~scanf("%d %lf",&n,&K))
	{
		for (int i=0;i<n;i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			p[i]=point(x,y);
		}
		int x,y;
		scanf("%d %d",&x,&y);A=point(x,y);
		scanf("%d %d",&x,&y);B=point(x,y);
		double Ox=(B.x-K*K*A.x)/(1.0-K*K);
		double Oy=(B.y-K*K*A.y)/(1.0-K*K);
		double F=(B.x*B.x+B.y*B.y-K*K*(A.x*A.x+A.y*A.y))/(1.0-K*K);
		double r=sqrt(Ox*Ox+Oy*Oy-F);
		double ans=0.0;
		Circle C=Circle(point(Ox,Oy),r);
		for (int i=0;i<n;i++) ans+=TriangleCircleInsection(C,p[i],p[(i+1)%n]);
		printf("Case %d: %.10lf\n",++cas,fabs(ans));
	}
	return 0;
}