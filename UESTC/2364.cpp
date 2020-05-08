#include <bits/stdc++.h>
#define MAXN 505
using namespace std;

int T,n,m,x,y,p,q,a[MAXN][MAXN];
int d[MAXN][MAXN][10],lg[MAXN];

inline void init()
{
	int N=max(n,m);
	for (int i=2;i<=N;i++) lg[i]=lg[i>>1]+1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			d[i][j][0]=a[i][j];
	for (int k=1;k<=lg[N];k++)
		for (int i=1;i+(1<<k)-1<=n;i++)
			for (int j=1;j+(1<<k)-1<=m;j++)
				d[i][j][k]=__gcd(__gcd(d[i][j][k-1],d[i+(1<<(k-1))][j+(1<<(k-1))][k-1]),__gcd(d[i][j+(1<<(k-1))][k-1],d[i+(1<<(k-1))][j][k-1]));
	return ;
}

inline int query(int x,int y,int k)
{
	int t=lg[k];int p=x+k-1,q=y+k-1;
	p=p-(1<<t)+1;q=q-(1<<t)+1;
	return __gcd(__gcd(d[x][y][t],d[x][q][t]),__gcd(d[p][y][t],d[p][q][t]));
}

inline int check(int x)
{
	int l=x>>1,res=0;
	for (int i=1;i+x-1<=n;i++)
		for (int j=1;j+x-1<=m;j++)
			res+=(query(i,j,x)%a[i+l][j+l]==0);
	return res;
}

inline int sqr(int x){return x*x;}

int main()
{
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	init();
	int l=0,r=min(n,m)>>1,ans;
	while (l<=r)
	{
		int m=l+r>>1;
		if (check(m<<1|1)){ans=m;l=m+1;}
		else r=m-1;
	}
	ans=ans<<1|1;
	printf("%d\n%d\n",ans*ans,check(ans));
	return 0;
}