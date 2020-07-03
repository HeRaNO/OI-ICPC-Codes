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
int n,x,y,p,q,in[MAXN],out[MAXN];
bool vis[MAXN],ap[MAXN];

void add(int u,int v)
{
	++out[u];++in[v];ap[x]=true;ap[y]=true;
	e[cnt]=(link){v,head[u]};head[u]=cnt++;
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
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d %d",&x,&y);
		add(x,y);
	}
	for (int i=1;i<=100;i++)
	{
		if (out[i]-in[i]==1) ++p;
		if (in[i]-out[i]==1) ++q;
	}
	if (p==1&&q==1)
	{
		for (int i=1;i<=100;i++) if (out[i]-in[i]==1){dfs(i);break;}
		for (int i=1;i<=100;i++) if (ap[i]&&!vis[i]) return puts("-1"),0;
		int ans=1;
		for (int i=1;i<=100;i++) abs(out[i]-in[i])==1?ans*=i:0;
		printf("%d\n",ans);
	}
	else if (!p&&!q)
	{
		for (int i=100;i;i--)
		{
			memset(vis,false,sizeof vis);
			if (ap[i]) dfs(i);bool f=true;
			for (int i=1;i<=100&&f;i++) if (ap[i]&&!vis[i]) f=false;
			if (!f) continue;
			return printf("%d\n",i*i),0;
		}
		return puts("-1"),0;
	}
	else puts("-1");
	return 0;
}