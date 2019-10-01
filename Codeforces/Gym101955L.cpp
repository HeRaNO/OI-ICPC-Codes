#include <bits/stdc++.h>
#define MAXN 105
using namespace std;
 
struct point
{
	double x,y;
	point() {}
	point(double _x, double _y): x(_x), y(_y) {}
	friend point operator - (const point &p1, const point &p2)
	{
		return point(p1.x - p2.x, p1.y - p2.y);
	}
	friend point Rotate(const point &p, double alpha)
	{
		return point(p.x * cos(alpha) - p.y * sin(alpha), p.x * sin(alpha) + p.y * cos(alpha));
	}
	friend double dot(const point &p1, const point &p2)
	{
		return p1.x * p2.x + p1.y * p2.y;
	}
	friend double Polar_Angle(const point &p)
	{
		return atan2(p.y, p.x);
	}
};
 
point a[MAXN<<1];
int cas,T,n,R,m,x[MAXN],y[MAXN],r[MAXN];
 
inline double getdis(point x,point y)
{
	point p=x-y;
	return sqrt(dot(p,p));
}
 
inline bool incir(int p,int q)
{
	point cc=point(x[q],y[q]);
	point t=cc-point(-a[p].x,-a[p].y);
	double dis=dot(t,t);
	if (r[q]*r[q]>dis) return true;
	return false;
}
 
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&n,&R);m=0;
		for (int i=1;i<=n;i++)
		{
			scanf("%d %d %d",&x[i],&y[i],&r[i]);
			if (x[i]*x[i]+y[i]*y[i]==(R+r[i])*(R+r[i]))
				a[++m]=Rotate(point(R,0),Polar_Angle(point(x[i],y[i])));
			else if (x[i]*x[i]+y[i]*y[i]>(R+r[i])*(R+r[i])||x[i]*x[i]+y[i]*y[i]<(R-r[i])*(R-r[i])) continue;
			else
			{
				double alpha=Polar_Angle(point(x[i],y[i]));
				double d=sqrt(x[i]*x[i]+y[i]*y[i]);
				double beta=(double)(R*R+x[i]*x[i]+y[i]*y[i]-r[i]*r[i])/(double)(2*R*d);
				beta=acos(beta);
				a[++m]=Rotate(point(R,0),alpha-beta);
				a[++m]=Rotate(point(R,0),alpha+beta);
			}
		}
		double dis=0;bool f=false;
		for (int i=1;i<=m;i++)
			for (int j=i+1;j<=m;j++)
				dis=max(dis,getdis(a[i],a[j]));
		for (int i=1;i<=m&&!f;i++)
		{
			bool all=true;
			for (int j=1;j<=n&&all;j++)
				if (incir(i,j)) all=false;
			if (all)
			{
				dis=R<<1;
				f=true;
			}
		}
		printf("Case #%d: %.15lf\n",++cas,dis);
	}
	return 0;
}