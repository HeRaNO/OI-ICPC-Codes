#include <cstdio>
#define MAXN 1100
using namespace std;

int n,m,k;
int a[MAXN],b[MAXN];
int dp[MAXN][MAXN],u[MAXN][MAXN],v[MAXN][MAXN];

int mymax(int a,int b)
{
    return a>b?a:b;
}

int main()
{
    freopen("crossa.in","r",stdin);freopen("crossa.out","w",stdout);
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for (int i=1;i<=m;i++)
        scanf("%d",&b[i]);
    for (int i=1;i<=n;i++)
        for (int j=2;j<=m;j++)
    {
        if (a[i]==b[j-1]) v[i][j]=j-1;
        else v[i][j]=v[i][j-1];
    }
    for (int j=1;j<=m;j++)
        for (int i=2;i<=n;i++)
    {
        if (a[i-1]==b[j]) u[i][j]=i-1;
        else u[i][j]=u[i-1][j];
    }
    for (int i=2;i<=n;i++)
        for (int j=2;j<=m;j++)
    {
        dp[i][j]=mymax(dp[i-1][j],dp[i][j-1]);
        if (a[i]!=b[j]&&u[i][j]&&v[i][j])
            dp[i][j]=mymax(dp[i][j],dp[u[i][j]-1][v[i][j]-1]+2);
    }
    printf("%d",dp[n][m]);
    return 0;
}
