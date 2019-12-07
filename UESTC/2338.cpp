#include <bits/stdc++.h>
#define MAXN 105
#define MAXM 100005
using namespace std;

struct link
{
	int to,nxt;
};

link e[MAXM<<1];
int head[MAXN],cnt;
int n,x,y,st,ed,in[MAXN],out[MAXN];
bool vis[MAXN],ap[MAXN];

void add(int u,int v)
{
	++out[u];++in[v];ap[x]=true;ap[y]=true;
	e[cnt]=(link){v,head[u]};head[u]=cnt++;
	e[cnt]=(link){u,head[v]};head[v]=cnt++;
}

inline void dfs(int x)
{
	vis[x]=true;
	for (int i=head[x];~i;i=e[i].nxt)
		if (!vis[e[i].to]) dfs(e[i].to);
	return ;
}

int main()
{
	memset(head,-1,sizeof head);
	assert(scanf("%d",&n)==1);
	for (int i=1;i<=n;i++)
	{
		assert(scanf("%d %d",&x,&y)==2);
		assert(1<=x&&x<=100);
		assert(1<=y&&y<=100);
		add(x,y);
	}
	for (int i=1;i<=100;i++) if (ap[i]){dfs(i);break;}
	for (int i=1;i<=100;i++) if (ap[i]) assert(vis[i]);
	for (int i=1;i<=100;i++)
	{
		if (abs(out[i]-in[i])>1) assert(false);
		if (out[i]-in[i]==1) ++st;
		if (in[i]-out[i]==1) ++ed;
	}
	if (!st&&!ed)
	{
		for (int i=100;i;i--) if (ap[i]) return printf("%d\n",i*i),0;
	}
	if (st==1&&ed==1)
	{
		int ans=1;
		for (int i=1;i<=100;i++)
		{
			if (out[i]-in[i]==1) ans*=i;
			if (in[i]-out[i]==1) ans*=i;
		}
		printf("%d\n",ans);
		return 0;
	}
	assert(false);
	return 0;
}