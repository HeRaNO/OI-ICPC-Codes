#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

int n,m,c[MAXN<<1];
long long a[MAXN],f[MAXN],p[MAXN],ans,t;
pair <long long,long long *> b[MAXN<<1];

inline int lowbit(int x){return x&-x;}
inline void add(int x){for (;x<=n+1;x+=lowbit(x)) ++c[x];return ;}
inline int query(int x){int r=0;for (;x;x-=lowbit(x)) r+=c[x];return r;}

int main()
{
	scanf("%d %lld",&n,&t);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (int i=1;i<=n;i++) f[i]=f[i-1]+a[i],p[i]=f[i];
	sort(p,p+n+1);
	for (int i=1;i<=n;i++)
	{
		add(lower_bound(p,p+n+1,f[i-1])-p+1);
		ans+=i-query(upper_bound(p,p+n+1,f[i]-t)-p);
	}
	printf("%lld\n",ans);
	return 0;
}