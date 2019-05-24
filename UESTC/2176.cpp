#include <bits/stdc++.h>
#define MAXN 1000010
using namespace std;

int n,a[MAXN],dp[MAXN],f[MAXN],g[MAXN],ans;

inline int binary(int x)
{
	int l=0,r=ans,m;
	while (l<=r)
	{
		m=l+r>>1;
		if (dp[m]<x) l=m+1;
		else r=m-1;
	}
	return l;
}

inline void read(int &x)
{
	x=0;char ch=getchar();bool f=false;
	while (ch<'0'||ch>'9'){if (ch=='-') f=true;ch=getchar();}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	if (f) x=-x;return ;
}

int main()
{
	memset(dp,0x7f,sizeof dp);
	read(n);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i<=n;i++)
	{
		int p=lower_bound(dp+1,dp+n+1,a[i])-dp;
		f[i]=p;dp[p]=a[i];
	}
	memset(dp,0x7f,sizeof dp);
	for (int i=n;i;i--)
	{
		int p=lower_bound(dp+1,dp+n+1,a[i])-dp;
		g[i]=p;dp[p]=a[i];
	}
	for (int i=1;i<=n;i++) ans=max(ans,2*min(f[i],g[i])-1);
	printf("%d\n",ans);
	return 0;
}
