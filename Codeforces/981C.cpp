#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

struct link
{
	int to,nxt;
};

link e[MAXN<<1];
int head[MAXN],cnt;
int n,u,v,deg[MAXN],a[MAXN],p;

void add(int u,int v)
{
	++deg[u];++deg[v];
	e[cnt]=(link){v,head[u]};head[u]=cnt++;
	e[cnt]=(link){u,head[v]};head[v]=cnt++;
}

int main()
{
	memset(head,-1,sizeof head);
	scanf("%d",&n);
	for (int i=1;i<n;i++) scanf("%d %d",&u,&v),add(u,v);
	if (n==2)
	{
		puts("Yes");
		puts("1");
		puts("1 2");
		return 0;
	}
	cnt=0;for (int i=1;i<=n;i++) if (deg[i]>deg[p]) p=i;
	for (int i=1;i<=n;i++) if (deg[i]==1) a[++a[0]]=i;
	if (a[0]>deg[p]) return puts("No"),0;
	puts("Yes");
	printf("%d\n",a[0]);
	for (int i=1;i<=a[0];i++) printf("%d %d\n",p,a[i]);
	return 0;
}