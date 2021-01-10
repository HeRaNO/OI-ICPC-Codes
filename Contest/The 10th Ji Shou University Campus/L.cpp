#include <bits/stdc++.h>
#define MAXN 21
using namespace std;

int n,k,a[MAXN];
short dp[1<<21][MAXN];

inline int len(int m,int n)
{
	return abs(a[m]-a[n]);
}

void dfs(int sta,int p)
{
	if (__builtin_popcount(sta)>k) return ;
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

inline void Solve()
{
	int ans=10000;
	scanf("%d %d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i<=n-k+1;i++)
	{
		int cnt=0;
		for (int j=i+1;j<i+k;j++) cnt+=a[j]-a[j-1];
		ans=min(ans,cnt*2);
	}
	printf("%d\n",ans);
	return ;
}

int main()
{
	int T;
	scanf("%d",&T);
	while (T--) Solve();
	return 0;
}