#include <bits/stdc++.h>
#define MAXN 20
using namespace std;

int n,s,p;
long long x[MAXN],y[MAXN],dp[1<<18][MAXN],ans;

inline long long len(int m,int n)
{
	return abs(x[m]-x[n])+abs(y[m]-y[n]);
}

void dfs(int sta,int p)
{
	for (int i=1;i<=n;i++)
		if (!(sta&(1<<(i-1))))
		{
			if (dp[sta|(1<<(i-1))][i]>dp[sta][p]+len(p,i))
			{
				dp[sta|(1<<(i-1))][i]=dp[sta][p]+len(p,i);
				dfs(sta|(1<<(i-1)),i);
			}
		}
	return ;
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
	memset(dp,0x3f,sizeof dp);ans=~(1LL<<63);
	read(n);read(s);
	for (int i=1;i<=n;i++)
	{
		read(p);x[i]=p;read(p);y[i]=p;
	}
	dp[1<<(s-1)][s]=0LL;
	dfs(1<<(s-1),s);
	for (int i=1;i<=n;i++) ans=min(ans,dp[(1<<n)-1][i]);
	printf("%lld\n",ans);
	return 0;
}
