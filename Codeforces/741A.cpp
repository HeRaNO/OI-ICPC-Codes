#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=2e3+10,MAXM=4e4+10;
const int INF=INT_MAX,MOD=1e9+7,mod=998244353;
const ll llINF=~(1ll<<63);

int n,a[MAXN],f[MAXN],sz[MAXN];

int _find(int x)
{
	return f[x]^x?f[x]=_find(f[x]):f[x];
}

ll lcm(ll x,ll y)
{
	ll p=__gcd(x,y);
	return x/p*y;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)sz[i]=1;
	for(int i=1;i<=n;i++)
	{
		int p=a[i];
		for(int j=1;j<=100&&p!=i;j++)
		{
			sz[i]++;
			p=a[p];
		}
		if(p!=i)return puts("-1"),0;
	}
	ll ans=1;
	for(int i=1;i<=n;i++)
		if(sz[i]>1)
		{
			if(sz[i]%2)ans=lcm(ans,sz[i]);
			else ans=lcm(ans,sz[i]/2);
		}
	cout<<ans;
	return 0;
}