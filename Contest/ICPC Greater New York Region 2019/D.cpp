#include <bits/stdc++.h>
#define MAXN 105
using namespace std;

const double PI=acos(-1.0);
const double EPS=1e-7;

inline int DB(double x) {
	if(x<-EPS) return -1;
	if(x>EPS) return 1;
	return 0;
}

struct point {
	double x,y;
 
	point() {}
	point(double _x,double _y):x(_x),y(_y) {}
 
	point operator-(point a) {
		return point(x-a.x,y-a.y);
	}
	point operator+(point a) {
		return point(x+a.x,y+a.y);
	}
	double operator*(point a) {
		return x*a.y-y*a.x;
	}
	point oppose() {
		return point(-x,-y);
	}
	double length() {
		return sqrt(x*x+y*y);
	}
	point adjust(double L) {
		L/=length();
		return point(x*L,y*L);
	}
	point vertical() {
		return point(-y,x);
	}
	double operator^(point a) {
		return x*a.x+y*a.y;
	}
};

struct segment {
	point a,b;
 
	segment() {}
	segment(point _a,point _b):a(_a),b(_b) {}
 
	point intersect(segment s) {
		double s1=(s.a-a)*(s.b-a);
		double s2=(s.b-b)*(s.a-b);
		double t=s1+s2;
		s1/=t;
		s2/=t;
		return point(a.x*s2+b.x*s1,a.y*s2+b.y*s1);
	}
	point vertical(point p) {
		point t=(b-a).vertical();
		return intersect(segment(p,p+t));
	}
	int isonsegment(point p) {
		return DB(min(a.x,b.x)-p.x)<=0&&
			   DB(max(a.x,b.x)-p.x)>=0&&
			   DB(min(a.y,b.y)-p.y)<=0&&
			   DB(max(a.y,b.y)-p.y)>=0;
	}
};

struct circle {
	point p;
	double R;
};

circle C;
point p[105];
int n;

double cross_area(point a,point b,circle C) {
	point p=C.p;
	double R=C.R;
	int sgn=DB((b-p)*(a-p));
	double La=(a-p).length(),Lb=(b-p).length();
	int ra=DB(La-R),rb=DB(Lb-R);
	double ang=acos(((b-p)^(a-p))/(La*Lb));
	segment t(a,b);
	point s;
	point h,u,temp;
	double ans,L,d,ang1;

	if(!DB(La)||!DB(Lb)||!sgn) ans=0;
	else if(ra<=0&&rb<=0) ans=fabs((b-p)*(a-p))/2;
	else if(ra>=0&&rb>=0) {
		h=t.vertical(p);
		L=(h-p).length();
		if(!t.isonsegment(h)||DB(L-R)>=0) ans=R*R*(ang/2);
		else {
			ans=R*R*(ang/2);
			ang1=acos(L/R);
			ans-=R*R*ang1;
			ans+=R*sin(ang1)*L;
		}
	} else {
		h=t.vertical(p);
		L=(h-p).length();
		s=b-a;
		d=sqrt(R*R-L*L);
		s=s.adjust(d);
		if(t.isonsegment(h+s)) u=h+s;
		else u=h+s.oppose();
		if(ra==1) temp=a,a=b,b=temp;
		ans=fabs((a-p)*(u-p))/2;
		ang1=acos(((u-p)^(b-p))/((u-p).length()*(b-p).length()));
		ans+=R*R*(ang1/2);
	}
	return ans*sgn;
}

double cal_cross()
{
	double ans=0;p[n]=p[0];
	for (int i=0;i<n;i++) ans+=cross_area(p[i],p[i+1],C);
	return fabs(ans);
}

inline double calcS()
{
	p[n]=p[0];double ans=0;
	for (int i=0;i<n;i++) ans+=p[i]*p[i+1];
	return fabs(ans)/2.0;
}

void TriangleCentroid(point P1, point P2, point P3, double& area, point& centroid)
{
	point P12 = P2 - P1;
	point P13 = P3 - P1;

	double x1 = P12.x;
	double y1 = P12.y;

	double x2 = P13.x;
	double y2 = P13.y;

	area = (x1*y2 - x2*y1)/2;

	centroid.x = (P1.x + P2.x + P3.x) / 3;
	centroid.y = (P1.y + P2.y + P3.y) / 3;

	return;
}

bool PolygonCentroid(point& centroid)
{
	double totalArea = 0;

	point totalTriangleCentroid(0,0);

	for (int i = 1; i < n - 1; i++)
	{
		double temp;
		point tempCentroid;

		TriangleCentroid(p[0], p[i], p[i + 1], temp, tempCentroid);

		totalTriangleCentroid.x += tempCentroid.x * temp;
		totalTriangleCentroid.y += tempCentroid.y * temp;

		totalArea += temp;
	}

	centroid.x = totalTriangleCentroid.x / totalArea;
	centroid.y = totalTriangleCentroid.y / totalArea;

	return true;
}

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%lf %lf",&p[i].x,&p[i].y);
	PolygonCentroid(C.p);
	double S=calcS();C.R=sqrt(S/PI);
	printf("%.4lf\n",cal_cross()/S);
	return 0;
}