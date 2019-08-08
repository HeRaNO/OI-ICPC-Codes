#include <bits/stdc++.h>
typedef long long ll;
const int MAXN=1505;
using namespace std;

int a[MAXN][MAXN],n,m,P,K,U,total,now,s;
char ch[MAXN];
double sumx,sumy;

int dir[8][2]={{-1,0},{1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,1},{1,-1}};

void bfs(int x,int y)
{
	a[x][y]=3;
	for(int i=0;i<4;i++)
	{
		int nx,ny;
		nx=x+dir[i][0];
		ny=y+dir[i][1];
		if(a[nx][ny]==2)
			bfs(nx,ny);
	}
	return ;
}

void bfs_b(int x,int y)
{
	a[x][y]=now;
	s++;
	sumx+=x;
	sumy+=y;
	for(int i=0;i<8;i++)
	{
		int nx,ny;
		nx=x+dir[i][0];
		ny=y+dir[i][1];
		if(a[nx][ny]==1)
			bfs_b(nx,ny);
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<=n+1;i++)
		{
			a[i][0]=a[i][m+1]=-1;
		}
		for(int i=0;i<=m+1;i++)
		{
			a[0][i]=a[n+1][i]=-1;
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%s",ch+1);
			for(int j=1;j<=m;j++)
			{
				if(ch[j]=='#')
					a[i][j]=1;
				else
					a[i][j]=2;
			}
		}
		total=P=K=U=0;
		P=-1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(a[i][j]==2)
				{
					bfs(i,j);
					P++;
				}
		now=10;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(a[i][j]==1)
				{
					now++;
					sumx=sumy=0;
					s=0;
					bfs_b(i,j);
					double nowx,nowy;
					nowx=(double)sumx/(double)s;
					nowy=(double)sumy/(double)s;
					double r=1;
					double fanwei=0.1,ans=0;
					for(int i=nowx-r;i<=nowx+r;i++)
						for(int j=nowy-r;j<=nowy+r;j++)
						{
							if(a[i][j]==now)
							{
								ans+=(double)1/(double)(r*2+1)/(double)(r*2+1);
							}
						}
					if(ans<=fanwei)
						U++;
					else
						K++;
					total++;
				}
		printf("P: %d\nK: %d\nU: %d\ntotal: %d\n",P,K,U-P,total);
	}
	return 0;
}