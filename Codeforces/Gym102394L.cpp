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

const int b1=233,b2=137;
const int m1=1e9+7,m2=1e9+9;
int a[MAXN];
int vis[MAXN];
vector<pii> s[MAXN],vec;

void solve()
{
	int n,q;
	n=read();q=read();
	memset(vis,0,(n+5)*sizeof(int));
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)s[i].resize(0);vec.resize(0);
	for(int i=1;i<=n;i++)
	{
		pii tmp={0,0};
		int cnt=0;
		for(int j=0;j<n;j++)
		{
			if(i-j<1)
			{
				vec.pb({tmp.fi,tmp.se});
				break;
			}
			if(vis[a[i-j]]==i)continue;
			tmp.fi+=a[i-j];
			tmp.se+=a[i-j];
			tmp.fi=1ll*tmp.fi*b1%m1;
			tmp.se=1ll*tmp.se*b2%m2;
			vis[a[i-j]]=i;
			cnt++;
			s[cnt].pb({tmp.fi,tmp.se});
		}
	}
	for(int i=1;i<=q;i++)
	{
		int tt=0;
		int p,cnt=0;
		pii tmp={0,0};
		p=read();
		for(int i=1;i<=p;i++)
		{
			int b;b=read();tt|=b;
			if(!b)continue;cnt++;
			tmp.fi+=b;
			tmp.se+=b;
			tmp.fi=1ll*tmp.fi*b1%m1;
			tmp.se=1ll*tmp.se*b2%m2;
		}
		bool f=0;
		if(!tt)
		{
			W("Yes");
			continue;
		}
		if(cnt!=p)
		{
			for(auto j:vec)
			if(j==tmp)
			{
				W("Yes");
				f=1;
				break;
			}
		}
		else
		{
			for(auto j:s[p])
			if(j==tmp)
			{
				W("Yes");
				f=1;
				break;
			}
		}
		if(!f)W("No");
	}
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("test_output.txt","w",stdout);
	int T=1;
	T=read();
	while(T--)solve();
	return 0;
}