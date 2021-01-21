#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 50
using namespace std;

const int M=1000000007;

int n,a[MAXN],dp[MAXN][MAXN][2];

inline void fadd(int &x,int y){x+=y;if (x>=M) x-=M;return ;}
inline int _2(int x){int r=1<<x;if (r>=M) r-=M;return r;}

int dfs(int i,int p,int l)
{
	int now=0,res=0;
	p&=~((1<<l)-1);
	if (i==n+1) return !p;
	int &f=dp[i][l][p&(1<<l)?1:0];
	if (~f) return f;
	for (int j=30;~j;j--)
		if (a[i]&(1<<j))
		{
			fadd(res,1LL*dfs(i+1,p^now,max(j,l))*_2(min(j,l))%M);
			now|=1<<j;
		}
	return f=res;
}

int main()
{
	memset(dp,-1,sizeof dp);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),++a[i];
	printf("%d\n",dfs(1,0,0));
	return 0;
}