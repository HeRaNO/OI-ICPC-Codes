#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

struct link
{
	int to,nxt;
};

link e[MAXN<<1];
int head[MAXN<<1],cnt;
int n,m,u,v,f[MAXN],ori[MAXN<<1],a[MAXN<<1][3];
bool vis[MAXN<<1];

inline void add(int u,int v)
{
	e[cnt]=(link){v,head[u]};head[u]=cnt++;
	e[cnt]=(link){u,head[v]};head[v]=cnt++;
}

inline int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

inline void addans(int x,int y,int z)
{
	int pt=++a[0][0];
	a[pt][0]=ori[x];a[pt][1]=ori[y];a[pt][2]=ori[z];
	return ;
}

inline int dfs(int x)
{
	vis[x]=true;int son=-1;
	for (int i=head[x];~i;i=e[i].nxt)
		if (!vis[e[i].to])
		{
			int y=dfs(e[i].to);
			if (~y) addans(x,e[i].to,y);
			else
			{
				if (!~son) son=e[i].to;
				else
				{
					addans(son,x,e[i].to);
					son=-1;
				}
			}
		}
	return son;
}

int main()
{
	memset(head,-1,sizeof head);
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++) f[i]=ori[i]=i;
	for (int i=n+1;i<=n+m;i++) ori[i]=i;
	for (int i=1;i<=m;i++)
	{
		scanf("%d %d",&u,&v);
		int fx=getf(u),fy=getf(v);
		if (fx!=fy) f[fy]=fx;
		else ori[++n]=v,v=n;
		add(u,v);
	}
	for (int i=1;i<=n;i++) if (!vis[i]) dfs(i);
	printf("%d\n",a[0][0]);
	for (int i=1;i<=a[0][0];i++) printf("%d %d %d\n",a[i][0],a[i][1],a[i][2]);
	return 0;
}