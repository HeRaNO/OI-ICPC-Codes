#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#define M 10100
using namespace std;
struct point{
	double x,y,z;
}points[M],ans;
int n;
double minans=23333333333333333ll;
double dis(const point &x,const point &y)
{
	return sqrt( (x.x-y.x)*(x.x-y.x) + (x.y-y.y)*(x.y-y.y) + (x.z-y.z)*(x.z-y.z) );
}
double Judge(const point &p)
{
	int i;
	double re=0;
	for(i=1;i<=n;i++)
		re=max(re,dis(p,points[i]));
	if(re<minans)
		ans=p,minans=re;
	return re;
}
double Rand()
{
	return rand()%1000/1000.0;
}
void SA(double T)
{
	int i;
	point Now=ans;
	while(T>0.000001)
	{
		point Neo;
		Neo.x=Now.x+T*(Rand()*2-1);
		Neo.y=Now.y+T*(Rand()*2-1);
		Neo.z=Now.z+T*(Rand()*2-1);
		double dE = Judge(Now) - Judge(Neo) ;
		if(dE > 0) Now=Neo;
		T*=0.998;
	}
	/*for(i=1;i<=300000;i++)
	{
		point Neo;
		Neo.x=ans.x+T*(Rand()*2-1);
		Neo.y=ans.y+T*(Rand()*2-1);
		Neo.z=ans.z+T*(Rand()*2-1);
		Judge(Neo);
	}*/
}
int main()
{
	srand((unsigned int)time(NULL));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%lf%lf",&points[i].x,&points[i].y,&points[i].z);
		ans.x+=points[i].x;
		ans.y+=points[i].y;
		ans.z+=points[i].z;
	}
	ans.x/=n;
	ans.y/=n;
	ans.z/=n;
	SA( 3000000 );
	printf("%.12lf\n",minans);
	return 0;
}