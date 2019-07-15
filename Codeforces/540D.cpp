#include <bits/stdc++.h>
#define MAXN 105
using namespace std;

double dp[MAXN][MAXN][MAXN];
int a,b,c;

long long C(int x){return 1LL*x*(x-1)/2;}

int main()
{
	scanf("%d %d %d",&a,&b,&c);
	dp[a][b][c]=1.0;
	for (int i=a;~i;i--)//r
		for (int j=b;~j;j--)//s
			for (int k=c;~k;k--)//p
			{
				if (k>=1&&j>=1) dp[i][j][k-1]+=dp[i][j][k]*(double)(j*k)/(i*k+j*k+j*i);
				if (j>=1&&i>=1) dp[i][j-1][k]+=dp[i][j][k]*(double)(j*i)/(i*k+j*k+j*i);
				if (i>=1&&k>=1) dp[i-1][j][k]+=dp[i][j][k]*(double)(i*k)/(i*k+j*k+j*i);
			}
	double r=0,s=0,p=0;
	for (int i=1;i<=a;i++) r+=dp[i][0][0];
	for (int i=1;i<=b;i++) s+=dp[0][i][0];
	for (int i=1;i<=c;i++) p+=dp[0][0][i];
	printf("%.10lf %.10lf %.10lf\n",r,s,p);
	return 0;
}
