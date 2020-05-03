#include <cmath>
#include <cstdio>
#include <algorithm>
#define pi 3.1415926
using namespace std;

struct point
{
	double x;
	double y;
};

int n;
double xa,ya,xb,yb;
point a[10];
int pt[10];
double ans;
double siz;

double get_dis(point a,point b)
{
	return sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
}

double mymax(double a,double b)
{
	return a>b?a:b;
}

double mymin(double a,double b)
{
	return a<b?a:b;
}

double myabs(double a)
{
	return a<0?-a:a;
}

void check()
{
	double r[10],tmp=0.0,now=999999999999.0,dis,res=0.0;
	for (int i=1;i<=n;i++) r[i]=0.0;
	for (int i=1;i<=n;i++)
	{
		tmp=myabs(a[pt[i]].x-xa); now=mymin(now,tmp);
		tmp=myabs(a[pt[i]].x-xb); now=mymin(now,tmp);
		tmp=myabs(a[pt[i]].y-ya); now=mymin(now,tmp);
		tmp=myabs(a[pt[i]].y-yb); now=mymin(now,tmp);
		for (int j=1;j<=i-1;j++)
		{
			dis=get_dis(a[pt[i]],a[pt[j]]);
			dis-=r[j];
			if (dis<0) dis=0;
			now=mymin(now,dis); 
		}
		r[i]=now;
		res+=pi*now*now;
	}
	ans=mymax(ans,res);
}

int main()
{
	freopen("oilbox.in","r",stdin);freopen("oilbox.out","w",stdout);
	scanf("%d",&n);
	scanf("%lf %lf %lf %lf",&xa,&ya,&xb,&yb);
	siz=myabs(xa-xb)*myabs(ya-yb);
	for (int i=1;i<=n;i++)
	{
		pt[i]=i;
		scanf("%lf %lf",&a[i].x,&a[i].y);
	}
	check();
	while (next_permutation(pt+1,pt+n+1)) check();
	check();
	printf("%.0lf\n",siz-ans);
	return 0;
}