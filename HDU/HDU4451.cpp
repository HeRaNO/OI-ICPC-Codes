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
typedef long long ll;
typedef pair<ll,ll> pii;
typedef double db;
const int MAXN=3e6+10,MAXM=2e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
const int inv2=5e8+4;
const double Pi=acos(-1);

int n,m,k;
ll dp[4][1005];
vector<int>v[4][1005];

void calc(int n,int m,int p)
{
	ll ans=0;
	for(int i=1;i<=n;i++)ans+=dp[p-1][i];
	for(int i=1;i<=m;i++)
	{
		dp[p][i]=ans;
		for(auto j:v[p][i])
		dp[p][i]-=dp[p-1][j];
	}
}

void solve()
{
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++)dp[1][i]=1;
	for(int i=1;i<=m;i++)v[2][i].resize(0);
	for(int i=1;i<=k;i++)v[3][i].resize(0);
	int p;
	scanf("%d",&p);
	for(int i=1;i<=p;i++)
	{
		char s[50];
		scanf("%s",s);
		int a,b;
		scanf("%d%s%d",&a,s,&b);
		if(s[0]=='p')v[2][b].pb(a);
		else v[3][b].pb(a);
	}
	calc(n,m,2);
	calc(m,k,3);
	ll ans=0;
	for(int i=1;i<=k;i++)ans+=dp[3][i];
	printf("%lld\n",ans);
	return;
}

int main()
{
	int t,kase=0;
	while(scanf("%d%d%d",&n,&m,&k)==3&&(n||m||k))
	{
		solve();
	}
	return 0;
}