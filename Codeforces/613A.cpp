#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

const double pi=acos(-1.0);

struct Point
{
	int x,y;
	Point(){}
	Point(int _x,int _y):x(_x),y(_y){}
	Point operator - (const Point &p)const{
		return Point(x-p.x,y-p.y);
	}
	long long operator * (const Point &p)const{
		return 1LL*x*p.y-1LL*y*p.x;
	}
	long long operator ^ (const Point &p)const{
		return 1LL*x*p.x+1LL*y*p.y;
	}
	long long dis(const Point &p)const{
		return 1LL*(x-p.x)*(x-p.x)+1LL*(y-p.y)*(y-p.y);
	}
}O;

int n;
Point p[MAXN];
double mx,mn=1e18;
long long mxx,mnx=~(1LL<<63);

inline int sgn(long long x){return x<0?0:1;}

inline double getdis(Point a,Point b)
{
	Point ab=b-a;
	if (!(sgn(a^ab)^sgn(b^ab))) return 1e18;
	long long x=abs(a*b);double y=sqrt(a.dis(b));
	double r=x/y;
	return r*r;
}

int main()
{
	scanf("%d %d %d",&n,&O.x,&O.y);
	for (int i=0;i<n;i++)
	{
		scanf("%d %d",&p[i].x,&p[i].y);
		p[i]=p[i]-O;
		long long d=p[i].dis(Point(0,0));
		mxx=max(mxx,d);mnx=min(mnx,d);
	}
	mx=mxx;mn=mnx;
	for (int i=0;i<n;i++) mn=min(mn,getdis(p[i],p[(i+1)%n]));
	printf("%.10lf\n",pi*(mx-mn));
	return 0;
}