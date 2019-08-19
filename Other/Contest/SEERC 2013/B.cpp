#include <bits/stdc++.h>
#define MAXN 500010
#define MAXM 500010
using namespace std;

set <int> g[MAXN];
int n,k,u,v,a,b,dis[MAXN],l[MAXN],r[MAXN];
queue <int> q;
set <int> :: iterator it;

inline void add(int u,int v)
{
	g[u].insert(v);g[v].insert(u);
	return ;
}

inline void BFS1(int S)
{
	memset(dis,-1,sizeof dis);q.push(S);dis[S]=0;
	while (!q.empty())
	{
		int x=q.front();q.pop();
		for (auto i:g[x])
			if (!~dis[i])
			{
				dis[i]=dis[x]+1;
				q.push(i);
			}
	}
	return ;
}

inline void BFS2(int S)
{
	memset(dis,-1,sizeof dis);
	for (int i=1;i<=n;i++) l[i]=i-1,r[i]=i+1;
	dis[S]=0;q.push(S);
	while (!q.empty())
	{
		int x=q.front();q.pop();
		for (int i=r[1];i<=n;i=r[i])
			if (!g[x].count(i))
			{
				dis[i]=dis[x]+1;q.push(i);
				l[r[i]]=l[i];r[l[i]]=r[i];
			}
	}
	return ;
}

inline int solve()
{
	if (a==b) return printf("%d\n",a),0;
	for (int i=1;i<=k;i++)
	{
		scanf("%d %d",&u,&v);
		add(u,v);
	}
	if (a<b)
	{
		if (g[1].count(n)) printf("%d\n",a);
		else
		{
			BFS1(1);
			if (!~dis[n]) printf("%d\n",b);
			else printf("%lld\n",min((long long)b,1LL*dis[n]*a));
		}
	}
	else
	{
		if (!g[1].count(n)) printf("%d\n",b);
		else
		{
			BFS2(1);
			if (!~dis[n]) printf("%d\n",a);
			else printf("%lld\n",min((long long)a,1LL*dis[n]*b));
		}
	}
	return 0;
}

int main()
{
	while(~scanf("%d %d %d %d",&n,&k,&a,&b))
	{
		for (int i=1;i<=n;i++) g[i].clear();
		solve();
	}
	return 0;
}
