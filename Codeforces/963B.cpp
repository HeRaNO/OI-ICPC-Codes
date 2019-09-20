#include <bits/stdc++.h>
using namespace std;
const int N=200050;

int n;
int siz[N];
struct edge
{
	int v;
	int nxt;
}e[N<<1];
int head[N],ecnt;

inline void ad(int u,int v)
{
	e[++ecnt].v=v;e[ecnt].nxt=head[u];head[u]=ecnt;
}

void dfs1(int u,int fa)
{
	siz[u]=1;
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa)continue;
		dfs1(v,u);
		siz[u]+=siz[v];
	}
}

void dfs2(int u,int fa)
{
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa)continue;
		if(siz[v]%2==0)dfs2(v,u);
	}
	cout<<u<<endl;
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa)continue;
		if(siz[v]%2)dfs2(v,u);
	}
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		int x;cin>>x;
		if(x)ad(x,i),ad(i,x);
	}
	if(n&1)puts("YES");
	else return puts("NO"),0;
	dfs1(1,0);
	dfs2(1,0);
	return 0;
}