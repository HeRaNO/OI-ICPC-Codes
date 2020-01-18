#include <bits/stdc++.h>
#define MAXN 100005
#define MAXK 6
using namespace std;

int n,m,q,k,x,y,f[MAXN],in[MAXN],out[MAXN];
bool g[MAXN][MAXK],vis[MAXN][MAXK];

int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

int main()
{
	scanf("%d %d",&n,&k);
	for (int i=1;i<=n;i++) f[i]=i;
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d %d",&x,&y);
		g[min(x,y)][abs(x-y)]=true;
	}
	for (int i=1;i<=k;i++)
		for (int j=1;j+i<=n;j++)
			if (g[j][i])
			{
				int fx=getf(j),fy=getf(i+j);
				if (fx!=fy)
				{
					f[fy]=fx;vis[j][i]=true;
				}
			}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=k;j++)
			if (vis[i][j])
			{
				++out[i];++in[i+j];
			}
	for (int i=1;i<=n;i++) in[i]+=in[i-1],out[i]+=out[i-1];
	scanf("%d",&q);
	while (q--)
	{
		scanf("%d %d",&x,&y);
		int ans=y-x+1,cnt=in[y]-out[x-1];
		for (int i=x-1;i+k>y;i--)
			for (int j=k;i+j>y;j--)
				if (vis[i][j]) ++cnt;
		printf("%d\n",ans-cnt);
	}
	return 0;
}
