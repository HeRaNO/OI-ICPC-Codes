#include <cstdio>
#define MAXN 110
using namespace std;

int dp[MAXN][MAXN][MAXN][4];
int n,m;
int k[3][2]={{1,2},{0,2},{0,1}};
int block[MAXN][4];

int mymax(int a,int b)
{
	return a>b?a:b;
}

bool jud(int a1,int a2,int b1,int b2)
{
	return (a1>=b1 && a2>=b2) || (a1>=b2 && a2>=b1);
}

bool ok(int a1,int k1,int a2,int k2)
{
	return jud(block[a1][k[k1][0]],block[a1][k[k1][1]],block[a2][k[k2][0]],block[a2][k[k2][1]]);
}

int dfs(int i,int a,int b,int k)
{
	if (a==n||b==n) return 0;
	if (dp[i][a][b][k]) return dp[i][a][b][k];
	int ans=(dp[i][a+1][b][k]=dfs(i,a+1,b,k));
	if (i<m)
	{
		for (int t=0;t<3;t++)
			ans=mymax(ans,(dp[i+1][a+1][a+1][t]=dfs(i+1,a+1,a+1,t))+block[a+1][t]);
	}
	for (int t=0;t<3;t++)
		if (ok(b,k,a+1,t))
			ans=mymax(ans,(dp[i][a+1][a+1][t]=dfs(i,a+1,a+1,t))+block[a+1][t]);
	return ans;
}

int main()
{
	freopen("buildinggame.in","r",stdin);freopen("buildinggame.out","w",stdout);
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d %d %d",&block[i][0],&block[i][1],&block[i][2]);
	printf("%d\n",dfs(0,0,0,0));
	return 0;
}