#include <bits/stdc++.h>
#define MAXN 10010
using namespace std;

struct link
{
	int to,nxt;
};

link e[MAXN<<1];
int head[MAXN],cnt;
int n,a,b,f[MAXN][3];

inline void add(int u,int v)
{
	e[cnt]=(link){v,head[u]};head[u]=cnt++;
	e[cnt]=(link){u,head[v]};head[v]=cnt++;
}

void TreeDP(int x,int fa)
{
	int d=~(1<<31);
	for (int i=head[x];~i;i=e[i].nxt)
		if (e[i].to!=fa)
		{
			TreeDP(e[i].to,x);
			f[x][0]+=min(f[e[i].to][1],f[e[i].to][2]);
			f[x][1]+=min(f[e[i].to][1],f[e[i].to][2]);
			d=min(d,f[e[i].to][2]-min(f[e[i].to][1],f[e[i].to][2]));
			f[x][2]+=min(f[e[i].to][0],min(f[e[i].to][1],f[e[i].to][2]));
		}
	f[x][1]+=d;++f[x][2];
	return ;
}

int main()
{
	memset(head,-1,sizeof head);
	scanf("%d",&n);
	for (int i=1;i<n;i++) scanf("%d %d",&a,&b),add(a,b);
	TreeDP(1,-1);
	printf("%d\n",min(f[1][1],f[1][2]));
	return 0;
}
