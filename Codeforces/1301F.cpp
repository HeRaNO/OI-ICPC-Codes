#include <bits/stdc++.h>
#define MAXN 1005
#define MAXK 40
using namespace std;

const int d[4][2]={
	{-1,0},{1,0},{0,1},{0,-1}
};

int n,m,k,T,a[MAXN][MAXN];
int dis[MAXN][MAXN][MAXK];
bool vis[MAXK];
queue <pair<int,int> > q;
vector <pair<int,int> > c[MAXK];

inline void BFS(int col)
{
	memset(vis,false,sizeof vis);
	for (auto i:c[col])
		q.push(i),dis[i.first][i.second][col]=0;
	while (!q.empty())
	{
		pair <int,int> u=q.front();q.pop();
		int x=u.first,y=u.second;
		if (!vis[a[x][y]])
		{
			for (auto i:c[a[x][y]])
			{
				int tx=i.first,ty=i.second;
				if (~dis[tx][ty][col]) continue;
				dis[tx][ty][col]=dis[x][y][col]+1;
				q.push({tx,ty});
			}
			vis[a[x][y]]=true;
		}
		for (int i=0;i<4;i++)
		{
			int tx=x+d[i][0],ty=y+d[i][1];
			if (tx<1||tx>n||ty<1||ty>m||~dis[tx][ty][col]) continue;
			dis[tx][ty][col]=dis[x][y][col]+1;
			q.push({tx,ty});
		}
	}
	return ;
}

int main()
{
	memset(dis,-1,sizeof dis);
	scanf("%d %d %d",&n,&m,&k);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);--a[i][j];
			c[a[i][j]].push_back({i,j});
		}
	for (int i=0;i<k;i++) BFS(i);
	scanf("%d",&T);
	while (T--)
	{
		int x,y,p,q,ans;
		scanf("%d %d %d %d",&x,&y,&p,&q);ans=abs(x-p)+abs(y-q);
		for (int i=0;i<k;i++)
			ans=min(ans,dis[x][y][i]+dis[p][q][i]+1);
		printf("%d\n",ans);
	}
	return 0;
}