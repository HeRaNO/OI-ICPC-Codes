#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define lowbit(x) x&-x
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define UNI(x) sort(ALL(x)),x.resize(unique(ALL(x))-x.begin())
#define GETPOS(c,x) (lower_bound(ALL(c),x)-c.begin())
#define LEN(x) strlen(x)
#define MS0(x) memset((x),0,sizeof((x)))
#define Rint register int
#define ls (u<<1)
#define rs (u<<1|1)
#define Flush fflush(stdout)
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
void _W(const ull &x) { printf("%llu", x); }
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.fi);putchar(' '); _W(x.se);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }
const int MOD=1e9+7,mod=998244353;
ll qpow(ll a,ll b) {ll res=1;a%=MOD; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
const int MAXN=2e5+10,MAXM=2e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX,SLINF=0x3f3f3f3f3f3f3f3fLL;
const int inv2=(MOD+1)/2;
const int Lim=1<<20;

int n, m,u,v,d,x;
ll  dp[2][MAXN];
Vll vec[MAXN];

void DP(int L,int R,int l,int r)
{
	if(L > R) return;
	int mid = (L + R) >> 1, cur = mid;
	for (int i = min(r, mid - 1); i >= l;i--)
	{
		if(mid>SZ(vec[x])+i)
			break;
		if(dp[u][d+mid*x]<dp[v][d+i*x]+vec[x][mid-i-1])
		{
			cur = i;
			dp[u][d + mid * x] = dp[v][d + i * x] + vec[x][mid - i - 1];
		}
	}
	DP(L, mid - 1, l, cur);
	DP(mid + 1, R, cur, r);
}

void solve()
{
	memset(dp[0], 0,(m+5)* sizeof(ll));
	for (int i = 1; i <= 100;i++)
		vec[i].resize(0);
	for (int i = 1; i <= n;i++)
	{
		ll w, v;
		R(w, v);
		vec[w].pb(v);
	}
	for (int i = 1; i <= 100;i++)
		sort(ALL(vec[i]), greater<ll>());
	v = 1;
	for (int i = 1; i <= 100;i++)
	{
		if(vec[i].empty())
			continue;
		for (int j = 1; j < SZ(vec[i]);j++)
			vec[i][j] = vec[i][j - 1] + vec[i][j];
		u = v,v=u^1;
		memcpy(dp[u], dp[v], (m+5)*sizeof(ll));
		for (int j = 0; j < i;j++)
		{
			d = j;
			x = i;
			DP(0, (m - j) / i, 0, (m - j) / i);
		}
		for (int j = 0; j <= m;j++)
			dp[u][j] = max(dp[u][j], dp[v][j]);
	}
	W(dp[u][m]);
}

int main()
{
	int T=1;
	//R(T);W(T);
	while(scanf("%d%d",&n,&m)==2)solve();
	return 0;
}
