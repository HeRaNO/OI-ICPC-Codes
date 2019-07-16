#include <bits/stdc++.h>
#define MAXN 105
using namespace std;

int T,n,m,u,v,in[MAXN],out[MAXN];
bool g[MAXN][MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&n,&m);
		memset(g,false,sizeof g);memset(in,0,sizeof in);memset(out,0,sizeof out);
		for (int i=1;i<=m;i++)
		{
			scanf("%d %d",&u,&v);
			g[u][v]=true;
		}
		for (int k=1;k<=n;k++)
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++)
					g[i][j]|=g[i][k]&g[k][j];
		bool f=true;
		for (int i=1;i<=n&&f;i++) if (g[i][i]) f=false;
		for (int i=1;i<=n&&f;i++)
			for (int j=1;j<=n&&f;j++)
				if (g[i][j]&&g[j][i]) f=false;
		if (!f)
		{
			for (int i=1;i<=n;i++) putchar('0');
		}
		else
		{
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++)
					if (g[i][j])
					{
						++in[j];++out[i];
					}
			for (int i=1;i<=n;i++)
			{
				if (in[i]>(n>>1)||out[i]>(n>>1)) putchar('0');
				else putchar('1');
			}
		}
		putchar('\n');
	}
	return 0;
}