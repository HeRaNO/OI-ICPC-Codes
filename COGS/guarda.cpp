#include <cstdio>
#include <cstring>
#define MAXN 210
#define positive 200
using namespace std;

double dp[2][MAXN][2*MAXN];
double p[MAXN];
int a[MAXN];
int n,kk,l;
double ans=0.0;

int mymax(int a,int b)
{
	return a>b?a:b;
}

int mymin(int a,int b)
{
	return a<b?a:b;
}

int main()
{
	freopen("guarda.in","r",stdin);freopen("guarda.out","w",stdout);
	scanf("%d %d %d",&n,&l,&kk);
	for (int i=1;i<=n;i++) scanf("%lf",&p[i]);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	dp[1][1][mymax(kk+positive+a[1],n)]=p[1]/100.0;
	dp[1][0][kk+positive]=(100.0-p[1])/100.0;
	for (int i=2;i<=n;i++)
	{
		memset(dp[i&1],0,sizeof(double)*MAXN*MAXN*2);
		for (int j=0;j<=n;j++)
			for (int k=positive-i;k<=400;k++)
				{
					if (j>0)
						dp[i&1][j][k]+=(dp[i-1&1][j-1][mymin(k-a[i],400)]*p[i]/100.0);
					dp[i&1][j][k]+=(dp[i-1&1][j][k]*(100.0-p[i])/100.0);
				}
	}
	for (int i=l;i<=n;i++)
		for (int j=positive;j<=400;j++)
			ans+=dp[n&1][i][j];
	printf("%.6lf\n",ans);
	return 0;
}