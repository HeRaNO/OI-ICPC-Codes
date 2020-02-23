#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x.begin(),x.end())
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const int MAXN=6e5+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;

int a[8][8],len[12],cnt;
int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
bool vis[8][8];

bool check(int x,int y)
{
	return x>=1&&x<=6&&y>=1&&y<=6;
}

int calcdis()
{
	for(int i=1;i<=6;i++)if(a[3][i]==1)return 7-i;
	return 0;
}

bool dfs(int mxdep,int cur)
{
	int p=calcdis();
	if(p+cur>mxdep)return false;
	if(p==len[1])return true;
	for(int i=1;i<=6;i++)
		for(int j=1;j<=6;j++)
		if(a[i][j])
		{
			int q=a[i][j];
			for(int k=0;k<4;k++)
			{
				int x=i,y=j;
				int ddx=d[k][0]*(len[q]-1)+x,ddy=d[k][1]*(len[q]-1)+y;
				int dx=d[k][0]*len[q]+x,dy=d[k][1]*len[q]+y;
				if(a[ddx][ddy]==q&&check(dx,dy))
				{
					if(a[dx][dy]==0)
					{
						a[dx][dy]=q;
						a[x][y]=0;
						if(dfs(mxdep,cur+1))return true;
						a[x][y]=q;
						a[dx][dy]=0;
					}
				}
			}
		}
	return false;
}

int dfslen(int x,int y)
{
	int ans=1;
	vis[x][y]=1;
	for(int i=0;i<4;i++)
	{
		int xx=x+d[i][0],yy=y+d[i][1];
		if(!check(xx,yy)||vis[xx][yy])continue;
		if(a[xx][yy]==a[x][y])ans+=dfslen(xx,yy);
	}
	return ans;
}

int main()
{
	for(int i=1;i<=6;i++)
		for(int j=1;j<=6;j++)scanf("%d",&a[i][j]),cnt=max(cnt,a[i][j]);
	for(int i=1;i<=6;i++)
		for(int j=1;j<=6;j++)
			if(a[i][j]&&!len[a[i][j]])len[a[i][j]]=dfslen(i,j);
	for(int i=1;i<=10;i++)
	{
		if(dfs(i,0))
		{
			printf("%d\n",i);
			return 0;
		}
	}
	puts("-1");
	return 0;
}
