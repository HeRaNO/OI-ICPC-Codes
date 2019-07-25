#include <bits/stdc++.h>
#define MAXN 1000010
using namespace std;

int n,r;
long long a[MAXN],k,c[MAXN],l,rr,ans,s;

inline bool check(long long m)
{
	for (int i=1;i<=n;i++) c[i]=a[i];
	for (int i=n+1;i<=n+r;i++) c[i]=0;
	long long pk=k,now=0LL;
	for (int i=1;i<=r+1;i++) now+=c[i];
	for (int i=1;i<=n;i++,now+=c[i+r])
	{
		if (now<m)
		{
			if (pk<m-now) return false;
			pk-=m-now;
			c[i+r]+=m-now;
			now=m;
		}
		if (i>r) now-=c[i-r];
	}
	return true;
}

int main()
{
	scanf("%d %d %lld",&n,&r,&k);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]),s+=a[i];
	l=1;rr=s+k;
	while (l<=rr)
	{
		long long mid=l+rr>>1;
		if (check(mid)){ans=mid;l=mid+1;}
		else rr=mid-1;
	}
	printf("%lld\n",ans);
	return 0;
}