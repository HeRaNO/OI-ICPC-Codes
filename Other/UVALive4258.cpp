#include <bits/stdc++.h>
#define MAXN 55
using namespace std;

struct point
{
	int x,y;
	bool operator < (const point &a)const{
		return x<a.x;
	}
};

point p[MAXN];
int T,n,dp[MAXN][MAXN];
bool u[MAXN][MAXN],d[MAXN][MAXN];

inline void init()
{
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
		{
			bool fu=true,fd=true;
			for (int k=i+1;k<j&&(fu||fd);k++)
			{
				long long f=1LL*(p[i].y-p[j].y)*(p[k].x-p[i].x);
				long long g=1LL*(p[k].y-p[i].y)*(p[i].x-p[j].x);
				if (f<=g) fu=false;
				if (f>=g) fd=false;
			}
			u[i][j]=fu;d[i][j]=fd;
		}
	return ;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		memset(dp,0,sizeof dp);
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d %d",&p[i].x,&p[i].y);
		sort(p+1,p+n+1);init();
		dp[1][2]=dp[2][1]=1;
		for (int i=1;i<n;i++)
			for (int j=1;j<n;j++)
				if (dp[i][j])
				{
					int nxt=max(i,j)+1;
					if (nxt==n&&u[i][nxt]&&d[j][nxt])
					{
						dp[n][n]+=dp[i][j];
						continue;
					}
					if (u[i][nxt]) dp[nxt][j]+=dp[i][j];
					if (d[j][nxt]) dp[i][nxt]+=dp[i][j];
				}
		printf("%d\n",dp[n][n]);
	}
	return 0;
}