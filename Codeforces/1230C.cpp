#include <bits/stdc++.h>
using namespace std;

int n,m,u,v;
int e[8][8],g[10][10],s[10];

int dfs(int depth)
{
	int ans=0;
	if (!depth)
	{
		memset(e,0,sizeof(e));
		for(int i=1;i<=7;i++)
			for(int j=1;j<=7;j++)
			{
				if(g[i][j]&&!e[s[i]][s[j]])
				{
					e[s[i]][s[j]]=e[s[j]][s[i]]=1;
					ans++;
				}
			}
		return ans;
	}
	for (int i=1;i<=6;i++)
	{
		s[depth]=i;
		ans=max(ans,dfs(depth-1));
	}
	return ans;
}

int main()
{
	scanf("%d%d",&n,&m);
	if (n<=6) return printf("%d\n",m),0;
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		g[u][v]=g[v][u]=1;
	}
	printf("%d\n",dfs(7));
	return 0;
}