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

char s[1005][1005];
int n,m,ans;
int l[1005][1005],dp[1005][1005];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]==s[i][j-1])l[i][j]=l[i][j-1]+1;
			else l[i][j]=1;
			dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
			dp[i][j]=min(dp[i][j],l[i][j]);
			if(i>1)dp[i][j]=min(dp[i][j],l[i-1][j]);
			ans=max(ans,dp[i][j]);
		}
	cout<<ans*ans;
	return 0;
}
