#include <bits/stdc++.h>
#define MAXN 1005
using namespace std;

int T,n,m,x,y,p,q,a[MAXN][MAXN],f[MAXN][MAXN];
int d[MAXN][MAXN][11][11],lg[MAXN];

inline void init()
{
	for (int i=2,p=max(n,m);i<=p;i++) lg[i]=lg[i>>1]+1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			d[i][j][0][0]=f[i][j];
	for (int ii=0;ii<=lg[n];ii++)
		for (int jj=0;jj<=lg[m];jj++)
			if (ii+jj)
			{
				for (int i=1;i+(1<<ii)-1<=n;i++)
					for (int j=1;j+(1<<jj)-1<=m;j++)
						if (ii) d[i][j][ii][jj]=max(d[i][j][ii-1][jj],d[i+(1<<(ii-1))][j][ii-1][jj]);
						else d[i][j][ii][jj]=max(d[i][j][ii][jj-1],d[i][j+(1<<(jj-1))][ii][jj-1]);
			}
	return ;
}

inline int query(int x,int y,int p,int q)
{
	int t1=lg[p-x+1],t2=lg[q-y+1];
	p=p-(1<<t1)+1;q=q-(1<<t2)+1;
	return max(max(d[x][y][t1][t2],d[x][q][t1][t2]),max(d[p][y][t1][t2],d[p][q][t1][t2]));
}

int main()
{
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (a[i][j])
				f[i][j]=min(min(f[i-1][j-1],f[i-1][j]),f[i][j-1])+1;
	init();
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d %d %d",&x,&y,&p,&q);
		int l=0,r=min(p-x+1,q-y+1),ans;
		while (l<=r)
		{
			int m=l+r>>1;
			if (query(x+m-1,y+m-1,p,q)>=m) ans=m,l=m+1;
			else r=m-1;
		}
		printf("%d\n",ans);
	}
	return 0;
}