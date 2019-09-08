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

struct line
{
	point p, v;
	line() {}
	line(const point &_p, const point &_v): p(_p), v(_v) {}
};

int T,x,y,m,pp,qq;
point p[5];
line a,b;

inline bool isIntersection(point a,point b,point c,point d)
{
	long long p=cross(b-a,b-c);
	long long q=cross(b-a,b-d);
	long long r=cross(d-c,d-a);
	long long s=cross(d-c,d-b);
	return (p*q<=0)&&(r*s<=0);
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		pp=0;qq=0;m=0;
		for (int i=1;i<=4;i++)
		{
			scanf("%d %d",&x,&y);
			p[i]=point(x,y);
		}
		if (isIntersection(p[1],p[2],p[3],p[4]))
		{
			a=line(p[1],p[2]-p[1]);
			b=line(p[3],p[4]-p[3]);
			point u=a.p-b.p;
			double tmp=(double)cross(b.v,u)/(double)cross(a.v,b.v);
			double ix=a.p.x+a.v.x*tmp;
			double iy=a.p.y+a.v.y*tmp;
			for (int i=1;i<=4;i++)
				if (p[i].y>iy) ++m;
			if (m==2)
			{
				for (int i=1;i<=4;i++)
					if (p[i].y>iy)
					{
						if (!pp) pp=i;
						else qq=i;
					}
				if (p[pp].y>p[qq].y) swap(pp,qq);
				double h=p[pp].y-iy,k,b;
				if (qq==1||qq==2)
				{
					k=(double)(p[1].y-p[2].y)/(double)(p[1].x-p[2].x);
					b=p[1].y-k*p[1].x;
				}
				else
				{
					k=(double)(p[3].y-p[4].y)/(double)(p[3].x-p[4].x);
					b=p[3].y-k*p[3].x;
				}
				double tx=(p[pp].y-b)/k;
				double s=fabs(tx-p[pp].x);
				printf("%.2lf\n",h*s*0.5);
			}
			else puts("0.00");
		}
		else puts("0.00");
	}
	return 0;
}