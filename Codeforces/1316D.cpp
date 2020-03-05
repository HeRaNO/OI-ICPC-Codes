#include <bits/stdc++.h>
#define MAXN 1005
using namespace std;

const int d[4][2]={
	{1,0},{-1,0},
	{0,1},{0,-1}
};

int n,x,y;
int mp[MAXN][MAXN];
vector <pair<int,int> > v[MAXN][MAXN];
char ans[MAXN][MAXN];
queue <pair<int,int> > q;

bool OK(int x,int y)
{
	return x>=1&&x<=n&&y>=1&&y<=n;
}

void BFS(int x,int y,int cnt)
{
	q.push({x,y});
	while (!q.empty())
	{
		pair <int,int> xx=q.front();q.pop();
		for (int i=0;i<4;i++)
		{
			int dx=xx.first+d[i][0],dy=xx.second+d[i][1];
			if (!OK(dx,dy)) continue;
			if (mp[dx][dy]!=(x-1)*n+y) continue;
			if (ans[dx][dy]) continue;
			if (i==0) ans[dx][dy]='U';
			else if (i==1) ans[dx][dy]='D';
			else if (i==2) ans[dx][dy]='L';
			else ans[dx][dy]='R';
			q.push({dx,dy});
			cnt--;
		}
	}
	if (cnt)
	{
		puts("INVALID");
		exit(0);
	}
	return ;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		{
			scanf("%d %d",&x,&y);
			mp[i][j]=(x-1)*n+y;
			if (i==x&&j==y) ans[i][j]='X';
			if (~x&&~y) v[x][y].push_back({i,j});
		}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (v[i][j].size())
			{
				if (ans[i][j]=='X')
					BFS(i,j,v[i][j].size()-1);
				else return puts("INVALID"),0;
			}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (mp[i][j]==-2*n-1)
			{
				if (mp[i+1][j]==-2*n-1) ans[i][j]='D';
				else if (mp[i-1][j]==-2*n-1) ans[i][j]='U';
				else if (mp[i][j+1]==-2*n-1) ans[i][j]='R';
				else if (mp[i][j-1]==-2*n-1) ans[i][j]='L';
				else return puts("INVALID"),0;
			}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (!ans[i][j]) return puts("INVALID"),0;
	puts("VALID");
	for (int i=1;i<=n;i++) puts(ans[i]+1);
	return 0;
}