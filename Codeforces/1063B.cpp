#include <bits/stdc++.h>
#define MAXN 2005
#define mp make_pair
#define fi first
#define se second
using namespace std;

const int d[4][2]={
	{1,0},{-1,0},
	{0,1},{0,-1}
};

int n,m,r,c,x,y,ans=1;
char g[MAXN][MAXN];
bool vis[MAXN][MAXN];
deque <pair<pair<int,int>,pair<int,int> > > q;

void BFS()
{
	q.push_front(mp(mp(r,c),mp(0,0)));vis[r][c]=true;
	while (!q.empty())
	{
		pair<pair<int,int>,pair<int,int> > now=q.front();q.pop_front();
		for (int i=0;i<4;i++)
		{
			int tx=now.fi.fi+d[i][0],ty=now.fi.se+d[i][1];
			if (vis[tx][ty]) continue;
			if (tx<1||tx>n||ty<1||ty>m||g[tx][ty]=='*') continue;
			if (ty==now.fi.se)
			{
				vis[tx][ty]=true;
				q.push_front(mp(mp(tx,ty),now.se));
			}
			else
			{
				if (d[i][1]==-1)
				{
					if (now.se.fi+1>x) continue;
					q.push_back(mp(mp(tx,ty),mp(now.se.fi+1,now.se.se)));
					vis[tx][ty]=true;
				}
				else
				{
					if (now.se.se+1>y) continue;
					q.push_back(mp(mp(tx,ty),mp(now.se.fi,now.se.se+1)));
					vis[tx][ty]=true;
				}
			}
			++ans;
		}
	}
	return ;
}

int main()
{
	scanf("%d %d",&n,&m);
	scanf("%d %d",&r,&c);
	scanf("%d %d",&x,&y);
	for (int i=1;i<=n;i++) scanf("%s",g[i]+1);
	if (g[r][c]=='*') return puts("0"),0;
	BFS();
	printf("%d\n",ans);
	return 0;
}