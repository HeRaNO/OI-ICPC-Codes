//From PoPoQQQ
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
#define M 100100
#define EPS 1e-7
using namespace std;
struct Point{
	double x,y;
	Point() {}
	Point(double _,double __):
		x(_),y(__) {}
	friend istream& operator >> (istream &_,Point &p)
	{
		scanf("%lf%lf",&p.x,&p.y);
		return _;
	}
	friend Point operator + (const Point &p1,const Point &p2)
	{
		return Point(p1.x+p2.x,p1.y+p2.y);
	}
	friend Point operator - (const Point &p1,const Point &p2)
	{
		return Point(p1.x-p2.x,p1.y-p2.y);
	}
	friend double operator * (const Point &p1,const Point &p2)
	{
		return p1.x*p2.y-p1.y*p2.x;
	}
	friend Point operator * (const Point &p1,double rate)
	{
		return Point(p1.x*rate,p1.y*rate);
	}
	friend double Distance(const Point &p1,const Point &p2)
	{
		return sqrt( (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y) ) ;
	}
	friend Point Rotate(const Point &p)
	{
		return Point(-p.y,p.x);
	}
}points[M];
struct Line{
	Point p,v;
	Line() {}
	Line(const Point &_,const Point &__):
		p(_),v(__) {}
	friend Point Get_Intersection(const Line &l1,const Line &l2)
	{
		Point u=l1.p-l2.p;
		double temp=(l2.v*u)/(l1.v*l2.v);
		return l1.p+l1.v*temp;
	}
};
struct Circle{
	Point o;
	double r;
	Circle() {}
	Circle(const Point &_,double __):
		o(_),r(__) {}
	bool In_Circle(const Point &p)
	{
		return Distance(p,o) < r + EPS ;
	}
}ans;
int n;
int main()
{
	int i,j,k;
	srand(19980402);
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>points[i];
	random_shuffle(points+1,points+n+1);
	for(i=1;i<=n;i++)
	{
		if(!ans.In_Circle(points[i]))
		{
			ans=Circle(points[i],0);
			for(j=1;j<i;j++)
				if(!ans.In_Circle(points[j]))
				{
					ans=Circle((points[i]+points[j])*0.5,Distance(points[i],points[j])*0.5);
					for(k=1;k<j;k++)
						if(!ans.In_Circle(points[k]))
						{
							Line l1=Line((points[i]+points[j])*0.5,Rotate(points[i]-points[j]));
							Line l2=Line((points[i]+points[k])*0.5,Rotate(points[i]-points[k]));
							Point O=Get_Intersection(l1,l2);
							ans=Circle(O,Distance(points[i],O));
						}
				}
		}
	}
	cout<<fixed<<setprecision(4)<<ans.r<<" "<<ans.o.x<<" "<<ans.o.y<<endl;
	return 0;
}