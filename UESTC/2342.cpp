#include <bits/stdc++.h>
#define MAXN 55
using namespace std;

int n;
long long dp[MAXN][2];
char s[MAXN][2];

int main()
{
	scanf("%d",&n);dp[1][0]=1;
	for (int i=1;i<=n;i++) scanf("%s",s[i]);
	for (int i=1;i<=n;i++)
		if (s[i][0]==s[i][1]&&s[i][0]=='x')
			return puts("NO"),0;
	for (int i=1;i<n;i++)
		if ((s[i][0]=='x'&&s[i+1][1]=='x')||(s[i][1]=='x'&&s[i+1][0]=='x'))
			return puts("NO"),0;
	for (int i=2;i<=n;i++)
	{
		if (s[i][0]=='.') dp[i][0]=dp[i-1][0]+dp[i-1][1];
		if (s[i][1]=='.') dp[i][1]=dp[i-1][0]+dp[i-1][1];
	}
	printf("YES\n%lld\n",dp[n][0]+dp[n][1]);
	return 0;
}