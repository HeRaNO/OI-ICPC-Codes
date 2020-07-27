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
const int MAXN=3e5+10,MAXM=2e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int inv2=(MOD+1)/2;
const int Lim=1<<20;

char s[MAXN],t[MAXN];
int dp[25][25];
int nxt[MAXN][30];
int lst[30];
int n,m;

int deal(int l,int r)
{
	memset(dp,0x3f,sizeof(dp));
	int ans=0;
	for(int i=0;i<=m;i++)dp[0][i]=l;
	int mx=min(m,r-l+1);
	for(int i=1;i<=mx;i++)
		for(int j=i;j<=m;j++)
		{
			dp[i][j]=min(dp[i][j],dp[i][j-1]);
			int p=dp[i-1][j-1];
			if(p>=r||p==-1)continue;
			if(nxt[p][t[j]-'a']==-1)continue;
			dp[i][j]=min(dp[i][j],nxt[p][t[j]-'a']);
			if(dp[i][j]<=r)ans=max(ans,i);
		}
	return ans;
}

void solve()
{
	scanf("%s",s+1);
	scanf("%s",t+1);
	n=LEN(s+1),m=LEN(t+1);
	memset(lst,-1,sizeof(lst));
	for(int i=n;~i;i--)
	{
		for(int j=0;j<26;j++)nxt[i][j]=lst[j];
		if(i)lst[s[i]-'a']=i;
	}
	int q;R(q);
	while(q--)
	{
		int l,r;R(l,r);
		int ans=deal(l-1,r);
		W(r-l+1+m-ans*2);
	}
}

int main()
{
	int T=1;
	R(T);
	while(T--)solve();
	return 0;
}