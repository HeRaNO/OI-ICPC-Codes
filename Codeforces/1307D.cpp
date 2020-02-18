#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

int n,m,k,u,v,a[MAXN],dis1[MAXN],dis2[MAXN],now=-1e9,ans;
vector <int> g[MAXN];
queue <int> q;

inline void BFS(int S,int dis[])
{
	q.push(S);dis[S]=0;
	while (!q.empty())
	{
		int x=q.front();q.pop();
		for (auto v:g[x])
			if (dis[v]==0x3f3f3f3f)
			{
				dis[v]=dis[x]+1;
				q.push(v);
			}
	}
	return ;
}

inline bool cmp(int a,int b)
{
	return dis1[a]-dis2[a]<dis1[b]-dis2[b];
}

int main()
{
	memset(dis1,0x3f,sizeof dis1);
	memset(dis2,0x3f,sizeof dis2);
	scanf("%d %d %d",&n,&m,&k);
	for (int i=1;i<=k;i++) scanf("%d",&a[i]);
	for (int i=1;i<=m;i++)
	{
		scanf("%d %d",&u,&v);
		g[u].push_back(v);g[v].push_back(u);
	}
	BFS(1,dis1);BFS(n,dis2);sort(a+1,a+k+1,cmp);
	for (int i=1;i<=k;i++)
	{
		ans=max(ans,now+dis2[a[i]]);
		now=max(now,dis1[a[i]]);
	}
	printf("%d\n",min(dis1[n],ans+1));
	return 0;
}