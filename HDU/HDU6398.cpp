#include <bits/stdc++.h>
using namespace std;

const double pi=acos(-1.0);
const double pi2=acos(0);

struct point
{
	int x,y;
	point(){}
	point(int _x,int _y):x(_x),y(_y){}
	point operator - (const point &a)const{
		return point(x-a.x,y-a.y);
	}
}p[3],O(0,0);

int T,w,a[3];
double ans;

inline int cross(point &p1,point &p2)
{
	return p1.x*p2.y-p1.y*p2.x;
}

inline int dot(point a,point b)
{
	return a.x*b.x+a.y*b.y;
}

inline double len(point a,point b)
{
	return sqrt(dot(b-a,b-a));
}

inline void check(point a,point b)
{
	int S=cross(a,b);
	if (dot(a,b)<0) return ;
	if (dot(a,a)<=w*w)
	{
		if (S<0) return ;
		if (1LL*dot(a,b)*dot(a,b)>1LL*dot(a,a)*w*w) return ;
		ans=min(ans,fabs(S)/len(a,O));
	}
	else
	{
		double A=atan2(sqrt(dot(a,a)-w*w),w);
		double B=pi2-A;
		double alpha=acos((double)dot(a,b)/(len(a,O)*len(b,O)));
		if (S>=0)
		{
			if (alpha-B>1e-9) return ;
			double l=len(b,O)*cos(alpha+A);
			if (l>w) return ;
			ans=min(ans,max(sqrt(dot(a,a)-w*w),len(b,O)*sin(alpha+A)));
		}
		else
		{
			if (alpha-A>1e-9) return ;
			double l=len(b,O)*cos(A-alpha);
			if (l>w) return ;
			ans=min(ans,sqrt(dot(a,a)-w*w));
		}
	}
	return ;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		for (int i=0;i<3;i++) scanf("%d %d",&p[i].x,&p[i].y),a[i]=i;
		scanf("%d",&w);ans=1e9+7;
		do {
			check(p[a[0]]-p[a[1]],p[a[2]]-p[a[1]]);
		}while (next_permutation(a,a+3));
		for (int i=0;i<3;i++) p[i].y=-p[i].y,a[i]=i;
		do {
			check(p[a[0]]-p[a[1]],p[a[2]]-p[a[1]]);
		}while (next_permutation(a,a+3));
		if (ans>=1e9) puts("impossible");
		else printf("%.9lf\n",ans);
	}
	return 0;
}
