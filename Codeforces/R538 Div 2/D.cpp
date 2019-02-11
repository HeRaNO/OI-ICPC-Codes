#include <cstdio>
#include <cstring>
#define MAXN 5005

int n,a[MAXN],f[MAXN][MAXN][2];

inline int min(int a,int b){return a<b?a:b;}

int main()
{
	memset(f,0x3f,sizeof f);
	scanf("%d",&n);for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) f[i][i][0]=f[i][i][1]=0;
	for (int j=1;j<=n;j++)
		for (int i=j;i;i--)
		{
			if (i>1)
			{
				f[i-1][j][0]=min(f[i-1][j][0],f[i][j][0]+(a[i]!=a[i-1]));
				f[i-1][j][0]=min(f[i-1][j][0],f[i][j][1]+(a[j]!=a[i-1]));
			}
			if (j<n)
			{
				f[i][j+1][1]=min(f[i][j+1][1],f[i][j][0]+(a[i]!=a[j+1]));
				f[i][j+1][1]=min(f[i][j+1][1],f[i][j][1]+(a[j]!=a[j+1]));
			}
		}
	printf("%d\n",min(f[1][n][0],f[1][n][1]));
	return 0;
}