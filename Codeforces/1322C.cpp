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

vector<int> g[MAXN];
ll c[MAXN];

bool cmp(int &a,int &b)
{
	if(SZ(g[a])^SZ(g[b]))return SZ(g[a])<SZ(g[b]);
	return g[a]<g[b];
}

int id[MAXN];

void solve()
{
	int n,m;
	ll ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&c[i]);
	for(int i=1;i<=n;i++)g[i].resize(0);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++)id[i]=i;
	for(int i=1;i<=n;i++)sort(ALL(g[i]));
	sort(id+1,id+n+1,cmp);
	for(int l=1;l<=n;)
	{
		while(SZ(g[id[l]])==0&&l<=n)l++;
		if(l>n)break;
		int r=l;
		ll sum=c[id[l]];
		while(r<n&&g[id[l]]==g[id[r+1]])r++,sum+=c[id[r]];
		ans=__gcd(ans,sum);
		l=r+1;
	}
	printf("%lld\n",ans);
}

int main()
{
	//srand(time(0))
	int t;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
