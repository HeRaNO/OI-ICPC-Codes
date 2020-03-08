#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
#define lowbit(x) x&-x
#define pb push_back
typedef long long ll;
typedef pair<ll,ll> pii;
typedef double db;
const int MAXN=2e6+10,MAXM=1e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
const int inv2=5e8+4;

char s[MAXN];
int n;
ll ans=0;
int main()
{
	scanf("%d%s",&n,s+1);
	int l=0,r=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='(')l++;
		else r++;
	}
	if(l!=r)return puts("-1"),0;
	l=r=0;
	bool f=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='(')l++;
		else r++;
		if(l<r)f=1;
		if(l==r)
		{
			if(f)f=0,ans+=(l+r);
			l=r=0;
		}
	}
	cout<<ans;
	return 0;
}
