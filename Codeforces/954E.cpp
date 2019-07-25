#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;

int n,T;
double l,r,mid;
pair <int,int> a[MAXN];

inline bool check(double x)
{
	double res=x,lo=0.0,now=T*x;
	for (int i=1;i<=n;i++)
	{
		if (res>a[i].second)
		{
			lo+=1LL*a[i].first*a[i].second;
			res-=a[i].second;
		}
		else
		{
			lo+=res*a[i].first;
			break;
		}
	}
	if (lo>now) return false;
	lo=0.0;res=x;
	for (int i=n;i;i--)
	{
		if (res>a[i].second)
		{
			lo+=1LL*a[i].first*a[i].second;
			res-=a[i].second;
		}
		else
		{
			lo+=1LL*res*a[i].first;
			break;
		}
	}
	if (now>lo) return false;
	return true;
}

int main()
{
	scanf("%d %d",&n,&T);
	for (int i=1;i<=n;i++) scanf("%d",&a[i].second);
	for (int i=1;i<=n;i++) scanf("%d",&a[i].first);
	sort(a+1,a+n+1);
	l=0;r=2e11;
	while (r-l>1e-7)
	{
		mid=(l+r)/2.0;
		if (check(mid)) l=mid;
		else r=mid;
	}
	printf("%.7lf\n",l);
	return 0;
}