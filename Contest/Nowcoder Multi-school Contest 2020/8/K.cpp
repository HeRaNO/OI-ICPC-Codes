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
const int MAXN=6e5+10,MAXM=2e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int inv2=(MOD+1)/2;
const int Lim=1<<20;

ll a[MAXN],b[MAXN];
pll x[1<<18];
ll y[1<<18],lazy[1<<18];

inline bool isneg(long long x){return x<0;}

struct longint
{
	bool neg;
	unsigned long long a;
	longint(){}
	longint(unsigned long long _a,bool _x):a(_a),neg(_x){}
	inline longint operator +(const long long &x)const{
		long long r=abs(x);
		if (neg^isneg(x))
		{
			if (a<r) return longint(r-a,isneg(x));
			else return longint(a-r,neg);
		}
		else return longint(a+r,neg);
	}
	inline void write()
	{
		if (neg&&a) putchar('-');
		printf("%llu\n",a);
		return ;
	}
}ans;

inline void BuildTree(int u,int l,int r)
{
	lazy[u]=0;
	if (l+1==r)
	{
		x[u]={a[l],l};y[u]=b[l];
		return ;
	}
	int m=l+r>>1;BuildTree(u<<1,l,m);BuildTree(u<<1|1,m,r);
	x[u]=max(x[u<<1],x[u<<1|1]);
	y[u]=min(y[u<<1],y[u<<1|1]);
	return ;
}

inline void add(int u,int v)
{
	y[u]+=v;lazy[u]+=v;
	return ;
}

inline void PushDown(int u)
{
	if (!lazy[u]) return ;
	add(u<<1,lazy[u]);add(u<<1|1,lazy[u]);lazy[u]=0;
	return ;
}

inline void modify(int u,int l,int r,int v,int pl,int pr)
{
	if (l==pl&&r==pr){add(u,v);return ;}
	int m=pl+pr>>1;PushDown(u);
	if (r<=m) modify(u<<1,l,r,v,pl,m);
	else if (m<=l) modify(u<<1|1,l,r,v,m,pr);
	else
	{
		modify(u<<1,l,m,v,pl,m);
		modify(u<<1|1,m,r,v,m,pr);
	}
	y[u]=min(y[u<<1],y[u<<1|1]);
	return ;
}

inline int query(int u,int l,int r,int pl,int pr)
{
	if (pl+1==pr) return !y[u]?pl:-1;
	PushDown(u);
	if (y[u]) return -1;
	int m=pl+pr>>1;
	if (r<=m) return query(u<<1,l,r,pl,m);
	else if (m<=l) return query(u<<1|1,l,r,m,pr);
	else
	{
		int t=query(u<<1,l,m,pl,m);
		if (!~t) return query(u<<1|1,m,r,m,pr);
		return t;
	}
}

inline pll qmax(int u,int l,int r,int pl,int pr)
{
	if (pl==l&&pr==r) return x[u];
	int m=pl+pr>>1;
	if (r<=m) return qmax(u<<1,l,r,pl,m);
	else if (m<=l) return qmax(u<<1|1,l,r,m,pr);
	else return max(qmax(u<<1,l,m,pl,m),qmax(u<<1|1,m,r,m,pr));
}

void solve()
{
	int n;
	R(n);
	for(int i=1;i<=n;i++)R(a[i]),a[i]+=a[i-1];
	for(int i=1;i<=n;i++)R(b[i]);
	BuildTree(1,1,n+1);
	ll ans1=b[1];
	ans=longint(0,false);
	for(int i=1;i<=ans1;i++)
	{
		int p=query(1,1,n+1,1,n+1);
		if(p==-1)p=n+1;
		pll tmp=qmax(1,1,p,1,n+1);
		ans=ans+tmp.fi;
		modify(1,1,tmp.se+1,-1,1,n+1);
	}
	printf("%lld ",ans1);
	ans.write();
}

int main()
{
	int T=1;
	R(T);
	for(int kase=1;kase<=T;kase++)
	{
		printf("Case #%d: ",kase);
		solve();
	}
	return 0;
}