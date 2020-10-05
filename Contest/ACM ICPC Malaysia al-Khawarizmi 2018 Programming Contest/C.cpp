#include <bits/stdc++.h>
using namespace std;
int n;
#define ll long long
ll dp[100];

int main()
{
	dp[1]=dp[2]=1;
	for(int i=3;i<100;++i)dp[i]=dp[i-2]+dp[i-3];
	int kase=0;
	while(cin>>n&&n)
	{
		printf("Case #%d: ",++kase);
		if(n<3)
		{
			printf("0\n");
			continue;
		}
		else if(n==3)
		{
			printf("1\n");
			continue;
		}
		printf("%lld\n",dp[n]+dp[n-1]);
	}
	return 0;
}