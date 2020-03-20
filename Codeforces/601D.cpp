#include <bits/stdc++.h>
#define MAXN 300005
using namespace std;

int n,tot,cnt,ans,u,v,a[MAXN],son[MAXN][26],siz[MAXN];
char s[MAXN];
vector <int> g[MAXN];

inline void add(int u,int v)
{
	g[u].push_back(v);g[v].push_back(u);
	return ;
}

inline int merge(int x,int y)
{
	int nxt=s[y]-'a',siz=1;
	if (!son[x][nxt]){son[x][nxt]=y;return 0;}
	for (int i=0;i<26;i++)
		if (son[y][i]) siz+=merge(son[x][nxt],son[y][i]);
	return siz;
}

inline void dfs(int x,int fa)
{
	siz[x]=1;
	for (auto v:g[x])
		if (v!=fa)
		{
			dfs(v,x);
			siz[x]+=siz[v]-merge(x,v);
		}
	if (a[x]+siz[x]>ans)
	{
		ans=a[x]+siz[x];
		cnt=1;
	}
	else if (a[x]+siz[x]==ans) ++cnt;
	return ;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%s",s+1);
	for (int i=1;i<n;i++) scanf("%d %d",&u,&v),add(u,v);
	dfs(1,-1);
	printf("%d\n%d\n",ans,cnt);
	return 0;
}