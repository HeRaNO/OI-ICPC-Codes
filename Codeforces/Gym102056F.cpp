#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

struct point
{
	double x, y, z;
	point() {}
	point(double _x, double _y, double _z):
		x(_x), y(_y), z(_z) {}
	bool operator == (const point &a)const{
		return (x==a.x)&&(y==a.y)&&(z==a.z);
	}
	friend point operator + (const point &p1, const point &p2)
	{
		return point(p1.x + p2.x, p1.y + p2.y, p1.z + p2.z);
	}
	friend point operator - (const point &p1, const point &p2)
	{
		return point(p1.x - p2.x, p1.y - p2.y, p1.z - p2.z);
	}
	friend point operator * (const point &p, double rate)
	{
		return point(p.x * rate, p.y * rate, p.z*rate);
	}
	friend double dot(const point &p1, const point &p2)
	{
		return p1.x * p2.x + p1.y * p2.y + p1.z * p2.z;
	}
	friend double Euclid_dis(const point &p1, const point &p2)
	{
		return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) + (p1.z - p2.z) * (p1.z - p2.z));
	}
};

point o,s,t;
int T;double r;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		double ans=0.0,alpha,beta,theta;
		int a,b,c,d,e,f;
		scanf("%d %d %d %lf",&a,&b,&c,&r);
		o=point(a,b,c);
		scanf("%d %d %d",&a,&b,&c);
		scanf("%d %d %d",&d,&e,&f);
		if ((a==d)&&(b==e)&&(c==f)){printf("0.00000000\n");continue;}
		s=point(a,b,c);t=point(d,e,f);
		double r1=Euclid_dis(s,o);
		double r2=Euclid_dis(t,o);
		double dd=Euclid_dis(s,t);
		ans+=sqrt(r1*r1-r*r);
		ans+=sqrt(r2*r2-r*r);
		alpha=acos((r1*r1+r2*r2-dd*dd)/(2*r1*r2));
		beta=acos(r/r2);
		theta=acos(r/r1);
		if (beta+theta>alpha) printf("%.10lf\n",Euclid_dis(s,t));
		else
		{
			alpha-=(beta+theta);
			ans+=r*alpha;
			printf("%.10lf\n",ans);
		}
	}
	return 0;
}