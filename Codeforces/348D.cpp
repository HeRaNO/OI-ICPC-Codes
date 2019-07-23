#include <cstdio>
#define MAXN 3005
using namespace std;

const long long M=1e9+7;

int n,m;
long long f[MAXN][MAXN],g[MAXN][MAXN];
char a[MAXN][MAXN];

int main()
{
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%s",a[i]+1);
	f[1][2]=a[1][2]=='.';
	g[2][1]=a[2][1]=='.';
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (a[i][j]=='.')
			{
				f[i][j]+=(f[i-1][j]+f[i][j-1])%M;
				g[i][j]+=(g[i-1][j]+g[i][j-1])%M;
			}
	long long p=f[n][m-1]*g[n-1][m]%M;
	long long q=f[n-1][m]*g[n][m-1]%M;
	printf("%lld\n",(q-p+M)%M);
	return 0;
}