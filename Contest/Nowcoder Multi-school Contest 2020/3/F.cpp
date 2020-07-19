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
const int MOD=998244353,mod=998244353;
ll qpow(ll a,ll b) {ll res=1;a%=MOD; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
const int MAXN=2e6+10,MAXM=2e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int inv2=(MOD+1)/2;
const int Lim=1<<20;

int T,prime[MAXN],tot,pfcnt;
bool not_prime[MAXN];
long long pf[MAXN];
vector <long long> fac;

inline void LinearShaker(int n)
{
	for (int i=2;i<=n;i++)
	{
		if (!not_prime[i]) prime[++tot]=i;
		for (int j=1;i*prime[j]<=n;j++)
		{
			not_prime[i*prime[j]]=true;
			if (!(i%prime[j])) break;
		}
	}
	return ;
}

inline int pfact(long long n)
{
	pfcnt=0;int cnt=0;
	for (int i=1;1LL*prime[i]*prime[i]<=n;i++)
	{
		if (n%prime[i]) continue;
		pf[++pfcnt]=1,++cnt;
		while (!(n%prime[i]))pf[pfcnt]*=prime[i],n/=prime[i];
	}
	if (n!=1){pf[++pfcnt]=n;++cnt;}
	return cnt;
}

inline bool fact(long long n)
{
	int t=pfact(n);fac.clear();
	fac.push_back(1);int lst=1;long long lstpri=1,now;
	for (int i=1;i<=pfcnt;i++)
	{
		if (pf[i]==lstpri) now*=lstpri;
		else now=pf[i],lst=fac.size();
		for (int j=0;j<lst;j++) fac.push_back(now*fac[j]);
		lstpri=pf[i];
	}
	return true;
}

long long exgcd(long long a,long long b,long long &x,long long &y)
{
	if (!b){x=1;y=0;return a;}
	long long t=exgcd(b,a%b,y,x);y-=x*(a/b);
	return t;
}

void solve()
{
	int a,b;
		long long e=-1,f=-1,d=-1,c=-1,g,k=-1,l=-1;
		scanf("%d %d",&a,&b);
		//fact(b);
		g=__gcd(a,b);
		if(g>1)
		{
			return W(a/g+1,b/g,1,b/g);
		}
		pfact(b);
		if(pfcnt<=1)
		{
			puts("-1 -1 -1 -1");
			return;
		}
		f=pf[1];d=b/f;
		long long gg=exgcd(f,d,c,e);//W(d,f,c,e);
		c*=a;e*=-a;//W(d,f,c,e);
		if(c<0)e=-e,c=-c,swap(e,c),swap(f,d);
		while(e<=0)e+=d,c-=f;
		printf("%lld %lld %lld %lld\n",c,d,e,f);
}

int main()
{
	LinearShaker(2000000);
	int T=1;
	R(T);
	while(T--)solve();
	// system("pause");
	return 0;
}