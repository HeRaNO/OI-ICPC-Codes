#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXN 15
using namespace std;

int n,sum;
int a[MAXN];
int b[MAXN][MAXN],c[MAXN][MAXN];
bool used[MAXN];

void dfs(int dep,int he)
{
	if (he<0) return ;
	if (dep==n+1)
	{
		if (he>0) return ;
		else
		{
			for (int i=1;i<n;i++) printf("%d ",a[i]);
			printf("%d\n",a[n]);
			exit(0);
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (!used[i])
		{
			a[dep]=i;
			used[i]=true;
			dfs(dep+1,he-i*c[n][dep]);
			used[i]=false;
		}
	}
}

int main()
{
	freopen("bds.in","r",stdin);freopen("bds.out","w",stdout);
	memset(used,false,sizeof(used));
	scanf("%d %d",&n,&sum);
	for (int i=1;i<=n;i++)
	{
		c[i][1]=c[i][i]=1;
		for (int j=2;j<i;j++)
			c[i][j]=c[i-1][j]+c[i-1][j-1];
	}
	dfs(1,sum);
	return 0;
}