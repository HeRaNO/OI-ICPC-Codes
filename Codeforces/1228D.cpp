#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int c[MAXN],n,m,u,v;
bool p[MAXN];
vector <int> g[MAXN];
queue<int> q;

bool BFS()
{
	for (auto v:g[1]){c[v]=2;q.push(v);}
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for (auto v:g[u])
			if (c[v]==c[u])
			{
				if(c[v]==2) c[v]=3;
				else return false;
			}
	}
	for (int i=1;i<=n;i++)
		for (auto v:g[i]) if (c[v]==c[i]) return false;
	return true;
}

int num[4];

int main()
{
	scanf("%d %d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d %d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
		if (u==1) p[v]=1;
	}
	for (int i=1;i<=n;i++) if(!p[i]) c[i]=1;
	if (!BFS()) return puts("-1"),0;
	for (int i=1;i<=n;i++)
	{
		if(!c[i]) return puts("-1"),0;
		++num[c[i]];
	}
	long long ans=0;
	if(!num[1]||!num[2]||!num[3]) return puts("-1"),0;
	ans=1LL*num[1]*num[2]+1LL*num[2]*num[3]+1LL*num[1]*num[3];
	if (m!=ans) return puts("-1"),0;
	for (int i=1;i<=n;i++) printf("%d%c",c[i],i==n?'\n':' ');
	return 0;
}
