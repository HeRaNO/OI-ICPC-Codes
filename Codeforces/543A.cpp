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
const int MAXN=1e6+10,MAXM=2e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
const int inv2=5e8+4;

int a[MAXN];
ll dp[505][505];
int n,m,P,b;

int main()
{
	scanf("%d%d%d%d",&n,&m,&b,&P);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<m;j++)
		{
			for(int k=0;k+a[i]<=b;k++)
				(dp[j+1][k+a[i]]+=dp[j][k])%=P;
		}
	}
	ll ans=0;
	for(int i=0;i<=b;i++)(ans+=dp[m][i])%=P;
	cout<<ans;
	return 0;
}