#include <bits/stdc++.h>
using namespace std;

const long double eps=1e-11L;
const long double cov=acosl(-1.0L)/180.0;

struct point
{
	long double x,y,z;
	point(){}
	point(long double _x,long double _y,long double _z):x(_x),y(_y),z(_z){}
	point operator * (const point &p)const{
		return point(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);
	}
	point operator * (const double &p)const{
		return point(x*p,y*p,z*p);
	}
	long double operator ^ (const point &p)const{
		return x*p.x+y*p.y+z*p.z;
	}
	long double length()const{
		return sqrtl(x*x+y*y+z*z);
	}
	point norm()const{
		long double d=sqrtl(x*x+y*y+z*z);
		return point(x/d,y/d,z/d);
	}
};

point A,B,C,D,nAB,nCD,l;

inline bool Check(point a,point b,point c)
{
	return ((a*b)^(a*c))>-eps&&((a*b)^(c*b))>-eps;
}

inline void Solve()
{
	long double lat,lon;
	scanf("%Lf %Lf",&lat,&lon);lat*=cov;lon*=cov;
	A=point(cosl(lat)*cosl(lon),cosl(lat)*sinl(lon),sinl(lat));
	scanf("%Lf %Lf",&lat,&lon);lat*=cov;lon*=cov;
	B=point(cosl(lat)*cosl(lon),cosl(lat)*sinl(lon),sinl(lat));
	scanf("%Lf %Lf",&lat,&lon);lat*=cov;lon*=cov;
	C=point(cosl(lat)*cosl(lon),cosl(lat)*sinl(lon),sinl(lat));
	scanf("%Lf %Lf",&lat,&lon);lat*=cov;lon*=cov;
	D=point(cosl(lat)*cosl(lon),cosl(lat)*sinl(lon),sinl(lat));
	nAB=A*B;nCD=C*D;l=nAB*nCD;
	if (l.length()<eps)
	{
		if (Check(A,B,C)) return puts("DANGER"),void();
		if (Check(A,B,D)) return puts("DANGER"),void();
		if (Check(C,D,A)) return puts("DANGER"),void();
		if (Check(C,D,B)) return puts("DANGER"),void();
		return puts("SAFELY"),void();
	}
	l=l.norm();
	long double da0=l^(nAB*A),da1=l^(nAB*B);
	long double db0=l^(nCD*C),db1=l^(nCD*D);
	if (da0>-eps&&da1<eps&&db0>-eps&&db1<eps) puts("DANGER");
	else if (da0<eps&&da1>-eps&&db0<eps&&db1>-eps) puts("DANGER");
	else puts("SAFELY");
	return ;
}

int main()
{
	freopen("flight.in","r",stdin);
	freopen("flight.out","w",stdout);
	int T;scanf("%d",&T);
	while (T--) Solve();
	return 0;
}