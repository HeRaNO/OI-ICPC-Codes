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

vector<ll> g[MAXN];
ll ans;

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n*(n-1)/2;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[u].pb(w);
		g[v].pb(w);
	}
	for(int i=1;i<=n;i++)sort(ALL(g[i]));
	for(int i=1;i<=n;i++)
	{
		int sz=SZ(g[i]);
		for(int j=0;j<sz;j+=2)ans+=g[i][j+1];
	}
	cout<<ans;
	return 0;
}