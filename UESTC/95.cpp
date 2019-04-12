#include <cmath>
#include <cstdio>
using namespace std;

const double pi=acos(-1.0);

int n,T;double r,v[25];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %lf",&n,&r);
		for (int i=1;i<=n;i++) scanf("%lf",&v[i]);
		v[0]=v[n];double s=0.0;
		for (int i=1;i<=n;i++) if (v[i-1]>v[i]) s+=v[i-1]-v[i];
		if (s==0.0) puts("Inf");
		else printf("%.3lf\n",2.0*pi*r/s);
	}
	return 0;
}
