#include <bits/stdc++.h>
#define MAXN 50001
#define MAXL 500010
using namespace std;

int n,m,a[MAXN],prime[MAXL],tot,rmx[MAXN],h[MAXL];
bool not_prime[MAXL];
bitset <50001> p[MAXN],now,pre;

inline void init()
{
	int n=5e5;
	for (int i=2;i<=n;i++)
	{
		if (!not_prime[i]) prime[++tot]=i;
		for (int j=1;i*prime[j]<=n;j++)
		{
			not_prime[i*prime[j]]=true;
			if (!(i%prime[j])) break;
		}
	}
	for (int i=1;i<=tot;i++) h[prime[i]]=i;
	return ;
}

int main()
{
	init();
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);rmx[n+1]=~(1<<31);
	for (int i=n;i;i--)
	{
		int x=a[i];int pt=1;
		now.reset();pre[i]=1;
		while (x!=1)
		{
			bool f=false;
			while (!(x%prime[pt])) f=true,x/=prime[pt];
			if (f){p[pt][i]=1;now|=p[pt];}
			if (!not_prime[x])
			{
				p[h[x]][i]=1;
				now|=p[h[x]];
				break;
			}
			++pt;
		}
		x=(pre^now)._Find_first();
		rmx[i]=min(rmx[i+1],x);
	}
	while (m--)
	{
		int l,r;
		scanf("%d %d",&l,&r);
		if (rmx[l]<=r) puts("S");
		else puts("N");
	}
	return 0;
}