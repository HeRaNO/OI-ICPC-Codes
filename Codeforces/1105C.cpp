#include <bits/stdc++.h>
#define M 1000000007LL
#define MAXN 200010
using namespace std;

int n,l,r;
long long dp[MAXN][3];

int main()
{
	scanf("%d %d %d",&n,&l,&r);
	int l1,l2,l0;
	l1=l2=l0=r/3;
	int p=r%3;
	if (p==1) l1++;
	else if (p==2) {l1++;l2++;}
	--l;
	p=l%3;
	dp[1][0]=l0-l/3;dp[1][1]=l1-l/3;dp[1][2]=l2-l/3;
	if (p==1) dp[1][1]--;
	else if (p==2) {dp[1][1]--;dp[1][2]--;}
	for (int i=1;i<n;i++)
		for (int j=0;j<3;j++)
			for (int k=0;k<3;k++)
				(dp[i+1][(j+k)%3]+=(dp[i][j]*dp[1][k])%M)%=M;
	printf("%I64d\n",dp[n][0]);
	return 0;
}