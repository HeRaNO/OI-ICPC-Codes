#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
#define lowbit(x) x&-x
#define pb push_back
#define ls (id<<1)
#define rs (id<<1|1)
#define Rint register int
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const int MAXN=2e6+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
const int inv2=5e8+4;

ll dp[5005][5005],sum[5005][5005];

int main()
{
	int b,s;
	cin>>s>>b;
	dp[s][s]=1;
	sum[s][s]=s;
	for(int i=s-1;i;i--)dp[s][i]=dp[s][i+1],sum[s][i]=sum[s][i+1];
	for(int i=s+1;i<=b;i++)
	{
		for(int j=1;j<=s;j++)
			(dp[i][j]+=sum[i-j][j]-dp[i-j][j]*(j-1)%MOD+MOD)%=MOD;
		for(int j=s;j>=1;j--)sum[i][j]=(sum[i][j+1]+dp[i][j]*j%MOD)%MOD,(dp[i][j]+=dp[i][j+1])%=MOD;
	}
	cout<<dp[b][1];
	return 0;
}
