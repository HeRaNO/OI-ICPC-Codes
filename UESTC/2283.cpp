#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

const double eps=1e-7;

struct point
{
	double x, y;
	point() {}
	point(double _x, double _y):
		x(_x), y(_y) {}
	friend point operator + (const point &p1, const point &p2)
	{
		return point(p1.x + p2.x, p1.y + p2.y);
	}
	friend point operator - (const point &p1, const point &p2)
	{
		return point(p1.x - p2.x, p1.y - p2.y);
	}
	friend point operator * (const point &p, double rate)
	{
		return point(p.x * rate, p.y * rate);
	}
	bool operator < (const point p) const
	{
		if (p.x != x) return p.x > x;
		else return p.y > y;
	}
	friend double cross(const point &p1, const point &p2)
	{
		return p1.x * p2.y - p1.y * p2.x;
	}
	friend double dis(const point &p1, const point &p2)
	{
		return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
	}
	friend point mid(const point &p1, const point &p2)
	{
		return point((p1.x+p2.x)/2.0,(p1.y+p2.y)/2.0);
	}
	friend point Rotate(const point &p)
	{
		return point(-p.y, p.x);
	}
};

struct Circle
{
	point o;
	double r;
	Circle(){}
	Circle(point _,double __):o(_),r(__){}
}ans;

point p[MAXN];
int n;

inline Circle getcenter(point a,point b,point c)
{
	point d=b-a,e=a-c;
	d=Rotate(d);e=Rotate(e);
	point f=mid(a,b),g=mid(a,c);
	point p=f-g;
	double t=cross(e,p)/cross(d,e);
	point O=f+d*t;
	return Circle(O,dis(O,a));
}

inline Circle getMinCircle()
{
	Circle r;
	r.o=p[1];r.r=0;
	for (int i=2;i<=n;i++)
		if (dis(p[i],r.o)>r.r+eps)
		{
			r=Circle(p[i],0);
			for (int j=1;j<i;j++)
				if (dis(p[j],r.o)>r.r+eps)
				{
					r.o=mid(p[i],p[j]);
					r.r=dis(p[i],p[j])/2;
					for (int k=1;k<j;k++)
						if (dis(p[k],r.o)>r.r+eps)
							r=getcenter(p[i],p[j],p[k]);
				}
		}
	return r;
}

int main()
{
	while (scanf("%d",&n)!=-1)
	{
		for (int i=1;i<=n;i++)
			scanf("%lf %lf",&p[i].x,&p[i].y);
		random_shuffle(p+1,p+n+1);
		ans=getMinCircle();
		printf("%.3lf\n%.3lf %.3lf\n",ans.r,ans.o.x,ans.o.y);
	}	
	return 0;
}