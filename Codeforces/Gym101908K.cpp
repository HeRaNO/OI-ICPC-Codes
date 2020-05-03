#include <bits/stdc++.h>
#define MAXN 150005
using namespace std;

const double C=70.710678118654752440084436210485;

struct Circle
{
	double x,y,r;
	bool operator < (const Circle &a)const{
		return r<a.r;
	}
	double dis(Circle a)
	{
		return sqrt((x-a.x)*(x-a.x)+(y-a.y)*(y-a.y));
	}
};

int n,ans;
Circle a[MAXN];

inline bool ok(int x,int y)
{
	double d=a[x].dis(a[y]);
	return a[y].r-a[x].r<d&&d<a[x].r+a[y].r;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lf %lf %lf",&a[i].x,&a[i].y,&a[i].r);
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
		{
			if (a[j].r-a[i].r>=C) break;
			else if (ok(i,j))
			{
				ans+=2;
				if (ans>2*n) return puts("greater"),0;
			}
		}
	printf("%d\n",ans);
	return 0;
}