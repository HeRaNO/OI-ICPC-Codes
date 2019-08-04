#include <bits/stdc++.h>
#define MAXN 1005
#define MAXQ 10010
#define MAXP 1000010
using namespace std;

const int d[4][2]={
	{1,0},{-1,0},
	{0,1},{0,-1}
};

struct line
{
	int a,b,c,d;
};

line a[MAXQ];
int n,m,q,cnt,f[MAXP],ans[MAXQ],g[MAXN][MAXN];
bool vis[MAXN][MAXN];

int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

inline void dfs(int x,int y,int fa)
{
	if (x<1||x>n||y<1||y>m||vis[x][y]) return ;
	vis[x][y]=true;
	int fx=getf((x-1)*m+y),fy=getf(fa);
	if (fx!=fy) f[fy]=fx;
	for (int i=0;i<4;i++)
		if (!g[x+d[i][0]][y+d[i][1]])
			dfs(x+d[i][0],y+d[i][1],(x-1)*m+y);
	return ;
}

inline void merge(int x,int y)
{
	for (int i=0;i<4;i++)
	{
		int tx=x+d[i][0],ty=y+d[i][1];
		if (tx<1||tx>n||ty<1||ty>m) continue;
		if (!g[tx][ty])
		{
			int fx=getf((tx-1)*m+ty),fy=getf((x-1)*m+y);
			if (fx!=fy){f[fy]=fx;--cnt;}
		}
	}
	return ;
}

int main()
{
	scanf("%d %d %d",&n,&m,&q);
	for (int i=1;i<=n*m;i++) f[i]=i;
	for (int t=1;t<=q;t++)
	{
		scanf("%d %d %d %d",&a[t].a,&a[t].b,&a[t].c,&a[t].d);
		for (int i=a[t].a;i<=a[t].c;i++)
			for (int j=a[t].b;j<=a[t].d;j++)
				++g[i][j];
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (!g[i][j]&&!vis[i][j]) ++cnt,dfs(i,j,(i-1)*m+j);
	for (int t=q;t;t--)
	{
		ans[t]=cnt;
		for (int i=a[t].a;i<=a[t].c;i++)
			for (int j=a[t].b;j<=a[t].d;j++)
				if (!--g[i][j]) ++cnt,merge(i,j);
	}
	for (int i=1;i<=q;i++) printf("%d\n",ans[i]);
	return 0;
}
