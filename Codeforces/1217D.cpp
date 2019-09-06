#include <bits/stdc++.h>
#define MAXN 5005
using namespace std;

struct link
{
	int to,nxt;
};

link e[MAXN];
int head[MAXN],cnt;
int n,m,u,v,ans[MAXN],sta[MAXN],in[MAXN],top;
bool cir;

inline void add(int u,int v)
{
	++in[v];
	e[cnt]=(link){v,head[u]};head[u]=cnt++;
}

inline void Topological_Sort()
{
	for (int i=1;i<=n;i++) if (!in[i]) sta[++top]=i;
	while (top)
	{
		int u=sta[top--];
		for (int i=head[u];~i;i=e[i].nxt)
			if (--in[e[i].to]==0) sta[++top]=e[i].to;
	}
	return ;
}

int main()
{
	memset(head,-1,sizeof head);
	scanf("%d %d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d %d",&u,&v);
		add(u,v);ans[i]=u<v?1:2;
	}
	Topological_Sort();
	for (int i=1;i<=n&&!cir;i++) if (in[i]) cir=true;
	if (!cir)
	{
		puts("1");
		for (int i=1;i<=m;i++) printf("1%c",i==m?'\n':' ');
	}
	else
	{
		puts("2");
		for (int i=1;i<=m;i++) printf("%d%c",ans[i],i==m?'\n':' ');
	}
	return 0;
}