#include <cmath>
#include <cstdio>
#include <algorithm>
#define MAXN 100010
using namespace std;

double eps = 1e-7;

struct point
{
	double x, y;
	point() {}
	point(double _x, double _y):
		x(_x), y(_y) {}
	bool operator < (const point p) const
	{
		if (p.x != x) return p.x > x;
		else return p.y > y;
	}
	friend point operator - (const point &p1, const point &p2)
	{
		return point(p1.x - p2.x, p1.y - p2.y);
	}
	friend double cross(const point &p1, const point &p2)
	{
		return p1.x * p2.y - p1.y * p2.x;
	}
	friend double dis(const point &p1, const point &p2)
	{
		return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
	}
};

inline double min(double a,double b){return a - b < eps ? a : b;}

int n;
point p[MAXN], ch[MAXN];

int ConvexHull(point *p, int n)
{
	sort(p, p + n);
	int m = 0;
	for (int i = 0; i < n; i++)
	{
		while (m > 1 && cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= eps) m--;
		ch[m++] = p[i];
	}
	int k = m;
	for (int i = n - 2; ~i; i--)
	{
		while (m > k && cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= eps) m--;
		ch[m++] = p[i];
	}
	if (n > 1) m--;
	return m;
}

double Rotating_Calipers(point *b,int siz)
{
	double res = 1e18;
	int k = 1;
	for (int i = 1; i <= siz; i++)
	{
		point v=ch[i-1]-ch[i%siz];
		while((cross(v,ch[(k+1)%siz]-ch[k]))<0) k=(k+1)%siz;
		res=min(res,fabs(cross(b[i%siz]-b[i-1],b[k]-b[i-1])/dis(b[i%siz],b[i-1])));
	}
	return res;
}

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%lf %lf",&p[i].x,&p[i].y);
	printf("%.2lf\n",Rotating_Calipers(ch,ConvexHull(p,n))/2.0);
	return 0;
}
