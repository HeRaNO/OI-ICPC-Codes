#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

int a[MAXN],b[MAXN],T,n,m;

inline void max(double &a,double b){if (a<b) a=b;return ;}
inline void min(double &a,double b){if (a>b) a=b;return ;}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);double s=0;
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=1;i<n;i++) scanf("%d",&b[i]);
		double l=a[1]+b[1],r=a[1]+b[1]+a[2];
		for (int i=1;i<n;i++)
		{
			s+=a[i]+b[i];
			max(l,s/i);min(r,(s+a[i+1])/i);
		}
		if (l<=r) printf("%.2lf\n",l);
		else puts("impossible");
	}
	return 0;
}