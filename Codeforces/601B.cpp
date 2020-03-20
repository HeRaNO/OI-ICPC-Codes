#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100050;
int n,q;
ll h[N],c[N];
int s[N],top;
ll L[N],R[N];

void gao()
{
	for(int i=2;i<=n+1;++i)
	{
		while(top&&c[s[top]]<c[i])R[s[top--]]=i-1;
		L[i]=s[top]+1;
		s[++top]=i;
	}
}

void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;++i)scanf("%lld",&h[i]);
	for(int i=1;i<=n;++i)c[i]=abs(h[i]-h[i-1]);
	c[n+1]=INT_MAX;
	gao();
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		ll ans=0;
		for(int i=l+1;i<=r;++i)
		{
			ll LL=max(l*1ll,L[i]-1);
			ll RR=min(r*1ll,R[i]);
			ans+=c[i]*(i-LL)*(RR-i+1);
		}
		cout<<ans<<'\n';
	}
}

int main()
{
	int Test=1;
//    cin>>Test;
	while(Test--)
	{
		solve();
	}
	return 0;
}