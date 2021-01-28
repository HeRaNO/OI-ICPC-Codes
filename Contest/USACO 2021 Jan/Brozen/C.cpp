#include <bits/stdc++.h>
#define MAXN 25
using namespace std;

int n,a[MAXN],b[MAXN],g[MAXN];
long long dp[1<<20|5];

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	for (int i=0;i<n;i++) scanf("%d",&b[i]);
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			if (a[i]<=b[j]) g[i]|=(1<<j);
	for (int i=0;i<n;i++)
		if (g[0]&(1<<i)) dp[1<<i]=1;
	for (int i=0;i<(1<<n);i++)
	{
		int x=__builtin_popcount(i);
		for (int j=0;j<n;j++)
			if (g[x]&(1<<j)&&!(i&(1<<j)))
				dp[i|(1<<j)]+=dp[i];
	}
	printf("%lld\n",dp[(1<<n)-1]);
	return 0;
}