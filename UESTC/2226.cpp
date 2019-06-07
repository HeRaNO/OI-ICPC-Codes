#include <bits/stdc++.h>
#define MAXN 10010
#define MAXM 20010
using namespace std;

struct link
{
	int to,val,nxt;
};

link e[MAXM];
int head[MAXN],cnt,ans;
int n,m,u,v,w,opt,dis[MAXN],num[MAXN];
bool vis[MAXN];
queue <int> q;

inline void add(int u,int v,int w)
{
	e[cnt]=(link){v,w,head[u]};head[u]=cnt++;
	return ;
}

void SPFA()
{
	q.push(0);dis[0]=0;
	while (!q.empty())
	{
		int x=q.front();q.pop();vis[x]=false;
		for (int i=head[x];~i;i=e[i].nxt)
			if (dis[e[i].to]<dis[x]+e[i].val)
			{
				dis[e[i].to]=dis[x]+e[i].val;
				if (!vis[e[i].to])
				{
					if (++num[e[i].to]==(n<<1))
					{
						puts("-1");exit(0);
					}
					vis[e[i].to]=true;
					q.push(e[i].to);
				}
			}
	}
	for (int i=1;i<=n;i++) ans+=dis[i];
	printf("%d\n",ans);
	return ;
}

int main()
{
	memset(head,-1,sizeof head);
	scanf("%d %d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&opt,&u,&v);
		if (u==v)
		{
			if (opt!=3) return puts("-1");
			else continue;
		}
		if (opt==2) add(u,v,1);
		else if (opt==1) add(v,u,1);
		else add(u,v,0),add(v,u,0);
	}
	for (int i=1;i<=n;i++) add(0,i,1);
	SPFA();
	return 0;
}