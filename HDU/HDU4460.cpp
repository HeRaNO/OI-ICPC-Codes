#include <bits/stdc++.h>
#define MAXN 1005
using namespace std;

string s,t;
int n,m,dis[MAXN];
bool vis[MAXN];
vector <int> g[MAXN];
queue <int> q;
map <string,int> mp;

inline int BFS(int x)
{
	memset(vis,0,sizeof vis);
	memset(dis,0,sizeof dis);
	q.push(x);
	while (!q.empty())
	{
		int u=q.front();q.pop();
		for (auto v:g[u])
		{
			if (vis[v]) continue;
			dis[v]=dis[u]+1;vis[v]=true;
			q.push(v);
		}
	}
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		if (!dis[i]&&i!=x) return ~(1<<31);
		ans=max(ans,dis[i]);
	}
	return ans;
}

int main()
{
	while (scanf("%d",&n)==1&&n)
	{
		int ans=0;mp.clear();
		for (int i=1;i<=n;i++)
		{
			cin>>s;mp[s]=i;
			g[i].clear();
		}
		scanf("%d",&m);
		for (int i=1;i<=m;i++)
		{
			cin>>s>>t;
			int u=mp[s],v=mp[t];
			g[u].push_back(v);g[v].push_back(u);
		}
		for (int i=1;i<=n;i++)
		{
			ans=max(ans,BFS(i));
			if (ans==~(1<<31)) break;
		}
		if (ans==~(1<<31)) ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}