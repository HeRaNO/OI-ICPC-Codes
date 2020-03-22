#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
int n,P,Q;
int f[55];
int Find(int x){return x==f[x]?x:f[x]=Find(f[x]);}
struct edge
{
	int u,v;
	double w;
	bool operator < (const edge &x)
	{
		return w<x.w;
	}
}e[5005];
struct points
{
	double x,y;
}a[55];

int main()
{
	while(cin>>n&&n)
	{
		for(int i=1;i<=n;++i)f[i]=i;
		scanf("%d%d",&P,&Q);
		f[P]=Q;
		for(int i=1;i<=n;++i)
		{
			scanf("%lf%lf",&a[i].x,&a[i].y);
		}
		int m=0;
		for(int i=1;i<=n;++i)
		{
			for(int j=i+1;j<=n;++j)
			{
				e[++m].u=i;
				e[m].v=j;
				e[m].w=sqrt((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y));
			}
		}
		sort(e+1,e+m+1);
		double ans=9999999999.0;
		for(int i=1;i<=m;++i)
		{
			if(e[i].u==P&&e[i].v==Q)
				ans=min(ans,e[i].w);
		}
		for(int i=1;i<=m;++i)
		{
			int fx=Find(e[i].u);
			int fy=Find(e[i].v);
			if(fx==fy)continue;
			ans+=e[i].w;
			f[fy]=fx;
		}
		printf("%.2lf\n",ans);
	}
	return 0;
}