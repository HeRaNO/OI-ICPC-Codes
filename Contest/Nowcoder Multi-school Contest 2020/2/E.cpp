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

int n,m;
int a[MAXN];
int b[MAXN];
int c[MAXN];
int ans[MAXN];

int add(int a,int b)
{
	return a+b>=MOD?a+b-MOD:a+b;
}

int sub (int a,int b)
{
	return (a-b+MOD)%MOD;
}

int mul (int a,int b)
{
	return (ll)a*b%MOD;
}

void OR(int *f,int x)
{
	 for (int o = 2, k = 1; o <= n; o <<= 1, k <<= 1)
		for (int i = 0; i < n; i += o)
			for (int j = 0; j < k; j++)
				f[i+j+k] = add(f[i+j+k],mul(f[i+j],x));
}

void AND(int *f,int x)
{
	for (int o = 2, k = 1; o <= n; o <<= 1, k <<= 1)
		for (int i = 0; i < n; i += o)
			for (int j = 0; j < k; j++)
				f[i+j] = add(f[i+j],mul(f[i+j+k],x));
}

void XOR(int *f,int p)
{
	int inv2=(MOD+1)/2;
	for (int o = 2, k = 1; o <= n; o <<= 1, k <<= 1)
		for (int i = 0; i < n; i += o)
			for (int j = 0; j < k; j++)
			{
				int u,t;
				u=f[j+i];t=f[j+k+i];
				f[j+i]=mul(p^1?inv2:1,add(u,t));
				f[j+k+i]=mul(p^1?inv2:1,sub(u,t));
			}
}

void solve()
{
	R(m);
	for(int i=1;i<=m;i++)
	{
		int p;R(p);
		a[p]=1;ans[0]=max(ans[0],p);
	}
	n=(1<<18);
	for(int i=0;i<n;i++)b[i]=a[i];
	XOR(a,1);XOR(b,1);
	for(int i=1;i<=20;i++)
	{
		for(int i=0;i<n;i++)c[i]=mul(a[i],b[i]);
		for(int i=0;i<n;i++)a[i]=c[i];
		XOR(c,MOD-1);
		for(int j=n;~j;j--)
		{
			if(c[j])
			{
				ans[i]=j;
				break;
			}
		}
	}
	for(int i=21;i<m;i++)ans[i]=ans[i-2];
	for(int i=0;i<m;i++)printf("%d ",ans[i]);
}

int main()
{
	int T=1;
	//R(T);
	while(T--)solve();
	return 0;
}