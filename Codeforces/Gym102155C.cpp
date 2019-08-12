#include <bits/stdc++.h>
#define MAXN 1005
#define MAXM 10005
using namespace std;

struct link
{
	int to,nxt;	
};

link e[MAXM<<1];
int head[MAXN],cnt;
int n,m,u,v,f[MAXN];
vector <int> g[MAXN];
bool vis[MAXN];

inline void add(int u,int v)
{
	e[cnt]=(link){v,head[u]};head[u]=cnt++;
}

bool dfs(int x)
{
	for (int i=head[x];~i;i=e[i].nxt)
		if (!vis[e[i].to])
		{
			vis[e[i].to]=true;
			if (!~f[e[i].to]||dfs(f[e[i].to])){f[e[i].to]=x;return true;}
		}
	return false;
}

inline int Hungary()
{
	int ans=0;memset(f,-1,sizeof f);
	for (int i=1;i<=n;i++)
	{
		memset(vis,false,sizeof vis);
		if (dfs(i)) ++ans;
	}
	return ans;
}

inline bool Solve(int x)
{
	memset(head,-1,sizeof head);cnt=0;
	memset(vis,false,sizeof vis);
	for (int i=0;i<g[x].size();i++) vis[g[x][i]]=true;
	for (int i=0;i<g[x].size();i++)
	{
		int v=g[x][i];
		for (int j=0;j<g[v].size();j++)
			if (g[v][j]!=x&&!vis[g[v][j]]) add(v,g[v][j]);
	}
	if (Hungary()+g[x].size()+1!=n) return false;
	puts("Yes");
	printf("%d %d\n",x,g[x].size());
	memset(vis,false,sizeof vis);
	for (int i=1;i<=n;i++)
		if (i!=x&&~f[i])
		{
			printf("%d %d\n",i,f[i]);
			vis[i]=true;vis[f[i]]=true;
		}
	for (int i=1;i<=n;i++) if (i!=x&&!vis[i]) printf("%d -1\n",i);
	return true;
}

int main()
{
	scanf("%d %d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d %d",&u,&v);
		g[u].push_back(v);g[v].push_back(u);
	}
	for (int i=1;i<=n;i++)
		if (g[i].size()>=(n>>1))
			if (Solve(i)) return 0;
	puts("No");
	return 0;
}