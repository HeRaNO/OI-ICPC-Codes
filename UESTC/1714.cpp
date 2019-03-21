#include <cmath>
#include <cstdio>
#include <algorithm>
#define MAXN 1005
using namespace std;

const double pi=acos(-1.0);
const double eps=1e-8;

struct Point
{
	double x,y;
	Point(){}
	Point(double _x,double _y):x(_x),y(_y){}
	bool operator < (const Point &a)const{
		return x!=a.x?x<a.x:y<a.y;
	}
	Point operator - (const Point &p)const{
		return Point(x-p.x,y-p.y);
	}
};

int n,m,l;double ans;
Point p[MAXN],ch[MAXN];

inline double cross(Point a,Point b){return a.x*b.y-a.y*b.x;}
inline double dis(Point a,Point b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}

int ConvexHull()
{
	sort(p,p+n);int m=0;
	for (int i=0;i<n;i++)
	{
		while (m>1&&cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=eps) m--;
		ch[m++]=p[i];
	}
	int k=m;
	for (int i=n-2;~i;i--)
	{
		while (m>k&&cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=eps) m--;
		ch[m++]=p[i];
	}
	if (n>1) m--;
	return m;
}

int main()
{
	scanf("%d %d",&n,&l);
	for (int i=0,x,y;i<n;i++){scanf("%d %d",&x,&y);p[i]=Point(x,y);}
	m=ConvexHull();
	for (int i=0;i<m;i++) ans+=dis(ch[i],ch[(i+1)%m]);
	printf("%.0lf\n",ans+pi*l*2.0);
	return 0;
}