#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int n,f[MAXN];
vector <int> g[MAXN];

inline void add(int u,int v)
{
	g[u].push_back(v);g[v].push_back(u);
	return ;
}

inline void TreeDP(int x,int fa)
{
	f[x]=1;int cnt=0;
	for (auto v:g[x]) if (v!=fa) TreeDP(v,x),cnt+=f[v];
	f[x]=cnt>0?cnt-1:1;
	return ;
}

int main()
{
	scanf("%d",&n);
	for (int i=1,u,v;i<n;i++) scanf("%d %d",&u,&v),add(u,v);
	TreeDP(1,-1);
	puts(f[1]?"Alice":"Bob");
	return 0;
}