#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

struct point
{
	long long x, y;
	point() {}
	point(long long _x, long long _y):
		x(_x), y(_y) {}
	friend point operator + (const point &p1, const point &p2)
	{
		return point(p1.x + p2.x, p1.y + p2.y);
	}
	friend point operator - (const point &p1, const point &p2)
	{
		return point(p1.x - p2.x, p1.y - p2.y);
	}
	friend long long cross(const point &p1, const point &p2)
	{
		return p1.x * p2.y - p1.y * p2.x;
	}
};

int T,x,y;
point p[5];

inline bool isIntersection(point a,point b,point c,point d)
{
	if (max(a.x,b.x)<min(c.x,d.x)) return false;
	if (max(a.y,b.y)<min(c.y,d.y)) return false;
	if (max(c.x,d.x)<min(a.x,b.x)) return false;
	if (max(c.y,d.y)<min(a.y,b.y)) return false;
	long long p=cross(b-a,b-c);
	long long q=cross(b-a,b-d);
	long long r=cross(d-c,d-a);
	long long s=cross(d-c,d-b);
	return (p*q<=0)&&(r*s<=0);
}

inline double solve()
{
	double ix,iy,t,m,n;int pa=0,pb=0,c=0;
	if (!isIntersection(p[1],p[2],p[3],p[4])) return 0;
	if (p[1].y==p[2].y||p[3].y==p[4].y) return 0;
	if (!cross(p[1]-p[2],p[3]-p[4])) return 0;
	t=(double)cross(p[1]-p[3],p[3]-p[4])/(double)cross(p[1]-p[2],p[3]-p[4]);
	ix=p[1].x+(p[2].x-p[1].x)*t;
	iy=p[1].y+(p[2].y-p[1].y)*t;
	for (int i=1;i<=4;i++)
		if (p[i].y>iy)
		{
			if (!pa) pa=i;
			else pb=i;
			++c;
		}
	if (c!=2) return 0;
	if ((p[pa].x-ix)*(p[pb].y-iy)>(p[pa].y-iy)*(p[pb].x-ix)) swap(pa,pb);
	if ((p[2].x-p[1].x)*(p[2].y-p[1].y)*(p[4].x-p[3].x)*(p[4].y-p[3].y)>0)
		if (p[pa].x>=p[pb].x) return 0;
	if (p[pa].y<p[pb].y) swap(pa,pb);
	if (pa<3)
	{
		m=(double)(p[1].x-p[2].x)/(double)(p[1].y-p[2].y);
		n=p[1].x-m*p[1].y;
	}
	else
	{
		m=(double)(p[3].x-p[4].x)/(double)(p[3].y-p[4].y);
		n=p[3].x-m*p[3].y;
	}
	double tx=m*p[pb].y+n;
	return fabs(tx-p[pb].x)*(p[pb].y-iy)/2.0;
}

int main()
{
	while (true)
	{
		for (int i=1;i<=4;i++)
		{
			if (scanf("%d %d",&x,&y)!=2) return 0;
			p[i]=point(x,y);
		}
		printf("%.2lf\n",solve());
	}
	return 0;
}