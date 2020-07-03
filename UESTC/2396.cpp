#include <bits/stdc++.h>
#define MAXN 200005
#define plli pair<long long,int>
#define pill pair<int,long long>
using namespace std;

int n,m,u,v,S;
long long w,dis[MAXN];
bool vis[MAXN];
priority_queue<plli, vector<plli>, greater<plli> > q;
vector <pill> g[MAXN];

inline void Dijkstra()
{
	memset(dis,0x3f,sizeof dis);dis[S]=0;q.push({0LL,S});
	while (!q.empty())
	{
		int x=q.top().second;q.pop();
		if (vis[x]) continue;vis[x]=true;
		for (auto v:g[x])
			if (dis[v.first]>dis[x]+v.second)
			{
				dis[v.first]=dis[x]+v.second;
				q.push({dis[v.first],v.first});
			}
	}
	return ;
}

template <typename T> void read(T &x)
{
	x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return ;
}

int main()
{
	read(n);read(m);
	for (int i=1;i<=m;i++)
	{
		read(u);read(v);read(w);w<<=1;
		g[u].push_back({v,w});g[v].push_back({u,w});
	}
	for (int i=1;i<=n;i++) read(w),g[S].push_back({i,w});
	Dijkstra();
	for (int i=1;i<=n;i++) printf("%lld%c",dis[i],i==n?'\n':' ');
	return 0;
}