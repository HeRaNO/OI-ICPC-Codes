#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

int n,mx,a[MAXN],b[MAXN],f[MAXN],g[MAXN],c[MAXN],_0[MAXN],d[MAXN];
long long ans;

inline int Binary(int x)
{
	int l=1,r=mx;
	while (l<=r)
	{
		int m=l+r>>1;
		if (b[m]<x) l=m+1;
		else r=m-1;
	}
	return l;
}

int main()
{
	while (~scanf("%d",&n))
	{
		memset(c,0,sizeof c);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		b[mx=0]=1<<31;
		for (int i=1;i<=n;i++)
			if (a[i])
			{
				if (a[i]>b[mx]){b[++mx]=a[i];f[i]=mx;}
				else b[f[i]=Binary(a[i])]=a[i];
			}
			else f[i]=0;
		b[mx=0]=1<<31;
		for (int i=n;i;i--)
			if (a[i])
			{
				if (-a[i]>b[mx]){b[++mx]=-a[i];g[i]=mx;}
				else b[g[i]=Binary(-a[i])]=-a[i];
			}
			else g[i]=0;
		ans=1LL*n*(n+1)/2*mx;
		memset(b,0,sizeof b);
		for (int i=n;i>0;i--)
		{
			int pt=i;
			for (;i;i--)
			{
				if (!a[i]){b[0]=n+1;break;}
				if (b[mx-f[i]]>a[i]+1)
				{
					++c[a[i]+1];--c[b[mx-f[i]]];
				}
			}
			for (int j=pt;j>i;j--) if (b[g[j]]<a[j]) b[g[j]]=a[j];
			if (b[mx]-1>a[i]&&i>0)
			{
				++c[a[i]+1];--c[b[mx]];
			}
		}
		for (int i=1;i<=n;i++)
		{
			c[i]+=c[i-1];
			if (c[i]!=0) ans+=i;
		}
		printf("%lld\n",ans);
	}
	return 0;
}