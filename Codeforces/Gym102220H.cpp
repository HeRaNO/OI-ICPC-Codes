#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int T,n,m,a[MAXN],o,l,r,x;
long long c[MAXN],d[MAXN];

inline int lowbit(int x){return x&-x;}
inline void modify(int x,long long v){if (!v) return ;for (;x<=n;x+=lowbit(x)) c[x]+=v;return ;}
inline long long query(int x){long long r=0;for (;x;x-=lowbit(x)) r+=c[x];return r;}
inline void modifyA(int x,int v){for (;x<=n;x+=lowbit(x)) d[x]+=v;return ;}
inline long long queryA(int x){long long r=0;for (;x;x-=lowbit(x)) r+=d[x];return r;}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&n,&m);
		memset(c,0,sizeof c);memset(d,0,sizeof d);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=1;i<=n;i++)
		{
			if (a[i]>a[i-1]) modify(i,a[i]-a[i-1]);
			else modify(i,0);
		}
		while (m--)
		{
			scanf("%d %d %d",&o,&l,&r);
			if (o==1)
			{
				scanf("%d",&x);
				int p=a[l-1]+queryA(l-1);
				int q=a[l]+queryA(l);
				long long now=query(l)-query(l-1);
				if (q+x>p) modify(l,q+x-p-now);
				else modify(l,-now);
				p=a[r]+queryA(r);
				q=a[r+1]+queryA(r+1);
				now=query(r+1)-query(r);
				if (q>p+x) modify(r+1,q-p-x-now);
				else modify(r+1,-now);
				modifyA(l,x);modifyA(r+1,-x);
			}
			else
			{
				printf("%lld\n",a[l]+queryA(l)+query(r)-query(l));
			}
		}
	}
	return 0;
}