#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=2e5+10,INF=0x7fffffff;
const ll llINF=0x7fffffffffffffff,MOD=1e9+7;
#define lowbit(x) x&-x

struct Node
{
	ll att,hp,z,s;
}a[MAXN];

bool cmp(Node a,Node b)
{
	return b.att*a.z<b.z*a.att;
}

int n;

ll bi(ll now)
{
	ll ans=0,l=1,r=1e9;
	while(l<=r)
	{
		ll mid=(l+r)/2;
		if(mid*mid+mid-2*now<0)
		{
			l=mid+1;
		}
		else
		{
			ans=mid,r=mid-1;
		}
	}
	return ans;
}

int main()
{
	int t;
	cin>>t;
	for(int kase=1;kase<=t;kase++)
	{
		ll ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld",&a[i].hp,&a[i].att);
			a[i].z=bi(a[i].hp);
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++)
			a[i].s=a[i-1].s+a[i].z;
		for(int i=1;i<=n;i++)ans+=a[i].s*a[i].att;
		printf("Case #%d: %lld\n",kase,ans);
	}
	return 0;
}