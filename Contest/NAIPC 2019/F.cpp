#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define lowbit(x) x&-x
#define pb push_back
#define ls (u<<1)
#define rs (u<<1|1)
#define ALL(x) (x).begin(),(x).end()
#define UNI(x) sort(ALL(x)),x.resize(unique(ALL(x))-x.begin())
#define GETPOS(c,x) (lower_bound(ALL(c),x)-c.begin())
#define LEN(x) strlen(x)
#define MS0(x) memset((x),0,sizeof((x)))
#define Rint register int
typedef unsigned int unit;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<pii> Vpii;
template<class T> void _R(T &x) { cin >> x; }
void _R(int &x) { scanf("%d", &x); }
void _R(ll &x) { scanf("%lld", &x); }
void _R(ull &x) { scanf("%llu", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }
template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const ll &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.fi); putchar(' '); _W(x.se);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }
const int MOD=1e9+7,mod=998244353;
ll qpow(ll a,ll b) {ll res=1;a%=MOD; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
const int MAXN=1e5+10,MAXM=2e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int inv2=(MOD+1)/2;
const int Lim=1<<10;

Vi f[MAXN];
int add(int x,int y){return (x+y)%MOD;}
int mul(int x,int y){return 1ll*x*y%MOD;}
int sub(int x,int y){return (x-y+MOD)%MOD;}
Vi mul(Vi &a,Vi &b)
{
	Vi ans;
	ans.resize(SZ(a)+SZ(b)-1);
	for(int i=0;i<SZ(a);i++)
		for(int j=0;j<SZ(b);j++)
		ans[i+j]=add(ans[i+j],mul(a[i],b[j]));
	return ans;
}
void Int(Vi &a)
{
	if(a.empty())return;
	a.resize(SZ(a)+1);
	for(int i=SZ(a)-2;~i;i--)a[i+1]=mul(a[i],qpow(i+1,MOD-2));
	a[0]=0;
}
int getF(Vi &a,int x)
{
	int ans=0;
	for(int i=SZ(a)-1;~i;i--)ans=add(mul(ans,x),a[i]);
	return ans;
}

Vi g[MAXN];
int b[MAXN],rt,mn[MAXN];
void dfs(int u)
{
	f[u].pb(qpow(b[u],MOD-2));
	for(auto v:g[u])
	{
		dfs(v);
		b[u]=min(b[u],b[v]);
		f[u]=mul(f[u],f[v]);
	}
	Int(f[u]);f[u][0]=getF(f[u],b[u]);
	for(int i=1;i<SZ(f[u]);i++)f[u][i]=sub(MOD,f[u][i]);
}

void solve()
{
	int n;R(n);
	for(int i=1;i<=n;i++)
	{
		int p;
		R(b[i],p);
		g[p].pb(i);
	}
	rt=g[0][0];
	dfs(rt);
	W(f[rt][0]);
}

int main()
{
	int T=1;
	//R(T);
	while(T--)solve();
	return 0;
}