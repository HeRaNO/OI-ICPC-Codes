#include <cmath>
#include <cstdio>
#include <algorithm>
#define MAXN 205
using namespace std;

const double eps=1e-8;

inline void read(int &x)
{
	x=0;char ch;bool f=false;
	if ((ch=getchar())==EOF){x=-1;return ;}
	while (ch<'0'||ch>'9'){if (ch=='-') f=true;ch=getchar();}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	if (f) x=-x;return ;
}

struct Point
{
	double x,y;
	Point(){}
	Point(double _,double __):x(_),y(__){}
	void read(){int _x;::read(_x);x=_x;::read(_x);y=_x;return ;}
	Point operator + (const Point &a)const{
		return Point(x+a.x,y+a.y);
	}
	Point operator - (const Point &a)const{
		return Point(x-a.x,y-a.y);
	}
	double operator * (const Point &a)const{
		return x*a.y-a.x*y;
	}
	int operator ^ (const Point &a)const{
		double m=x*a.y-a.x*y;
		if (fabs(m)<=eps) return 0;
		if (m<-eps) return -1;
		return 1;
	}
	double len(){return sqrt(x*x+y*y);}
};

struct line
{
	Point x,y;
	line(){}
	line(Point _,Point __):x(_),y(__){}
	double len(){return (y-x).len();}
};

Point p[MAXN];line l[MAXN];
int n,pt;double ans;
pair <double,int> a[MAXN];

void max(double a){if (ans<a) ans=a;return ;}

int cross(line A,line B)
{
	Point a,b,c;a=A.y-A.x;b=B.x-A.x;c=B.y-A.x;
	int x=a^b,y=a^c;
	if (x==y) return 0;
	if (x>y) return x&&y?2:1;
	return x&&y?-2:-1;
}

double len(line A,line B)
{
	return (B.x-A.x)*(B.y-A.x)/((A.y-A.x)*(B.y-B.x))*A.len();
}

inline void Analyze(line x)
{
	pt=0;int cnt=0;double s=0;
	for (int i=1,m;i<=n;i++)
	{
		m=cross(x,l[i]);
		if (!m) continue;
		a[++pt]=make_pair(len(x,l[i]),m);
	}
	sort(a+1,a+pt+1);
	for (int i=1;i<=pt;i++)
	{
		if (cnt) s+=a[i].first-a[i-1].first;
		else max(s),s=0;
		cnt+=a[i].second;
	}
	max(s);
	return ;
}

int main()
{
	while (1)
	{
		read(n);if (!~n) break;
		for (int i=1;i<=n;i++) p[i].read();
		for (int i=1;i<n;i++) l[i]=line(p[i],p[i+1]);l[n]=line(p[n],p[1]);
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				Analyze(line(p[i],p[j]));
		printf("%.10lf\n",ans);ans=0;
	}
	return 0;
}
