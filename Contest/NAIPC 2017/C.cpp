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
const int MAXN=2e6+10,MAXM=2e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int inv2=5e8+4;
const int Lim=1<<20;

int x[305],g[305][305],n;

ll dp[2][305][305][2];

void solve()
{
	R(n);
	for(int i=0;i<n;i++)R(x[i]);
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
		if(__gcd(x[i],x[j])!=1)g[i][j]=1;
	for(int i=0;i<n;i++)dp[0][i][i][0]=dp[1][i][i][0]=1;
	for(int len=1;len<n;len++)
	{
		for(int l=0,r=l+len;r<n;l++,r++)
		{
			for(int nr=l;nr<r;nr++)
			{
				if(g[l][nr])(dp[0][l][r][0]+=(dp[0][l][nr][1]*dp[0][nr][r][0]%MOD))%=MOD;
				if(g[l][r])(dp[0][l][r][1]+=(dp[0][l][nr][0]*dp[1][nr+1][r][0])%MOD)%=MOD;
			}
			for(int nl=r;nl>l;nl--)
			{
				if(g[nl][r])(dp[1][l][r][0]+=(dp[1][nl][r][1]*dp[1][l][nl][0]%MOD))%=MOD;
				if(g[l][r])(dp[1][l][r][1]+=(dp[1][nl][r][0]*dp[0][l][nl-1][0])%MOD)%=MOD;
			}
			(dp[0][l][r][0]+=dp[0][l][r][1])%=MOD;
			(dp[1][l][r][0]+=dp[1][l][r][1])%=MOD;
		}
	}
	W(dp[1][0][n-1][0]);
}

int main()
{
	int T=1;
	//R(T);
	while(T--)solve();
	// system("pause");
	return 0;
}