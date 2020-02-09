#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

struct Point
{
	int x,y;
	Point(){}
	Point(int _x,int _y):x(_x),y(_y){}
	Point operator - (const Point &a)const{
		return Point(x-a.x,y-a.y);
	}
	long long operator * (const Point &a)const{
		return 1LL*x*a.y-1LL*y*a.x;
	}
	long long dis()const{
		return 1LL*x*x+1LL*y*y;
	}
}a[MAXN];

int n;

int main()
{
	scanf("%d",&n);
	if (n&1) return puts("NO"),0;
	for (int i=0;i<n;i++) scanf("%d %d",&a[i].x,&a[i].y);
	for (int i=0,m=n>>1;i<m;i++)
	{
		Point p=a[i+1]-a[i];
		Point q=a[(i+1+m)%n]-a[i+m];
		if (p*q||p.dis()!=q.dis()) return puts("NO"),0;
	}
	puts("YES");
	return 0;
}