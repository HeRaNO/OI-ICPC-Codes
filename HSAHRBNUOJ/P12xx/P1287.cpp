#include <cstdio>
#define MAXN 16
#define MAXK 15
using namespace std;

int n,k,x;long long f[MAXN][MAXK],a[MAXN];

inline long long max(long long a,long long b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}

int main()
{
	scanf("%d %d",&n,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);a[i]=a[i-1]+x;f[i][0]=a[i];
		for (int j=1,p=min(i-1,k);j<=p;j++)
			for (int k=1;k<i;k++)
				f[i][j]=max(f[i][j],f[k][j-1]*(a[i]-a[k]));
	}
	printf("%lld\n",f[n][k]);
	return 0;
}
