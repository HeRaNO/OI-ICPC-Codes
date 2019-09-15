#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;

int T,b,n,cas;
long long ans[MAXN][11];

inline long long f(int n,int b)
{
	long long ans=0;
	while (n)
	{
		ans+=n%b;
		n/=b;
	}
	return ans;
}

int main()
{
	scanf("%d",&T);
	for (int i=1;i<=1000000;i++)
		for (int j=2;j<=10;j++)
			ans[i][j]=ans[i-1][j]+f(i,j);
	while (T--)
	{
		scanf("%d %d",&n,&b);
		printf("Case #%d: %lld\n",++cas,ans[n][b]);
	}
	return 0;
}