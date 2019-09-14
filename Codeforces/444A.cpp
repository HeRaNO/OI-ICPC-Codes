#include <bits/stdc++.h>
#define MAXN 505
using namespace std;

int n,m,u,v,w,a[MAXN];
double ans;

int main()
{
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int j=1;j<=m;j++)
	{
		scanf("%d %d %d",&u,&v,&w);
		ans=max(ans,(double)(a[u]+a[v])/(double)w);
	}
	printf("%.15lf\n",ans);
	return 0;
}
