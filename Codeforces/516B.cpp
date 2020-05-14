#include <bits/stdc++.h>
#define MAXN 2005
using namespace std;

const int d[4][2]={
	{-1,0},{1,0},
	{0,-1},{0,1}
};
const char f[4][3]={"v^","^v","><","<>"};

char s[MAXN][MAXN];
int n,m,out[MAXN][MAXN];
queue <pair<int,int> > q;

inline void BFS()
{
	while (!q.empty())
	{
		int x,y;
		tie(x,y)=q.front();q.pop();
		if (!out[x][y]) continue;
		for (int i=0;i<4;i++)
		{
			int tx=x+d[i][0],ty=y+d[i][1];
			if (tx<1||tx>n||ty<1||ty>m||s[tx][ty]!='.') continue;
			out[x][y]=out[tx][ty]=0;
			s[x][y]=f[i][0];s[tx][ty]=f[i][1];
			for (int j=0;j<4;j++)
			{
				int dx=tx+d[j][0],dy=ty+d[j][1];
				if (dx<1||dx>n||dy<1||dy>m||s[dx][dy]!='.') continue;
				if (--out[dx][dy]==1) q.push({dx,dy});
			}
		}
	}
	return ;
}

int main()
{
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (s[i][j]=='.')
			{
				for (int k=0;k<4;k++)
				{
					int tx=i+d[k][0],ty=j+d[k][1];
					if (tx<1||tx>n||ty<1||ty>m||s[tx][ty]!='.') continue;
					++out[i][j];
				}
			}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (out[i][j]==1) q.push({i,j});
	BFS();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (s[i][j]=='.') return puts("Not unique"),0;
	for (int i=1;i<=n;i++) puts(s[i]+1);
	return 0;
}