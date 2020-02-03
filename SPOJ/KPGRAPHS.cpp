#include <bits/stdc++.h>
#define MAXN 1005
using namespace std;

const long long M=1e9+7;
const long long inv2=(M+1)/2;

int T,n;
long long ans[MAXN][3],C[MAXN][MAXN],g[MAXN],h[MAXN];

inline long long fpow(long long a,long long b)
{
	long long r=1;
	for (;b;b>>=1,(a*=a)%=M) if (b&1) (r*=a)%=M;
	return r;
}

inline void Init()
{
	int n=1e3;
	for (int i=0;i<=n;i++)
	{
		C[i][0]=C[i][i]=1;
		for (int j=1;j<i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%M;
	}
	for (int i=1;i<=n;i++) h[i]=fpow(2,i*(i-1)/2);
	ans[1][0]=1;g[1]=1;
	for (int i=2;i<=n;i++)
	{
		for (int j=1;j<i;j++)
		{
			g[i]+=ans[j][0]*C[i-1][j-1]%M*h[i-j]%M;
			if (g[i]>=M) g[i]-=M;
		}
		ans[i][0]=h[i]-g[i]+M;
		if (ans[i][0]>=M) ans[i][0]-=M;
	}
	for (int i=n;~i;i--) h[i+1]=h[i];h[1]=1;
	ans[1][1]=1;g[1]=1;
	for (int i=2;i<=n;i++)
	{
		g[i]=0;
		for (int j=1;j<i;j++)
		{
			g[i]+=ans[j][1]*C[i-1][j-1]%M*h[i-j]%M;
			if (g[i]>=M) g[i]-=M;
		}
		ans[i][1]=h[i]-g[i]+M;
		if (ans[i][1]>=M) ans[i][1]-=M;
	}
	for (int i=1;i<=n;i++)
	{
		g[i]=0;
		for (int j=0;j<=i;j++)
		{
			g[i]+=C[i][j]*fpow(2,j*(i-j))%M;
			if (g[i]>=M) g[i]-=M;
		}
	}
	for (int i=1;i<=n;i++)
	{
		h[i]=g[i]*inv2%M;long long r=0;
		for (int j=1;j<i;j++)
		{
			r+=C[i-1][j-1]*h[j]%M*g[i-j]%M;
			if (r>=M) r-=M;
		}
		h[i]+=M-r;
		if (h[i]>=M) h[i]-=M;
	}
	ans[0][2]=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=i;j++)
		{
			ans[i][2]+=C[i-1][j-1]*h[j]%M*ans[i-j][2]%M;
			if (ans[i][2]>=M) ans[i][2]-=M;
		}
	return ;
}

int main()
{
	Init();scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		printf("Connected: %lld\n",ans[n][0]);
		printf("Eulerian: %lld\n",ans[n][1]);
		printf("Bipartite: %lld\n",ans[n][2]);
		putchar('\n');
	}
	return 0;
}