#include <bits/stdc++.h>
#define MAXN 8
using namespace std;

const double eps=1e-7;
const double INF=1e18;

struct point
{
	double x,y;
	point(){}
	point(double _x,double _y):x(_x),y(_y){}
	point operator - (const point &p)const{
		return point(x-p.x,y-p.y);
	}
	double operator ^ (const point &p)const{
		return x*p.x+y*p.y;
	}
	double operator * (const point &p)const{
		return x*p.y-y*p.x;
	}
	double length(){
		return sqrt(x*x+y*y);
	}
};

point p[MAXN|1];
int N,M,n;
double dp[1<<MAXN];

void Cut(double &L,double &R,point x,point y,point la,point lb)
{
	point v=lb-la,lv=y-x,p=la-x;
	double op=v*lv;
	if (fabs(op)<=eps) return ;
	if (op<0) L=max(L,(lv*p)/op);
	else R=min(R,(lv*p)/op);
	return ;
}

double calc(int sta,int x)
{
	double l=-INF,r=INF;
	Cut(l,r,point(0,0),point(N,0),p[x],p[x+1]);
	Cut(l,r,point(N,0),point(N,M),p[x],p[x+1]);
	Cut(l,r,point(N,M),point(0,M),p[x],p[x+1]);
	Cut(l,r,point(0,M),point(0,0),p[x],p[x+1]);
	for (int i=0;i<n;i++) if (sta&(1<<i)) Cut(l,r,p[i],p[i+1],p[x],p[x+1]);
	return (r-l)*(p[x]-p[x+1]).length();
}

int main()
{
	scanf("%d %d %d",&N,&M,&n);
	for (int i=n-1;~i;i--) scanf("%lf %lf",&p[i].x,&p[i].y);p[n]=p[0];
	for (int i=1;i<(1<<n);i++) dp[i]=INF;
	for (int i=0;i<(1<<n);i++)
		for (int j=0;j<n;j++)
			if (!(i&(1<<j)))
				dp[i|(1<<j)]=min(dp[i|(1<<j)],dp[i]+calc(i,j));
	printf("%.3lf\n",dp[(1<<n)-1]);
	return 0;
}