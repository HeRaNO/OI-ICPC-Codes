#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define lowbit(x) x&-x
#define pb emplace_back
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
const int MAXN=2e6+10,MAXM=2e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX,SLINF=0x3f3f3f3f3f3f3f3fLL;
const int inv2=(MOD+1)/2;
const int Lim=1<<20;


const int SIZ =100000000 +3;
char buf1[SIZ];
char *p1=buf1,*p2=buf1;
inline char readchar()
{
	if(p1==p2)p1=buf1,p2=buf1+fread(buf1,1,SIZ,stdin);
	return p1==p2?EOF:*p1++;
}
inline int read()
{
	int ret,c;
	while((c=readchar())> '9'|c< '0');ret=c-'0';
	while((c=readchar())>='0'&&c<='9')ret=ret*10+c-'0';
	return ret;
}

Vi vec[MAXN];
Vi tmp;
ll laz[MAXN];
Vi g[MAXN];
int n,k;
ll val[MAXN];
void solve()
{
	n=read();
	k=0;
	memset(laz,0,(n+5)*sizeof(ll));
	tmp.resize(0);
	for(int kase=1;kase<=n;kase++)
	{
		g[kase].resize(0);
		vec[kase].resize(0);
		int op;
		op=read();
		if(op==1)
		{
			int sz=read();k+=sz;
			for(int i=1;i<=sz;i++)
			{
				int p;p=read();
				vec[kase].pb(p);
				tmp.pb(p);
			}
		}
		else
		{
			int u,v;u=read();v=read();
			g[kase].pb(u);
			g[kase].pb(v);
		}
	}
	memset(val,0,(k+10)*sizeof(ll));
	UNI(tmp);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<SZ(vec[i]);j++)vec[i][j]=GETPOS(tmp,vec[i][j]);
	}
	laz[n]=1;
	ll sum=0;
	for(int i=n;i;i--)
	{
		for(auto v:g[i])laz[v]+=laz[i];
		for(auto v:vec[i])val[v]+=laz[i],sum+=laz[i];
	}
	ll cnt=*max_element(val,val+k+5);
	W(min(sum,(sum-cnt)*2));
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("test_output.txt","w",stdout);
	int T=1;
	R(T);
	while(T--)solve();
	return 0;
}
