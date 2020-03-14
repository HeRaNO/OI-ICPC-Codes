#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
#define lowbit(x) x&-x
#define pb push_back
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)>>1)
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const int MAXN=(1<<20)+5,MAXM=2e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
const int inv2=5e8+4;

int n,m;
char s[25][25];
ll dp[MAXN],st[25][25],a[25][25],sum[25][25];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		scanf("%lld",&a[i][j]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			ll maxn=0;
			for(int k=1;k<=n;k++)
			{
				if(s[i][j]!=s[k][j])continue;
				sum[i][j]+=a[k][j];
				maxn=max(maxn,a[k][j]);
				st[i][j]|=(1<<(k-1));
			}
			sum[i][j]-=maxn;
		}
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	for(int sta=0;sta<(1<<n);sta++)
	{
		for(int i=1;i<=n;i++)
		if(!((1<<(i-1))&sta))
		{
			for(int j=1;j<=m;j++)
			{
				int tmp1=(1<<(i-1)),tmp2=st[i][j];
				dp[sta|tmp1]=min(dp[sta|tmp1],dp[sta]+a[i][j]);
				dp[sta|tmp2]=min(dp[sta|tmp2],dp[sta]+sum[i][j]);
			}
		}
	}
	printf("%lld",dp[(1<<n)-1]);
	return 0;
}