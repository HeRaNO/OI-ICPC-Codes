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
const int MAXN=6e6+10,MAXM=2e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX,SLINF=0x3f3f3f3f3f3f3f3fLL;
const int inv2=(MOD+1)/2;
const int Lim=1<<20;

struct Node
{
	int l,r,rk,lch,rch;
}e[MAXN];

int p[MAXN],d[MAXN],b[MAXN],n;
int stk[MAXN],top,rk[MAXN],tot;

void dfs(int u)
{
	int p1=p[u/2-1]%10,p2=d[u/2-1];
	if(u&1){rk[u/2]=tot++;return;}
	//W(u,e[u].lch,e[u].rch,p1,p2);
	if(p2>=p1)
	{
		dfs(e[u].lch);
		dfs(e[u].rch);
	}
	else
	{
		dfs(e[u].rch);
		dfs(e[u].lch);
	}
}

void ins(int i)
{
	int q=b[i];
	bool f=0;
	e[i].lch=e[i].rch=0;
	while(top&&b[stk[top]]>q)top--,f=1;
	if(top)e[stk[top]].rch=i;
	if(f)e[i].lch=stk[top+1];
	stk[++top]=i;
}

void solve()
{
	top=tot=0;
	R(n);
	ll pseed,pa,pb,pmod;
	R(pseed,pa,pb,pmod);
	for(int i=0;i<n;i++)p[i]=i;
	for(int i=1;i<n;i++)
	{
		swap(p[pseed%(i+1)],p[i]);
		pseed=(pseed*pa+pb)%pmod;
	}
	ll dseed,da,db,dmod;
	R(dseed,da,db,dmod);
	for(int i=0;i<n;i++)d[i]=dseed%10,dseed=(dseed*da+db)%dmod;
	for(int i=0;i<=n;i++)b[i*2+1]=INF;
	for(int i=0;i<n;i++)
	{
		if(p[i]%10==d[i])b[i*2+2]=INF-1;
		else b[i*2+2]=p[i];
	}
	for(int i=1;i<=n*2+1;i++)ins(i);
	dfs(stk[1]);
	ll ans=0,base=10000019;
	for(int i=n;~i;i--)ans=(ans*base+rk[i])%MOD;
	W(ans);
	//for(int i=0;i<=n;i++)printf("%d ",rk[i]);W("");
}

int main()
{
	//freopen("input.txt","r",stdin);
	int T=1;
	R(T);
	while(T--)solve();
	return 0;
}
