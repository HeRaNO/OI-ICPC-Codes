#include <bits/stdc++.h>
#define MAXN 1005
using namespace std;

const double eps=1e-5;

int n;
double d[MAXN][MAXN],c[MAXN][MAXN],x[MAXN],y[MAXN],z[MAXN],dis[MAXN];
bool vis[MAXN];
double l,r,m;

inline bool ok(double m)
{
	double ans=0.0;memset(vis,false,sizeof vis);
	dis[1]=0.0;for (int i=2;i<=n;i++) dis[i]=1e18;
	for (int i=1;i<=n;i++)
	{
		double mn=1e18;int pt=-1;
		for (int j=1;j<=n;j++)
			if (!vis[j]&&mn>dis[j])
			{
				pt=j;mn=dis[j];
			}
		if (!~pt) break;
		vis[pt]=true;ans+=mn;
		for (int j=1;j<=n;j++)
			if (j!=pt) dis[j]=min(dis[j],c[pt][j]-m*d[pt][j]);
	}
	return ans>=0.0;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lf %lf %lf",&x[i],&y[i],&z[i]);
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
		{
			d[i][j]=d[j][i]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
			c[i][j]=c[j][i]=fabs(z[i]-z[j]);
		}
	l=0.0;r=1500.0;
	while (r-l>eps)
	{
		m=(l+r)/2.0;
		if (ok(m)) l=m;
		else r=m;
	}
	printf("%.3lf\n",l);
	return 0;
}
