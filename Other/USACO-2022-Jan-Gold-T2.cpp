#include <bits/stdc++.h>
#define MAXN 100005
#define MAXQ 200005
using namespace std;

int n,q,ans[MAXN],D[MAXQ];
bool active[MAXN],ban[MAXQ];
char opt[3];
pair<int,int> R[MAXQ];
vector<pair<int,int>> edges;
vector<int> g[MAXN];

void dfs(int x,int t)
{
	if (ans[x]) return ; ans[x]=t;
	for (int v:g[x]) dfs(v,t);
	return ;
}

int main()
{
	scanf("%d %d",&n,&q);
	for (int i=1;i<=n;i++) active[i]=true;
	for (int i=0,x,y;i<q;i++)
	{
		scanf("%s",opt);
		if (opt[0]=='A')
		{
			scanf("%d %d",&x,&y);
			edges.push_back({x,y});
		}
		else
		{
			scanf("%d",&x);
			if (opt[0]=='D')
			{
				D[i]=x;
				active[x]=false;
			}
			else
			{
				R[i]=edges[x-1];
				ban[x-1]=true;
			}
		}
	}
	for (int i=0;i<edges.size();i++)
		if (!ban[i])
		{
			int u,v;tie(u,v)=edges[i];
			g[u].push_back(v);g[v].push_back(u);
		}
	for (int i=1;i<=n;i++)
		if (active[i]) dfs(i,q);
	for (int now=q-1;now;now--)
	{
		if (D[now]) dfs(D[now],now);
		else if (R[now]!=R[0])
		{
			int u,v;tie(u,v)=R[now];
			g[u].push_back(v);g[v].push_back(u);
			if (ans[u]||ans[v])
			{
				dfs(u,now);dfs(v,now);
			}
		}
	}
	for (int i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}