#include <cmath>
#include <cstdio>
using namespace std;

int T,n,a,b,m,c[1010],s,x;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		m=0;s=0;
		scanf("%d %d %d",&n,&a,&b);
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if (a<=x&&x<=b){c[++m]=x;s+=x;}
		}
		double avg=(double)s/(double)m;
		double d=0;
		printf("%.2lf ",avg);
		for (int i=1;i<=m;i++)
			d+=(avg-c[i])*(avg-c[i]);
		d=sqrt(d)/(double)m;
		printf("%.2lf\n",d);
	}
	return 0;
}