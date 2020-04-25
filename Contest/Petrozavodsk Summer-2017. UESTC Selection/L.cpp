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
#define GETPOS(c,x) (lower_bound(ALL(c),x)-c.begin())
#define LEN(x) strlen(x)
#define MS0(x) memset((x),0,sizeof((x)))
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
const int MAXN=1e6+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
const int inv2=5e8+4;
const int Lim=1<<20;

const int M=110119;

long long fac[MAXN],inv[MAXN],invfac[MAXN];
inline void Get_Factor_and_Inv(int n)
{
	inv[1] = fac[1] = invfac[0] = invfac[1] = 1LL;
	for (int i = 2; i <= n; i++) inv[i] = (M - M / i) * inv[M % i] % M;
	for (int i = 2; i <= n; i++) fac[i] = (fac[i - 1] * i) % M, invfac[i] = (invfac[i - 1] * inv[i]) % M;
	return ;
}

long long Lucas_C(long long n, long long m, long long M)
{
	if (n < m) return 0LL;
	if(n==m)return 1;
	if (n < M && m < M) return fac[n] * invfac[m] % M * invfac[n - m] % M;
	return Lucas_C(n / M, m / M, M) * Lucas_C(n % M, m % M, M) % M;
}

ll n,m,r;
ll x[MAXN],y[MAXN],val[MAXN],id[MAXN];

ll getv(ll x1,ll y1,ll x2,ll y2)
{
	x2-=x1;y2-=y1;
	if((x2+y2)%3)return 0;
	if(x2<0||y2<0)return 0;
	ll n=(x2+y2)/3;
	ll p=abs(x2-y2)/2;
	if(n/2<p)return 0;
	return Lucas_C(n,n/2-p,M);
}

void solve()
{
	R(n,m,r);
	if(n==1&&m==1)return W(1);
	for(int i=1;i<=r;i++)
	{
		R(x[i],y[i]);
	}
	for(int i=0;i<=r+1;i++)id[i]=i,val[i]=0;
	x[0]=y[0]=val[0]=1;
	x[r+1]=n,y[r+1]=m;
	sort(id,id+r+2,[&](int a,int b){return x[a]+y[a]<x[b]+y[b];});
	for(int q=0;q<r+1;q++)
	{
		int i=id[q];
		for(int p=q+1;p<=r+1;p++)
		{
			int j=id[p];
			ll ans=getv(x[i],y[i],x[j],y[j]);
			if(i)ans=M-ans;
			val[j]=(val[j]+ans*val[i]%M)%M;
		}
	}
	W(val[id[r+1]]);
}

int main()
{
	Get_Factor_and_Inv(M-1);
	int t=1;
	R(t);
	while(t--)solve();
	return 0;
}