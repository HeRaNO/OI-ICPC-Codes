#include <bits/stdc++.h>
#define MAXN 1005
using namespace std;

int n,rt,mx,qcnt,dis[MAXN],T,P,Q;
vector <int> g[MAXN];
bool vis[MAXN];

bool dfs(int x,int f)
{
	if (vis[x]) return true;
	dis[x]=dis[f]+1;
	for (auto v:g[x]) if(v!=f&&dfs(v,x)) return vis[x]=1;
	if (dis[mx]<dis[x]) mx=x;
	return 0;
}

void dfsL(int x,int f)
{
	for (auto v:g[x]) if (v!=f) dis[v]=dis[x]+1,dfsL(v,x);
	return ;
}

inline int ask(int x,int y)
{
	printf("? %d %d\n",x,y);fflush(stdout);
	vis[x]=vis[y]=true;
	int z;scanf("%d",&z);return z;
}

int main()
{
	scanf("%d",&n);
	for (int i=1,u,v;i<n;i++)
	{
		scanf("%d %d",&u,&v);
		g[u].push_back(v);g[v].push_back(u);
	}
	dfsL(1,-1);
	for (int i=1;i<=n;i++) if (dis[P]<dis[i]) P=i;
	memset(dis,0,sizeof dis);dfsL(P,-1);
	for (int i=1;i<=n;i++) if (dis[Q]<dis[i]) Q=i;
	rt=ask(P,Q);
	for(int i=1;i<=n/2;i++)
	{
		int q=rt,p=rt;
		memset(dis,0,sizeof(dis));
		int cnt=g[rt].size();
		for (auto j:g[rt])
		{
			mx=0;
			if (dfs(j,rt)) --cnt;
			else if (dis[q]<=dis[mx])
			{
				p=q;
				q=mx;
			}
		}
		if (!cnt)
		{
			printf("! %d\n",rt);
			return 0;
		}
		rt=ask(p,q);
	}
	assert(false);
	return 0;
}