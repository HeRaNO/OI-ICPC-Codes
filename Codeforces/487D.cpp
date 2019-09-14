#include <bits/stdc++.h>
#define MAXN 100005
#define MAXM 11
using namespace std;

int n,m,q,b,pos[MAXN];
int dp[MAXN][MAXM];
char a[MAXN][MAXM];

inline int dfs(int k,int x,int y)
{
	if (dp[x][y]) return dp[x][y];
	if (a[x][y]=='^')
	{
		int nx=x-1,ny=y;
		if ((k-1)*b+1>nx) dp[x][y]=nx*(m+2)+ny;
		else dp[x][y]=dfs(k,nx,ny);
	}
	else if (a[x][y]=='>')
	{
		int nx=x,ny=y+1;
		if (ny==m+1) dp[x][y]=nx*(m+2)+ny;
		else if (a[x][y+1]=='<')
		{
			dp[x][y]=-1;dp[x][y+1]=-1;
		}
		else dp[x][y]=dfs(k,nx,ny);
	}
	else
	{
		int nx=x,ny=y-1;
		if (ny==0) dp[x][y]=nx*(m+2)+ny;
		else if (a[x][y-1]=='>')
		{
			dp[x][y]=-1;dp[x][y-1]=-1;
		}
		else dp[x][y]=dfs(k,nx,ny);
	}
	return dp[x][y];
}

inline void clean(int x)
{
	for (int i=(x-1)*b+1,p=min(x*b,n);i<=p;i++)
		for (int j=1;j<=m;j++)
			dfs(x,i,j);
	return ;
}

inline void modify(int x,int y,char c)
{
	for (int i=(pos[x]-1)*b+1,p=min(pos[x]*b,n);i<=p;i++)
		for (int j=1;j<=m;j++)
			dp[i][j]=0;
	a[x][y]=c;
	clean(pos[x]);
	return ;
}

inline int query(int k,int x,int y)
{
	if (!~dp[x][y]) return -1;
	if (k==1) return dp[x][y];
	int nx=dp[x][y]/(m+2),ny=dp[x][y]%(m+2);
	if (ny!=0&&ny!=m+1) return query(k-1,nx,ny);
	return dp[x][y];
}

int main()
{
	scanf("%d %d %d",&n,&m,&q);b=(int)sqrt(n);
	for (int i=1;i<=n;i++) scanf("%s",a[i]+1);
	for (int i=1;i<=n;i++) pos[i]=(i-1)/b+1;
	for (int i=1,p=n/b+(n%b!=0);i<=p;i++) clean(i);
	while (q--)
	{
		int x,y;char o[3];
		scanf("%s %d %d",o,&x,&y);
		if (o[0]=='A')
		{
			int res=query(pos[x],x,y);
			if (res==-1) puts("-1 -1");
			else printf("%d %d\n",res/(m+2),res%(m+2));
		}
		else
		{
			scanf("%s",o);
			modify(x,y,o[0]);
		}
	}
	return 0;
}