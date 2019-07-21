#include <cmath>
#include <cstdio>
#include <algorithm>
#define MAXN 200010
using namespace std;

struct point
{
	long long x,y;
	point(){}
	point(long long _x,long long _y):x(_x),y(_y){}
	bool operator < (const point p) const
	{
		if (p.x != x) return p.x > x;
		else return p.y > y;
	}
	friend point operator + (const point &p1,const point &p2)
	{
		return point(p1.x+p2.x,p1.y+p2.y);
	}
	friend point operator - (const point &p1,const point &p2)
	{
		return point(p1.x-p2.x,p1.y-p2.y);
	}
};

int n;long long x,y;
point p[MAXN];

inline long long cross_a(point a,point b,point c){return abs((b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x));}

long long Rotating_Calipers()
{
	long long res=~(1LL<<63);
	for (int i=0;i<n;i++) res=min(res,cross_a(p[i],p[(i+1)%n],p[(i+2)%n]));
	return res;
}

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%lld %lld",&x,&y);
		p[i]=point(x,y);
	}
	printf("%lld\n",Rotating_Calipers());
	return 0;
}