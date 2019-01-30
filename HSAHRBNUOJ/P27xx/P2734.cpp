#include <cstdio>
#include <cstring>
#define MAXN 100010
using namespace std;

struct link
{
	int to,val,nxt;
};

link e[MAXN<<1];
int head[MAXN],cnt;
int n,m,u,v,w,siz[MAXN][16],a[MAXN][16],d[MAXN],sz[16];

inline void add(int u,int v,int w)
{
	e[cnt]=(link){v,w,head[u]};head[u]=cnt++;
	e[cnt]=(link){u,w,head[v]};head[v]=cnt++;
}

void dfs1(int x,int f)
{
	for (int i=head[x];~i;i=e[i].nxt)
		if (e[i].to!=f)
		{
			int p=e[i].to;dfs1(p,x);
			d[x]+=d[p]+(e[i].val>>4);++siz[x][e[i].val&15];
			for (int j=0,r=e[i].val;j<16;j++,r++)
			{
				siz[x][r&15]+=siz[p][j];
				d[x]+=(r>>4)*siz[p][j];
			}
		}
	return ;
}

void dfs2(int x,int f)
{
	for (int i=head[x];~i;i=e[i].nxt)
		if (e[i].to!=f)
		{
			int p=e[i].to,y=d[x]-d[p];
			for (int j=0,r=e[i].val;j<16;j++,r++)
			{
				y-=(r>>4)*siz[p][j];
				sz[r&15]=siz[x][r&15]-siz[p][j];
			}
			--sz[e[i].val&15];++siz[p][e[i].val&15];d[p]+=y;
			for (int j=0,r=e[i].val;j<16;j++,r++)
			{
				d[p]+=(r>>4)*sz[j];
				siz[p][r&15]+=sz[j];
			}
			dfs2(p,x);
		}
	return ;
}

inline void read(int &x)
{
	x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return ;
}

int main()
{
	memset(head,-1,sizeof head);
	read(n);read(m);
	for (int i=1;i<n;i++) read(u),read(v),read(w),add(u,v,w);
	dfs1(1,-1);dfs2(1,-1);
	for (int i=1;i<=n;i++)
	{
		u=d[i]<<4;
		for (int j=0;j<16;j++) u+=(j^m)*siz[i][j];
		printf("%d\n",u);
	}		
	return 0;
}
