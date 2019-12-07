#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=1e5+10,INF=~(1<<31),MOD=1e9+7,mod=998244353;
const int MAXM=5e6+10;
const ll llINF=~(1ll<<63);
const double Pi=acos(-1.0);
#define lowbit(x) x&-x

char ss[MAXN];
string s[MAXN];
int n;

ll ksm(ll x,ll v)
{
	ll ans=1;
	x%=MOD;
	while(v)
	{
		if(v&1)(ans*=x)%=MOD;
		(x*=x)%=MOD;
		v>>=1;
	}
	return ans;
}

ll val[15],loc[15];

void solve(int u)
{
	int p=s[u][0]-'0';
	ll vv=0,llo=0;
	for(int i=3;i<s[u].size();i++)
	{
		int now=s[u][i]-'0';
		(vv*=ksm(10,loc[now]))%=MOD;
		(vv+=val[now])%=MOD;
		(llo+=loc[now])%=(MOD-1);
	}
	loc[p]=llo%(MOD-1);
	val[p]=vv%MOD;
}

int main()
{
	scanf("%s",ss+1);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=0;i<=9;i++)
	{
		val[i]=i;
		loc[i]=1;
	}
	for(int i=n;i;i--)
	{
		solve(i);
	}
	int sz=strlen(ss+1);
	ll ans=0;
	for(int i=1;i<=sz;i++)
	{
		int u=ss[i]-'0';
		((ans*=ksm(10,loc[u]))+=val[u])%=MOD;
	}
	cout<<ans;
	return 0;
}
