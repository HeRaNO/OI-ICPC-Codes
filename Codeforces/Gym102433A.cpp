#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
#define lowbit(x) x&-x
#define pb push_back
#define ls (id<<1)
#define rs (id<<1|1)
#define Rint register int
#define UNI(x) sort(ALL(x)),x.resize(unique(ALL(x))-x.begin())
typedef long long ll;
typedef double db;
typedef pair<db,ll> pii;
const int MAXN=2e6+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
const int inv2=5e8+4;

int n,u,v;
ll w;
long long f[MAXN],s[MAXN],t[MAXN],all,sz[MAXN],h[MAXN],sumt[MAXN];
vector <pair<int,ll> > g[MAXN];

inline void dfs(int x,int fa)
{
	sz[x]=1;
	sumt[x]=t[x];
	for (auto v:g[x])
		if (v.first!=fa)
		{
			dfs(v.first,x);
			sumt[x]+=sumt[v.first];
			sz[x]+=sz[v.fi];
		}
	for (auto v:g[x])
		if (v.first!=fa)
		{
			f[x]+=f[v.first]+v.second*sumt[v.first];
			h[x]+=h[v.fi]+v.se*sz[v.fi];
		}
	return ;
}

void dfs2(int u,int fa)
{
	for (auto v:g[u])
		if (v.first!=fa)
		{
			f[v.first]=f[u]+v.second*(all-sumt[v.first]*2);
			h[v.fi]=h[u]+v.se*(n-sz[v.fi]*2);
			dfs2(v.first,u);
		}
	return ;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&t[i]),all+=t[i];
	for (int i=1;i<n;i++)
	{
		scanf("%d %d %lld",&u,&v,&w);
		g[u].push_back({v,w});g[v].push_back({u,w});
	}
	dfs(1,-1);
	dfs2(1,-1);
	for (int i=1;i<=n;i++) printf("%lld\n",f[i]+h[i]*t[i]);
	return 0;
}
