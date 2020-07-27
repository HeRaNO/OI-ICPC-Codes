#include <bits/stdc++.h>
#define MAXN 1005
using namespace std;

const double pi=acos(-1.0);

struct point
{
	double x, y;
	point() {}
	point(double _x, double _y):
		x(_x), y(_y) {}
	point operator + (const point &p) const {
		return point(x + p.x, y + p.y);
	}
	point operator - (const point &p) const {
		return point(x - p.x, y - p.y);
	}
	point operator * (double rate) const {
		return point(x * rate, y * rate);
	}
	point operator / (double rate) const {
		return point(x / rate, y / rate);
	}
	bool operator < (const point &p) const {
		if (p.x != x) return p.x > x;
		else return p.y > y;
	}
	double operator ^ (const point &p) const {
		return x * p.x + y * p.y;
	}
	double operator * (const point &p) const {
		return x * p.y - y * p.x;
	}
	double Polar_Angle() const {
		return atan2(y, x);
	}
	point Rotate(double alpha) const {
		return point(x * cos(alpha) - y * sin(alpha), x * sin(alpha) + y * cos(alpha));
	}
}O;

point p[MAXN];
double Alpha,s,S;
int n,K;

inline point getPoint(double r,int i,int k)
{
	return point(r*cos(2*pi*i/k),r*sin(2*pi*i/k));
}

bool SameSide(point A, point B, point C, point P)
{
    point AB = B - A ;
    point AC = C - A ;
    point AP = P - A ;

    double v1 = AB * AC ;
    double v2 = AB * AP ;

    // v1 and v2 should point to the same direction
    return v1 * v2 >= 0 ;
}

inline bool PIT(point A,point B,point C,point P)
{
	return SameSide(A, B, C, P) &&
        SameSide(B, C, A, P) &&
        SameSide(C, A, B, P) ;
}

inline int check(double r,int k)
{
	int cnt=0;
	for (int i=1;i<=n;i++)
	{
		int x=p[i].x,y=p[i].y;
		bool f=false;
		for (int j=0;j<k;j++)
			if (PIT(O,getPoint(r,j,k),getPoint(r,(j+1)%k,k),p[i]))
			{
				++cnt;break;
			}
	}
	return cnt;
}

int main()
{
	scanf("%d",&n);
	for (int i=1,x,y;i<=n;i++) scanf("%d %d",&x,&y),p[i]=point(x,y);
	for (int k=3;k<=8;k++)
	{
		double l=0,r=1e7;
		for (int i=1;i<=200;i++)
		{
			double mid=(l+r)/2.0;
			if (!check(mid,k)) l=mid;
			else r=mid;
		}
		r=(l+r)/2.0;
		s=k*sin(2*pi/k)*r*r/2;
		l=0;r=1e7;
		for (int i=1;i<=200;i++)
		{
			double mid=(l+r)/2.0;
			if (check(mid,k)==n) r=mid;
			else l=mid;
		}
		r=(l+r)/2.0;
		S=k*sin(2*pi/k)*r*r/2;
		double alpha=s/S;
		if (alpha>Alpha)
		{
			Alpha=alpha;K=k;
		}
	}
	printf("%d %.9lf\n",K,Alpha);
	return 0;
}