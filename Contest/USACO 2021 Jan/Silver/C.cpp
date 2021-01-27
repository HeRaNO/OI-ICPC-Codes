#include <bits/stdc++.h>
#define MAXN 1005
using namespace std;

int n,a[MAXN][MAXN],ans;
int p[MAXN][MAXN];

inline int getSum(int x,int y)
{
	return p[x-1][y-1]+p[x-1][y]+p[x][y-1]+p[x][y];
}

inline int getAns(int x,int y)
{
	int ans=0;
	for (int i=0;i<n;i++) p[1][i+1]=(x>>i)&1;
	for (int i=0;i<n;i++) p[i+1][1]=(y>>i)&1;
	for (int i=2;i<=n;i++)
		for (int j=2;j<=n;j++)
		{
			p[i][j]=0;int pp=getSum(i,j);
			if (!pp||pp==3) return 0;
			if (pp==1) p[i][j]=1;
		}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (p[i][j]) ans+=a[i][j];
	return ans;
}

int main(int argc, char const *argv[])
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	for (int i=0;i<(1<<n);i++)
		for (int j=0;j<(1<<n);j++)
			ans=max(ans,getAns(i,j));
	printf("%d\n",ans);
	return 0;
}