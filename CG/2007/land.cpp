#include <bits/stdc++.h>
#define MAXN 2005
using namespace std;

const double eps=1e-8;

struct Point
{
	double x,y,i;
	Point(){}
	Point(double _x,double _y):x(_x),y(_y){}
	Point operator - (const Point &p2)const{
		return Point(x-p2.x,y-p2.y);
	}
	bool operator < (const Point p)const{
		if (p.x!=x) return p.x>x;
		return p.y>y;
	}
	double operator * (const Point &p2) {
		return 1LL*x*p2.y-1LL*y*p2.x;
	}
};

int n;
Point p[MAXN],ch[MAXN];

int ConvexHull(Point *p,int n)
{
	sort(p,p+n);int m=0;
	for (int i=0;i<n;i++)
	{
		while (m>1&&(ch[m-1]-ch[m-2])*(p[i]-ch[m-2])<=eps) --m;
		ch[m++]=p[i];
	}
	int k=m;
	for (int i=n-2;~i;i--)
	{
		while (m>k&&(ch[m-1]-ch[m-2])*(p[i]-ch[m-2])<=eps) --m;
		ch[m++]=p[i];
	}
	if (n>1) --m;
	return m;
}

inline bool OK(Point a,Point b,Point c,Point d)
{
	double A=fabs((b-a)*(c-a));
	double B=fabs((b-a)*(d-a));
	return A<B;
}

inline void Rotating_Calipers(int m)
{
	double ans=0,now;
	if (m<=2) ans=0;
	else if (m==3)
	{
		now=~(1LL<<63);
		ans=abs((ch[0]-ch[2])*(ch[1]-ch[2]));
		for (int i=0;i<n;i++)
		{
			if (ch[0].i==p[i].i||ch[1].i==p[i].i||ch[2].i==p[i].i) continue;
			double s1=fabs((ch[0]-p[i])*(ch[1]-p[i]));
			double s2=fabs((ch[1]-p[i])*(ch[2]-p[i]));
			double s3=fabs((ch[2]-p[i])*(ch[0]-p[i]));
			now=min(min(now,s1),min(s2,s3));
		}
		if (now!=~(1LL<<63)) ans-=now;
		else ans=0;
	}
	else
	{
		for (int i=0;i<m;i++)
		{
			int x=(i+1)%m,y=(i+2)%m;
			for (int j=(i+2)%m;j!=i;(++j)%=m)
			{
				while (x!=j&&OK(ch[i],ch[j],ch[x],ch[x+1])) (++x)%=m;
				while (y!=i&&OK(ch[i],ch[j],ch[y],ch[y+1])) (++y)%=m;
				now=fabs((ch[x]-ch[i])*(ch[j]-ch[i]))+fabs((ch[y]-ch[i])*(ch[j]-ch[i]));
				if (now>ans) ans=now;
			}
		}
	}
	printf("%.3lf\n",ans/2.0);
	return ;
}

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%lf %lf",&p[i].x,&p[i].y),p[i].i=i;
	Rotating_Calipers(ConvexHull(p,n));
	return 0;
}