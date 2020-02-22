#include <bits/stdc++.h>
#define MAXN 55
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
	int operator * (const Point &p2) {
		return x*p2.y-y*p2.x;
	}
};

int T,m,n,c;
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

inline bool in(int x,int y,int c)
{
	double k=sqrt(2),b=y-k*x;int cnt=0;Point O=Point(x,y);
	for (int i=0;i<c;i++) if (p[i].x==x&&p[i].y==y) return false;
	for (int i=0;i<c;i++)
	{
		Point oa=ch[i]-O;
		Point ob=ch[(i+1)%c]-O;
		if (!(oa*ob)) return false;
	}
	for (int i=0;i<c;i++)
	{
		int A=ch[(i+1)%c].y-ch[i].y;
		int B=ch[i].x-ch[(i+1)%c].x;
		int C=ch[(i+1)%c]*ch[i];
		int lx=min(ch[i].x,ch[(i+1)%c].x),rx=max(ch[i].x,ch[(i+1)%c].x);
		int ly=min(ch[i].y,ch[(i+1)%c].y),ry=max(ch[i].y,ch[(i+1)%c].y);
		double nx=-(B*b+C)/(A+B*k);
		double ny=k*nx+b;
		if (ny>y) continue;
		if (lx<=nx&&nx<=rx&&ly<=ny&&ny<=ry) ++cnt;
	}
	return cnt&1;
}

int main()
{
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++)
	{
		printf("Case %d\n",cas);
		scanf("%d %d",&n,&m);
		for (int i=0;i<n;i++) scanf("%d %d",&p[i].x,&p[i].y);
		c=ConvexHull(p,n);
		for (int i=0;i<=c;i++) printf("%d %d\n",ch[i%c].x,ch[i%c].y);
		for (int i=1;i<=m;i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			if (in(x,y,c)) printf("%d %d is unsafe!\n",x,y);
			else printf("%d %d is safe!\n",x,y);
		}
		puts("");
	}
	return 0;
}