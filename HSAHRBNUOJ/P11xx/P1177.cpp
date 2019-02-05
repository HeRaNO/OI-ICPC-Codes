#include <cstdio>
#include <cstring>
#define MAXN 2000
using namespace std;

char a[MAXN],b[MAXN];
int f[MAXN][MAXN],n,m,ans;

inline int max(int a,int b){return a>b?a:b;}

int main()
{
	scanf("%s",a+1);scanf("%s",b+1);n=strlen(a+1);m=strlen(b+1);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			if (a[i]==b[j]) f[i][j]=f[i-1][j-1]+1;
			else f[i][j]=max(f[i-1][j],f[i][j-1]);
			ans=max(ans,f[i][j]);
		}
	printf("%d\n",ans);
	return 0;
}
