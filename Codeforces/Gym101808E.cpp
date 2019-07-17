#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int T,n,x[MAXN],y[MAXN],l[MAXN],r[MAXN];
int hi,lo;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);double ans=0;
		for (int i=1;i<=n;i++) scanf("%d %d",&x[i],&y[i]);
		l[0]=r[n+1]=-1;
		for (int i=1;i<=n;i++) l[i]=max(l[i-1],y[i]);
		for (int i=n;i;i--) r[i]=max(r[i+1],y[i]);
		for (int i=1;i<n;i++)
		{
			if (y[i]<=y[i+1])
			{
				hi=i+1;
				lo=i;
			}
			else
			{
				hi=i;
				lo=i+1;
			}
			int p=min(l[lo],r[lo]);
			if (p>=y[hi]&&p>=y[lo])
			{
				ans+=(double)(2*p-y[hi]-y[lo])*(double)(x[i+1]-x[i]);
			}
			else
			{
				ans+=(double)(p-y[lo])*(p-y[lo])*(x[i+1]-x[i])/(y[hi]-y[lo]);
			}
		}
		printf("%.10lf\n",ans/2.0);
	}
	return 0;
}