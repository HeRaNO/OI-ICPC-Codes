#include <bits/stdc++.h>
#define MAXN 1005
using namespace std;

const double pi=acos(-1.0);

struct Point
{
	int x,y,b;double a;
	Point(){}
	Point(int x,int y):x(x),y(y){}
	Point operator - (const Point &p)const{
		return Point(x-p.x,y-p.y);
	}
	bool operator < (const Point &p)const{
		return a<p.a;
	}
	inline double getAngle(){
		return atan2(y,x);
	}
}O;

Point p[MAXN];
int n;
vector <double> v;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d %d %d",&p[i].x,&p[i].y,&p[i].b);
		for (int j=1;j<i;j++)
			if (p[j].b<p[i].b) v.push_back((p[j]-p[i]).getAngle());
			else if (p[j].b>p[i].b) v.push_back((p[i]-p[j]).getAngle());
	}
	sort(v.begin(),v.end());
	if (v.size()<=1) return puts("Y"),0;
	double x=v.back()-2*pi;
	for (auto y:v)
	{
		if (y>=x+pi) return puts("Y"),0;
		x=y;
	}
	puts("N");
	return 0;
}