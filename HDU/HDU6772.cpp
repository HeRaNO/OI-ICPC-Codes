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
const int MAXN=3e6+10,MAXM=2e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int inv2=(MOD+1)/2;
const int Lim=1<<20;

struct Node
{
	int a,b,c,d;
};

ll ans=0;
int cnt[56],n,k;
Node vec[56][56];
int mx[56][5];

void dfs(int dep,int a,int b,int c,int d)
{
	if(dep==k+1)
	{
		ans=max(ans,1ll*a*b*c*d);
		return;
	}
	ll tmp=1ll*(a+mx[dep][0])*(b+mx[dep][1])*(c+mx[dep][2])*(d+mx[dep][3]);
	if(tmp<=ans)return;
	bool f=0;
	for(int i=1;i<=cnt[dep];i++)
	{
		f=1;
		dfs(dep+1,a+vec[dep][i].a,b+vec[dep][i].b,c+vec[dep][i].c,d+vec[dep][i].d);
	}
	if(!f)dfs(dep+1,a,b,c,d);
}

void solve()
{
	ans=0;
	R(n,k);
	memset(mx,0,sizeof(mx));
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;i++)
	{
		int t=0;
		int a,b,c,d;R(t,a,b,c,d);
		cnt[t]++;
		vec[t][cnt[t]]={a,b,c,d};
		mx[t][0]=max(mx[t][0],a);
		mx[t][1]=max(mx[t][1],b);
		mx[t][2]=max(mx[t][2],c);
		mx[t][3]=max(mx[t][3],d);
	}
	for(int i=k-1;i;i--)
		for(int j=0;j<=3;j++)mx[i][j]+=mx[i+1][j];
	dfs(1,100,100,100,100);
	W(ans);
}

int main()
{
	int T=1;
	R(T);
	while(T--)solve();
	return 0;
}