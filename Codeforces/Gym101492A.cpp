#include <bits/stdc++.h>
#define MAXN 50010
#define MAXM 500010
using namespace std;

struct link
{
	int to,nxt;
};

link e[MAXM<<1];
int head[MAXN],cnt;
int n,m,k,u,v,f[MAXN];

inline void add(int u,int v)
{
	e[cnt]=(link){v,head[u]};head[u]=cnt++;
	e[cnt]=(link){u,head[v]};head[v]=cnt++;
}

void dfs(int x,int fa)
{
	if (f[x]) return ;
	for (int i=1;i<=k;i++)
	{
		bool fl=true;
		for (int j=head[x];~j&&fl;j=e[j].nxt)
			if (f[e[j].to]==i) fl=false;
		if (fl)
		{
			f[x]=i;
			break;
		}
	}
	for (int i=head[x];~i;i=e[i].nxt) if (e[i].to!=fa) dfs(e[i].to,x);
	return ;
}

int main()
{
	memset(head,-1,sizeof head);
	scanf("%d %d %d",&n,&m,&k);
	for (int i=1;i<=m;i++)
	{
		scanf("%d %d",&u,&v);
		add(u,v);
	}
	for (int i=1;i<=n;i++) if (!f[i]) dfs(i,-1);
	for (int i=1;i<=n;i++) if (!f[i]||f[i]>k) return puts("-1"),0;
	for (int i=1;i<=n;i++) printf("%d\n",f[i]);
	return 0;
}