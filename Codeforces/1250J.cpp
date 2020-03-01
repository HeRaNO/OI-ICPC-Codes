#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
const int N=30050;
ll c[N],t[N];
int n;ll k,sum;

inline bool check(ll x)
{
	ll sum2=0;t[1]=c[1];
	for(int i=1;i<=n;++i)
	{
		sum2+=t[i]/x;
		t[i+1]=c[i+1];
		if(t[i+1]>=x-(t[i]%x))
		{
			t[i+1]-=(x-(t[i]%x));
			sum2++;
		}
	}
	if(sum2>=k)return true;
	else return false;
}

int main()
{
	int Test;cin>>Test;
	while(Test--)
	{
		scanf("%d%lld",&n,&k);sum=0;
		ll L=1;
		for(int i=1;i<=n;++i)scanf("%lld",&c[i]),sum+=c[i];
		c[n+1]=0;
		ll ans=0;ll R=sum;
		while(L<=R)
		{
			ll mid=(L+R)>>1;
			if(check(mid))ans=mid,L=mid+1;
			else R=mid-1;
		}
		printf("%lld\n",ans*k);
	}
	return 0;
}
