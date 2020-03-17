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
typedef long long ll;
typedef pair<ll,ll> pii;
typedef double db;
const int MAXN=5e5+10,MAXM=2e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
const int inv2=5e8+4;

char s[MAXN];
int n,ans=1,p=2;

int main()
{
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++)s[i]-='0';
	for(int i=n;i>1;i--)s[i]^=s[i-1];
	for(int i=2;i<=n;i++)
	{
		ans+=s[i];
		if(!s[i]&&p)
		{
			p--;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
