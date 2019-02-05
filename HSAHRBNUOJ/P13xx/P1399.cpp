#include <cstdio>
#include <cstring>
#define MAXN 205
using namespace std;

int n,m,u,v,w,g[MAXN][MAXN],a[MAXN][MAXN];
bool f=true,ans[MAXN];

inline int min(int a,int b){return a<b?a:b;}

int main()
{
	memset(g,0x3f,sizeof g);
	scanf("%d %d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		g[u][v]=g[v][u]=min(g[u][v],w);a[v][u]=a[u][v]=w;
	}
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
		{
			int M=g[i][j],p,cnt=0;
			if (M==a[i][j]||M==0x3f3f3f3f) continue;
			for (int k=1;k<=n&&cnt<=1;k++)
				if (g[i][j]==g[i][k]+g[k][j])
				{
					++cnt;p=k;
				}
			if (cnt!=1) continue;
			ans[p]=true;
		}
	for (int i=1;i<=n;i++)
		if (ans[i])
		{
			if (f){printf("%d",i);f=false;}
			else printf(" %d",i);
		}
	if (f) puts("No important cities.");
	else putchar('\n');
	return 0;
}