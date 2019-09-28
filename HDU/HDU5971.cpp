#include <bits/stdc++.h>
#define MAXN 1005
using namespace std;

vector <int> e[MAXN];
int n,m,x,y,u,v,col[MAXN],sta[MAXN];
bool ok,vis[MAXN];

void dfs(int x, int c)
{
	col[x] = c;
	for (int i = 0; i < e[x].size(); i++)
	{
		if (col[e[x][i]] == c)
		{
			ok = false;
			return ;
		}
		if (!col[e[x][i]])
		{
			if (sta[e[x][i]] && sta[x] == sta[e[x][i]]) ok = false;
			dfs(e[x][i], 3 - c);
		}
	}
	return ;
}

int main()
{
	while(~scanf("%d%d%d%d",&n,&m,&x,&y))
	{
		ok=true;int cnt=0;
		memset(vis,false,sizeof vis);
		memset(col,0,sizeof col);
		memset(sta,0,sizeof sta);
		for (int i=1;i<=n;i++) e[i].clear();
		for (int i=1;i<=m;i++)
		{
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
			vis[v]=vis[u]=true;
		}
		for (int i=1;i<=x;i++)
		{
			scanf("%d",&u);
			sta[u]=1;vis[u]=true;
		}
		for (int i=1;i<=y;i++)
		{
			scanf("%d",&u);
			sta[u]=2;vis[u]=true;
		}
		for (int i=1;i<=n;i++) if (vis[i]) ++cnt;
		if (cnt<n)
		{
			puts("NO");continue;
		}
		for (int i=1;i<=n&&ok;i++) if (!col[i]) dfs(i,1);
		puts(ok?"YES":"NO");
	}
	return 0;
}