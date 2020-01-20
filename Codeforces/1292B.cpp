#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

long long x[MAXN],y[MAXN],bx,by,xs,ys,t,ans[MAXN];
int ax,ay,n,res;

int main()
{
	scanf("%lld %lld",&x[0],&y[0]);
	scanf("%d %d",&ax,&ay);
	scanf("%lld %lld",&bx,&by);
	scanf("%lld %lld %lld",&xs,&ys,&t);
	for (int i=1;;i++)
	{
		x[i]=ax*x[i-1]+bx;
		y[i]=ay*y[i-1]+by;
		if (x[i]>2e16||y[i]>2e16)
		{
			n=i;
			break;
		}
	}
	for (int i=1;i<=n;i++)
		ans[i]=(x[i]-x[i-1])+(y[i]-y[i-1]);
	if (t>=abs(xs-x[0])+abs(ys-y[0]))
	{
		int p=1;
		long long dis=t-abs(xs-x[0])-abs(ys-y[0]);
		for (int i=1;i<=n;i++)
			if (ans[i]<=dis)
			{
				++p;dis-=ans[i];
			}
			else break;
		res=max(res,p);
	}
	for (int i=1;i<=n;i++)
	{
		int p=1;
		long long dis=t-abs(xs-x[i])-abs(ys-y[i]);
		if (dis<0) continue;
		for (int j=i;j>=1;j--)
			if (ans[j]<=dis)
			{
				++p;dis-=ans[j];
			}
			else break;
		res=max(res,p);
	}
	printf("%d\n",res);
	return 0;
}