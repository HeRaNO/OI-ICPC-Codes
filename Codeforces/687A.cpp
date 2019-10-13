#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int INF=~(1<<31),MAXN=3e5+10;
 
int head[MAXN],to[MAXN],_next[MAXN],cnt;
int col[MAXN];
bool vis[MAXN];
 
void add_Edge(int u,int v)
{
	_next[++cnt]=head[u];
	to[cnt]=v;
	head[u]=cnt;
}
 
void dfs(int u)
{
	vis[u]=1;
	for(int i=head[u];i;i=_next[i])
	{
		int v=to[i];
		if(!col[v])col[v]=3-col[u];
		else if(col[v]!=3-col[u])
		{
			puts("-1");
			exit(0);
		}
		if(!vis[v])
		dfs(v);
	}
}
 
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add_Edge(u,v);
		add_Edge(v,u);
	}
	for(int i=1;i<=n;i++)
		if(!col[i])
		{
			col[i]=1;
			dfs(i);
		}
	int ans=0;
	for(int i=1;i<=n;i++)
		if(col[i]==1)
			ans++;
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
		if(col[i]==1)printf("%d ",i);
	printf("\n%d\n",n-ans);
	for(int i=1;i<=n;i++)
		if(col[i]==2)printf("%d ",i);
	return 0;
}