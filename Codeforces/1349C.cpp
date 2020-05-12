#include <bits/stdc++.h>
#define MAXN 1005
using namespace std;

int n,m,Q,a[MAXN][MAXN],b[MAXN][MAXN];
char s[MAXN][MAXN];
queue <pair<int,int> > q;

inline void chk(int x,int y,int tx,int ty)
{
	if (~a[tx][ty]) return ;
	a[tx][ty]=max(a[x][y]+1,2);b[tx][ty]=b[x][y];
	q.push({tx,ty});
	return ;
}

inline void BFS()
{
	while (!q.empty())
	{
		int x,y;
		tie(x,y)=q.front();q.pop();
		if (x<n) chk(x,y,x+1,y);
		if (y<m) chk(x,y,x,y+1);
		if (x>0) chk(x,y,x-1,y);
		if (y>0) chk(x,y,x,y-1);
	}
	return ;
}

int main()
{
	memset(a,-1,sizeof a);
	scanf("%d %d %d",&n,&m,&Q);
	for (int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			if (i<n&&s[i][j]==s[i+1][j])
			{
				a[i][j]=a[i+1][j]=0;
				b[i][j]=b[i+1][j]=s[i][j]-'0';
			}
			if (j<m&&s[i][j]==s[i][j+1])
			{
				a[i][j]=a[i][j+1]=0;
				b[i][j]=b[i][j+1]=s[i][j]-'0';
			}
		}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (~a[i][j]) q.push({i,j});
	BFS();
	while (Q--)
	{
		int x,y;long long p;
		scanf("%d %d %lld",&x,&y,&p);
		if (a[x][y]==-1||p<a[x][y]) printf("%c\n",s[x][y]);
		else printf("%d\n",(p&1)^b[x][y]);
	}
	return 0;
}