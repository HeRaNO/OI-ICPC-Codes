#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const int MAXN=5e5+10,MAXM=1e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
#define lowbit(x) x&-x
const int inv2=5e8+4;

ll n,k;
char s[MAXN],t[MAXN];

int main()
{
	scanf("%lld%lld",&n,&k);
	scanf("%s",s+1);
	scanf("%s",t+1);
	ll l=0,r=0,ans=0,tmp=0;
	for(int i=1;i<=n;i++)
	{
		l<<=1;
		r<<=1;
		l+=s[i]-'a';
		r+=t[i]-'a';
		ll q=min(r-l+1-tmp,k);
		ans+=q*(n-i+1);
		tmp+=q;
		k-=q;
		if(k<=0)break;
	}
	cout<<ans;
	return 0;
}
