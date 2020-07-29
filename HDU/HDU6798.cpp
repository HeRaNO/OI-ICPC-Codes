#include <bits/stdc++.h>
using namespace std;

const double pi=acos(-1.0);
const double s3=sqrt(3);
const double _23pi=2*pi/3;

struct point
{
	double x,y;
	point(){}
	point(double _x,double _y):x(_x),y(_y){}
	point operator + (const point &p)const{
		return point(x+p.x,y+p.y);
	}
	point operator - (const point &p)const{
		return point(x-p.x,y-p.y);
	}
	point operator * (const double &r)const{
		return point(x*r,y*r);
	}
	point Rotate(double alpha)const{
		return point(x*cos(alpha)-y*sin(alpha),x*sin(alpha)+y*cos(alpha));
	}
}P,v,C;

int L,x,y,vx,vy,k;
double h;

inline long long check(double t)
{
	long long cnt=0;point Q=P+(v*t);
	cnt+=abs(floor(Q.y/h));
	Q=Q-C;Q=Q.Rotate(_23pi);Q=Q+C;
	cnt+=abs(floor(Q.y/h));
	Q=Q-C;Q=Q.Rotate(_23pi);Q=Q+C;
	cnt+=abs(floor(Q.y/h));
	return cnt;
}

inline void Solve()
{
	scanf("%d %d %d %d %d %d",&L,&x,&y,&vx,&vy,&k);
	P=point(x,y);v=point(vx,vy);h=L*s3/2.0;C=point(0,h/3);
	double l=0,r=1e11;
	for (int i=1;i<=70;i++)
	{
		double mid=(l+r)/2.0;
		if (check(mid)>=k) r=mid;
		else l=mid;
	}
	printf("%.8lf\n",(l+r)/2.0);
	return ;
}

int main()
{
	int T;scanf("%d",&T);
	while (T--) Solve();
	return 0;
}