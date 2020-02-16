#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x.begin(),x.end())
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const int MAXN=6e5+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;

ll a[MAXN],sz[MAXN],cnt,n,k;
int kase=0;
vector<int> g[MAXN];
priority_queue<ll,vector<ll>,greater<ll> >pq;

void dfs(int u,int fa,ll B)
{
	sz[u]=a[u];
	for(auto j:g[u])
		if(j!=fa)dfs(j,u,B);
	for(auto j:g[u])
		if(j!=fa)pq.push(sz[j]);
	while(!pq.empty())
	{
		ll val=pq.top();
		if(val+sz[u]<=B)
		{
			sz[u]+=val;
			pq.pop();
		}
		else break;
	}
	cnt-=SZ(pq);
	while(!pq.empty())pq.pop();
}

bool check(ll mid)
{
	cnt=k-1;
	dfs(1,0,mid);
	return cnt>=0;
}

ll mx=0;

void solve()
{
	mx=0;
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)g[i].resize(0);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]),mx=max(mx,a[i]);
	ll l=mx,r=1e18,ans=0;
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		if(check(mid))r=mid-1,ans=mid;
		else l=mid+1;
	}
	printf("Case #%d: %lld\n",++kase,ans);
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}