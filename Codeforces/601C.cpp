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

int n,m,x[MAXN],sum;
long double dp[105][100005];

int main()
{
	scanf("%d%d",&n,&m);
	if (m==1) return puts("1"),0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
		sum+=x[i];
	}
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		double tmp=dp[i-1][0]/(m-1);
		for(int k=1;k<=i*m;k++)
		{
			if(k>=x[i])dp[i][k]-=dp[i-1][k-x[i]]/(m-1);
			dp[i][k]+=tmp;
			tmp+=dp[i-1][k]/(m-1);
			if(k>m)tmp-=dp[i-1][k-m]/(m-1);
		}
	}
	db ans=0;
	for(int i=1;i<sum;i++)ans+=dp[n][i];
	printf("%.15lf",ans*(m-1)+1);
	return 0;
}
