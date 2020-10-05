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
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.fi);putchar(' '); _W(x.se);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }
const int MOD=1e9+7,mod=998244353;
ll qpow(ll a,ll b) {ll res=1;a%=MOD; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
const int MAXN=1e6+10,MAXM=2e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX,SLINF=0x3f3f3f3f3f3f3f3fLL;
const int inv2=(MOD+1)/2;
const int Lim=1<<20;

int l[MAXN],r[MAXN];
int n,m,p,q;
struct Matrix
{
	ll a[30][30];
	int n,m;
	void init(int N,int M)
	{
		n=N,m=M;
		memset(a,0,sizeof(a));
	}
	Matrix operator * (const Matrix &rhs)const
	{
		Matrix res;
		res.init(n,rhs.m);
		for(int k=1;k<=m;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=rhs.m;j++)
				res.a[i][j]+=a[i][k]*rhs.a[k][j];
		return res;
	}
}A,B;
void solve()
{
	A.init(n,m);
	B.init(p,q);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)R(A.a[i][j]);
	for(int i=1;i<=p;i++)
		for(int j=1;j<=q;j++)R(B.a[i][j]);
	if(m!=p)
	{
		W("undefined");
		return;
	}
	Matrix res=A*B;
	for(int i=1;i<=res.n;i++)
	{
		printf("| ");
		for(int j=1;j<=res.m;j++)
		printf("%lld ",res.a[i][j]);
		W("|");
	}
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("test_output.txt","w",stdout);
	int T=1;
	//R(T);
	while(scanf("%d%d%d%d",&n,&m,&p,&q)==4&&(n||m||p||q))
		printf("Case #%d:\n",T++),solve();
	return 0;
}
