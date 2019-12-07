#include <bits/stdc++.h>
using namespace std;

double dp[2][1050];
int n;
double k;

int main()
{
	cin>>n>>k;
	int t=1;
	for(int i=1;i<=n;++i)
	{
		t^=1;
		for(int j=min(n,1000);j>0;j--)
			dp[t][j]=dp[t^1][j]*(k-1)/k+(1.0/k)*((dp[t^1][j+1]+1.0*j)/(j+1.0)+j*(dp[t^1][j]+(1.0+j)/2.0)/(j+1.0));
	}
	printf("%.12lf\n",k*dp[t][1]);
	return 0;
}