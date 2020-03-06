#include <bits/stdc++.h>
#define ll long long
#define mem(a,b) memset(a,b,sizeof(a))
#define ls id<<1
#define rs id<<1|1
#define pii pair<int,ll>
#define mp(a,b) make_pair((a),(b))
using namespace std;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
const int N=300050;
int n;
ll a[N],ans;
vector <pii> e[N];
ll dp[N];

void dfs(int u,int fa)
{
	ll mx1=0,mx2=0;
	for(auto p:e[u])
	{
		int v=p.first;
		ll cost=p.second;
		if(v==fa)continue;
		dfs(v,u);
		if(dp[v]-cost>=mx1)mx2=mx1,mx1=dp[v]-cost;
		else if(dp[v]-cost>=mx2)mx2=dp[v]-cost;
	}
	ans=max(ans,mx1+mx2+a[u]);
	dp[u]=mx1+a[u];
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<n;++i)
	{
		int x,y;ll c;
		scanf("%d%d%lld",&x,&y,&c);
		e[x].push_back({y,c});
		e[y].push_back({x,c});
	}
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}
