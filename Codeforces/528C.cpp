#include <bits/stdc++.h>
#define MAXN 100005
#define MAXM 500005
using namespace std;

struct link
{
	int to,nxt;bool f;
};

link e[MAXM<<1];
int head[MAXN],cnt=1;
int n,m,x,y,c,in[MAXN];

inline void add(int x,int y)
{
	e[++cnt]=(link){y,head[x],false};head[x]=cnt;
	e[++cnt]=(link){x,head[y],false};head[y]=cnt;
}

inline void dfs(int x)
{
	for (int &i=head[x];i;i=e[i].nxt)
		if (!e[i].f)
		{
			e[i].f=e[i^1].f=true;
			int now=i;dfs(e[now].to);
			if ((++c)&1) printf("%d %d\n",x,e[now].to);
			else printf("%d %d\n",e[now].to,x);
		}
	return ;
}

int main()
{
	scanf("%d %d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d %d",&x,&y);
		++in[x];++in[y];add(x,y);
	}
	x=0;
	for (int i=1;i<=n;i++)
		if (in[i]&1)
		{
			if (x) add(x,i),x=0,++m;
			else x=i;
		}
	if (m&1) add(1,1),++m;
	printf("%d\n",m);dfs(1);
	return 0;
}