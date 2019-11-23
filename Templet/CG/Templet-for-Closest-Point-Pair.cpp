#include <cmath>
#include <cstdio>
#include <algorithm>
#define MAXN 200010
using namespace std;

struct Point
{
	double x,y;
	double dis(const Point &a)const{
		return sqrt((x-a.x)*(x-a.x)+(y-a.y)*(y-a.y));
	}
};

int n;
Point p[MAXN],t[MAXN];
double ans=1e18;

bool cmp(Point x,Point y){return x.x==y.x?x.y<y.y:x.x<y.x;}
bool cmpy(Point x,Point y){return x.y<y.y;}
inline void min(double &x,double y){if (x>y) x=y;return ;}

void DC(int l,int r)
{
	if (l==r) return ;
	if (l+1==r){min(ans,p[l].dis(p[r]));return ;}
	int m=l+r>>1,cnt=0;
	DC(l,m);DC(m+1,r);
	for (int i=l;i<=r;i++)
		if (fabs(p[m].x-p[i].x)<=ans) t[++cnt]=p[i];
	sort(t+1,t+cnt+1,cmpy);
	for (int i=1;i<=cnt;i++)
		for (int j=i+1;j<=cnt;j++)
		{
			if (t[j].y-t[i].y>=ans) break;
			min(ans,t[i].dis(t[j]));
		}
	return ;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lf %lf",&p[i].x,&p[i].y);
	sort(p+1,p+n+1,cmp);
	DC(1,n);
	printf("%.4lf\n",ans);
	return 0;
}