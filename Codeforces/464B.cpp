#include <bits/stdc++.h>
#define MAXN 10
using namespace std;

const int d[6][3]={
	{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}
};

int n=8,a[MAXN][4],ans[MAXN][3];
long long dis[MAXN][MAXN];

inline long long getdis(int x,int y)
{
	return 1LL*(ans[x][0]-ans[y][0])*(ans[x][0]-ans[y][0])+
		   1LL*(ans[x][1]-ans[y][1])*(ans[x][1]-ans[y][1])+
		   1LL*(ans[x][2]-ans[y][2])*(ans[x][2]-ans[y][2]);
}

inline bool check()
{
	int a=0,b=0,c=0;long long mn=~(1LL<<63);
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
		{
			dis[i][j]=getdis(i,j);
			mn=min(mn,dis[i][j]);
		}
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
		{
			if (dis[i][j]==mn) ++a;
			else if (dis[i][j]==mn*2) ++b;
			else if (dis[i][j]==mn*3) ++c;
		}
	return a==12&&b==12&&c==4;
}

void dfs(int x)
{
	if (x==n+1)
	{
		if (check())
		{
			puts("YES");
			for (int i=1;i<=n;i++)
				printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
			exit(0);
		}
		return ;
	}
	for (int i=0;i<6;i++)
	{
		ans[x][0]=a[x][d[i][0]];
		ans[x][1]=a[x][d[i][1]];
		ans[x][2]=a[x][d[i][2]];
		dfs(x+1);
	}
	return ;
}

int main()
{
	for (int i=1;i<=n;i++)
		for (int j=1;j<=3;j++)
			scanf("%d",&a[i][j]);
	dfs(1);
	puts("NO");
	return 0;
}