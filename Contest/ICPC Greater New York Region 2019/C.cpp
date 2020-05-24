#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define lowbit(x) x&-x
#define pb push_back
#define ls (u<<1)
#define rs (u<<1|1)
#define Rint register int
#define ALL(x) (x).begin(),(x).end()
#define UNI(x) sort(ALL(x)),x.resize(unique(ALL(x))-x.begin())
#define GETPOS(c,x) (lower_bound(ALL(c),x)-c.begin())
#define LEN(x) strlen(x)
#define MS0(x) memset((x),0,sizeof((x)))
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
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
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.F); putchar(' '); _W(x.S);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }
const int MOD=1e9+7,mod=1e9+7;
ll qpow(ll a,ll b) {ll res=1;a%=MOD; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
const int MAXN=3e5+10,MAXM=2e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int inv2=5e8+4;
const int Lim=1<<20;

int n,m;
Vi g[MAXN];
db dp[21][30000];
db ans[21];

db getans(int s,int w,int now)
{
	memset(dp,0,sizeof(dp));
	memset(ans,0,sizeof(ans));
	dp[s][0]=1;int cur=1;
	for(int jj=1;jj<=20000;jj++)
	{
		for(int i=1;i<=n;i++)
		{
			for(auto j:g[i])
			{
				if(j==i)ans[j]+=dp[i][cur-1]/((db)SZ(g[i]));
				else dp[j][cur]+=dp[i][cur-1]/((db)SZ(g[i]));
			}
		}
		cur++;
	}
	return ans[w];
}

void solve()
{
	R(n,m);
	for(int i=1;i<=n;i++)
	{
		int p;R(p);
		g[i].pb(i);
		for(int j=1;j<=p;j++)
		{
			int c;R(c);
			g[i].pb(c);
		}
	}
	for(int i=1;i<=m;i++)
	{
		int pp,s,w;R(pp,s,w);
		printf("%d %.5lf\n",i,getans(s,w,i));
	}
}

int main()
{
	int T = 1;
	//R(T);
	while (T--)solve();
	return 0;
}