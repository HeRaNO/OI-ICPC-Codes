#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int n,x;
long long l,r,ans,k,s[MAXN],c[MAXN];

inline int lowbit(int x){return x&-x;}
inline void add(int x){for (;x<=n;x+=lowbit(x)) ++c[x];return ;}
inline long long query(int x){long long r=0;for (;x;x-=lowbit(x)) r+=c[x];return r;}

inline long long check(long long m)
{
	long long ans=0;memset(c,0,sizeof c);
	for (int i=1;i<=n;i++)
	{
		long long x=s[i]-m;
		int it=lower_bound(s+1,s+n+1,x)-(s+1);
		ans+=query(it)+(x>0);
		add(i);
	}
	return ans;
}

int main()
{
	scanf("%d %lld",&n,&k);k=1LL*n*(n+1)/2+1-k;
	for (int i=1;i<=n;i++) scanf("%d",&x),s[i]=s[i-1]+x;
	l=0;r=s[n];
	while (l<r)
	{
		long long m=l+r>>1;
		if (check(m)>=k) l=m+1;
		else r=m;
	}
	printf("%lld\n",l);
	return 0;
}