#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x.begin(),x.end())
#define lowbit(x) x&-x
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const int MAXN=3e5+10,MAXM=2e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;

int n,m,k;
int fa[MAXN],ff[MAXN];
ll sz[MAXN];

int _find(int x)
{
	return x^fa[x]?fa[x]=_find(fa[x]):fa[x];
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)fa[i]=i,sz[i]=1;
	for(int i=1;i<=k;i++)scanf("%d",&ff[i]);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		u=_find(u);v=_find(v);
		if(u==v)continue;
		fa[u]=v;
		sz[v]+=sz[u];
	}
	vector<ll> v;
	for(int i=1;i<=k;i++)
	{
		int u=ff[i];
		u=_find(u);
		v.push_back(sz[u]);
		sz[u]=0;
	}
	ll num=0;
	for(int i=1;i<=n;i++)
	{
		int u=_find(i);
		if(sz[u])
		{
			num+=sz[u];
			sz[u]=0;
		}
	}
	*max_element(v.begin(),v.end())+=num;
	ll ans=0;
	for(auto j:v)
		ans+=(j-1)*j/2;
	cout<<ans-m;
	return 0;
}