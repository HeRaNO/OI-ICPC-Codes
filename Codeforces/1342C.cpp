#include <bits/stdc++.h>
#define MAXN 40005
using namespace std;

int T,a,b,q;
long long l,r,dp[MAXN];

long long f(long long x)
{
	return dp[a*b]*(x/(a*b))+dp[x%(a*b)];
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d %d",&a,&b,&q);
		for (int i=1;i<=a*b;i++)
		{
			dp[i]=(((i%a)%b)!=((i%b)%a));
			dp[i]+=dp[i-1];
		}
		for (int i=1;i<=q;i++)
		{
			scanf("%lld %lld",&l,&r);
			printf("%lld%c",f(r)-f(l-1),i==q?'\n':' ');
		}
	}
	return 0;
}