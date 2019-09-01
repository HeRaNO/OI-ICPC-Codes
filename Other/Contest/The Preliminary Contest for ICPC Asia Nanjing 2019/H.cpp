#include <bits/stdc++.h>
#define MAXN 305
#define MAXM 510
using namespace std;

struct link
{
	int to;long long val;int nxt;
};

link e[MAXM];
int head[MAXN],cnt;
int n,m,u,v,w,T,pcnt[MAXN];
long long dis[MAXN];
bool flag,mark[MAXN];
queue <int> q;

inline void add(int u,int v,long long w)
{
	e[cnt]=(link){v,w,head[u]};head[u]=cnt++;
}

void SPFA(int x)
{
	mark[x]=true;
	for (int i=head[x];~i;i=e[i].nxt)
		if (dis[e[i].to]>e[i].val+dis[x])
		{
			if (mark[e[i].to]){flag=true;return;}
			else
			{
				dis[e[i].to]=e[i].val+dis[x];
				SPFA(e[i].to);
			}
		}
	mark[x]=false;
	return ;
}
 
bool judge()
{
	for (int i=1;i<=n;i++) dis[i]=mark[i]=0;
	flag=false;
	for (int i=1;i<=n;i++)
	{
		SPFA(i);
		if (flag) return true;
	}
	return false;
}

inline long long Binary(int s,int t)
{
	int p=cnt;add(s,t,0);
	long long l=-1e18,r=1e18,m,ans;
	while (l<=r)
	{
		m=(l+r)/2;e[p].val=m;
		if (judge()){ans=m;l=m+1;}
		else r=m-1;
	}
	e[p].val=ans+1;
	return ans+1;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		memset(head,-1,sizeof head);cnt=0;
		scanf("%d %d",&n,&m);
		for (int i=1;i<=m;i++)
		{
			scanf("%d %d %d",&u,&v,&w);
			add(u+1,v+1,w);
		}
		for (int i=1;i<=6;i++)
		{
			scanf("%d %d",&u,&v);
			printf("%lld\n",Binary(u+1,v+1));
		}
	}
	return 0;
}