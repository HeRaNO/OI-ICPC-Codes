#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

int n,m,u,v,x,ans,dis[MAXN],cnt[MAXN];
bool vis[MAXN];
vector <int> g[MAXN];
queue <int> q;

inline void BFS()
{
	while (!q.empty())
	{
		int x=q.front();q.pop();
		for (auto v:g[x])
			if (!dis[v]||dis[v]==dis[x]+1)
			{
				cnt[v]+=cnt[x];dis[v]=dis[x]+1;
				if (cnt[v]==m){ans=v;return ;}
				if (!vis[v]){q.push(v);vis[v]=true;}
			}
	}
	return ;
}

int main()
{
	scanf("%d %d",&n,&m);
	for (int i=1;i<n;i++)
	{
		scanf("%d %d",&u,&v);
		g[u].push_back(v);g[v].push_back(u);
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%d",&x);
		dis[x]=1;vis[x]=true;cnt[x]=1;
		q.push(x);
	}
	if (m==1) return printf("YES\n%d\n",x),0;
	BFS();
	if (!ans) puts("NO");
	else printf("YES\n%d\n",ans);
	return 0;
}