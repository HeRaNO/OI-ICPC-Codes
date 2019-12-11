#include <bits/stdc++.h>
#define MAXN 1005
using namespace std;

int n,m,x,y,W,w[MAXN],b[MAXN],f[MAXN],sw[MAXN],sb[MAXN],ans;
vector <int> v[MAXN];
int dp[2][MAXN];

inline int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

int main()
{
	scanf("%d %d %d",&n,&m,&W);
	for (int i=1;i<=n;i++) scanf("%d",&w[i]),f[i]=i;
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	for (int i=1;i<=m;i++)
	{
		scanf("%d %d",&x,&y);
		int fx=getf(x),fy=getf(y);
		if (fx!=fy) f[fy]=fx;
	}
	for (int i=1;i<=n;i++)
	{
		int fi=getf(i);sw[fi]+=w[i];sb[fi]+=b[i];
		v[fi].push_back(i);
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=W;~j;j--) dp[i&1][j]=dp[(i-1)&1][j];
		for (int j=W;j>=sw[i];j--)
			dp[i&1][j]=max(dp[i&1][j],dp[(i-1)&1][j-sw[i]]+sb[i]);
		for (auto j:v[i])
			for (int k=W;k>=w[j];k--)
				dp[i&1][k]=max(dp[i&1][k],dp[(i-1)&1][k-w[j]]+b[j]);
	}
	for (int i=W;~i;i--) ans=max(ans,dp[n&1][i]);
	printf("%d\n",ans);
	return 0;
}
