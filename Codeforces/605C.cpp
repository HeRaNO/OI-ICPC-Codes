#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

struct Point
{
	int x,y;
	Point(){}
	Point(int _x,int _y):x(_x),y(_y){}
	Point operator - (const Point &p2)const{
		return Point(x-p2.x,y-p2.y);
	}
	bool operator < (const Point p)const{
		if (p.x!=x) return p.x>x;
		return p.y>y;
	}
	bool operator == (const Point &p)const{
		return x==p.x&&y==p.y;
	}
	long long operator * (const Point &p2) {
		return 1LL*x*p2.y-1LL*y*p2.x;
	}
};

int n,P,q,mxa,mxb;
Point p[MAXN],ch[MAXN];

int ConvexHull(Point *p,int n)
{
	sort(p,p+n);int m=0;
	for (int i=0;i<n;i++)
	{
		while (m>1&&(ch[m-1]-ch[m-2])*(p[i]-ch[m-2])<=0) --m;
		ch[m++]=p[i];
	}
	int k=m;
	for (int i=n-2;~i;i--)
	{
		while (m>k&&(ch[m-1]-ch[m-2])*(p[i]-ch[m-2])<=0) --m;
		ch[m++]=p[i];
	}
	if (n>1) --m;
	return m;
}

int main()
{
	scanf("%d %d %d",&n,&P,&q);
	for (int i=0;i<n;i++)
	{
		scanf("%d %d",&p[i].x,&p[i].y);
		mxa=max(p[i].x,mxa);mxb=max(p[i].y,mxb);
	}
	p[n++]=Point(mxa,0);p[n++]=Point(0,mxb);p[n++]=Point(0,0);
	int m=ConvexHull(p,n);
	for (int i=0;i<m;i++)
	{
		long long A=ch[(i+1)%m].y-ch[i].y;
		long long B=ch[i].x-ch[(i+1)%m].x;
		long long C=ch[(i+1)%m]*ch[i];
		long long xa=-C*P,xb=(A*P+B*q);
		if (!xa) continue;
		int mxx=max(ch[i].x,ch[(i+1)%m].x);
		int mnx=min(ch[i].x,ch[(i+1)%m].x);
		if (!(mnx*xb<=xa&&xa<=mxx*xb)) continue;
		long long ya=-C*q,yb=(A*P+B*q);
		int mxy=max(ch[i].y,ch[(i+1)%m].y);
		int mny=min(ch[i].y,ch[(i+1)%m].y);
		if (!(mny*yb<=ya&&ya<=mxy*yb)) continue;
		return printf("%.10lf\n",(double)-xb/C),0;
	}
	assert(false);
	return 0;
}