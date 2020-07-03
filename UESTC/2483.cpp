#include <cstdio>
#include <algorithm>
#define MAXN 6005
using namespace std;

struct Point
{
	long long x,y;
	Point(){x=y=0;}
	Point(long long _x,long long _y):x(_x),y(_y){}
	Point operator + (const Point &a)const{
		return Point(x+a.x,y+a.y);
	}
	Point operator - (const Point &a)const{
		return Point(x-a.x,y-a.y);
	}
	bool operator < (const Point &a)const{
		return x==a.x?y<a.y:x<a.x;
	}
	long long operator * (const Point &a)const{
		return x*a.y-y*a.x;
	}
};

Point p[MAXN],a[MAXN];
int n,x,y;
long long S;

inline void Analyze(int x)
{
	int m=0;Point P;
	for (int i=x+1;i<=n;i++) a[++m]=p[i]-p[x];
	sort(a+1,a+m+1,[&](const Point &a,const Point &b){return a*b>0;});
	for (int i=1;i<=m;i++) P=P+a[i];
	for (int i=1;i<=m;i++) P=P-a[i],S+=a[i]*P;
	return ;
}

inline void read(int &x)
{
	x=0;bool f=false;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=true;ch=getchar();}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	x=f?-x:x;return ;
}

int main()
{
	read(n);
	for (int i=1;i<=n;i++) read(x),read(y),p[i]=Point(x,y);
	sort(p+1,p+n+1);
	for (int i=1;i<n-1;i++) Analyze(i);
	if (!S) puts("QAQ");
	else if (S&1) printf("%lld.5\n",S>>1);
	else printf("%lld.0\n",S>>1);
	return 0;
}