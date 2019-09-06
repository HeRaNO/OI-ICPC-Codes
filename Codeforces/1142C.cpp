#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

struct Point
{
	long long x,y;
	Point(){}
	Point(int _x,int _y):x(_x),y(_y){}
	bool operator <(const Point &a)const{
		if (x!=a.x) return x<a.x;
		return y<a.y;
	}
};

Point p[MAXN],covu[MAXN];
int n,m,u;
long long x,y;

inline int ConvexHull()
{
	sort(p+1,p+n+1);
	for (int i=1;i<=n;i++)
	{
		if (u&&p[i].x==covu[u].x) --u;
		while (u>1&&
			(covu[u-1].y-covu[u].y)*(covu[u].x-p[i].x)<=
			(covu[u].y-p[i].y)*(covu[u-1].x-covu[u].x)) --u;
		covu[++u]=p[i];
	}
	return u-1;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld %lld",&x,&y);
		p[i].x=x;p[i].y=y-x*x;
	}
	printf("%d\n",ConvexHull());
	return 0;
}