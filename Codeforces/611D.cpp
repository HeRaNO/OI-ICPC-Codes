#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x.begin(),x.end())
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const int MAXN=8e5+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=119;
const int Lim=1<<20;

char s[MAXN];
int n,nxt[5005][5005];
ll dp[5005][5005];

int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=n;i;i--)
	for(int j=n;j>i;j--)
	{
		if(s[i]==s[j])nxt[i][j]=nxt[i+1][j+1]+1;
		else nxt[i][j]=0;
	}
	if(s[1]=='0')return puts("0"),0;
	for(int i=1;i<=n;i++)dp[1][i]=1;
	for(int i=2;i<=n;i++)
	for(int j=i;j<=n;j++)
	{
		(dp[i][j]+=dp[i][j-1])%=MOD;
		int p=2*i-j-1;
		if(p<1)continue;
		int q1=nxt[p][i]+p,q2=nxt[p][i]+i;
		if(s[i]=='0')dp[i][j]=0;
		else
		{
			if(q1<i&&q2<=j&&s[q2]>s[q1])(dp[i][j]+=dp[p][i-1])%=MOD;
			else (dp[i][j+1]+=dp[p][i-1])%=MOD;
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++)(ans+=dp[i][n])%=MOD;
	cout<<ans;
	return 0;
}
