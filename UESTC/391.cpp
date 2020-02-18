#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int T,n,f[MAXN],ans;
vector <int> g[MAXN];

inline void dfs(int x,int fa)
{
	for (auto v:g[x])
		if (v!=fa)
		{
			dfs(v,x);
			if (f[v]>0) f[x]+=f[v],ans=max(ans,f[x]);
		}
	return ;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);ans=1<<31;
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&f[i]);ans=max(ans,f[i]);
			g[i].clear();
		}
		for (int i=1,x,y;i<n;i++)
		{
			scanf("%d %d",&x,&y);
			g[x].push_back(y);g[y].push_back(x);
		}
		dfs(1,-1);printf("%d\n",ans);
	}
	return 0;
}