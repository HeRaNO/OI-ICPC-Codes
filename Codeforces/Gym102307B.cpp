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

int p[MAXN],n;
void manacher(char *x){
	int id,mx=0,i;
	for(i=1;i<=(n<<1)+1;i++){
		if(i<mx)p[i]=min(p[2*id-i],mx-i);
		else p[i]=1;
		while(x[i-p[i]]==x[i+p[i]]&&i-p[i]>=1&&i+p[i]<=(n<<1)+1) p[i]++;
		if(mx<i+p[i])mx=p[id=i]+i;
	}
}

char s[MAXN],t[MAXN];
int cnt;

void solve()
{
	scanf("%s",s+1);
	n=LEN(s+1);
	t[++cnt]='#';
	for(int i=1;i<=n;i++)
	{
		t[++cnt]=s[i];
		t[++cnt]='#';
	}
	manacher(t);
	int ans=0;
	for(int i=cnt;~i;i--)
	{
		//W(t[i],i,p[i]);
		if(p[i]+i==cnt+1)ans=max(ans,p[i]);
	}
	for(int i=n-ans+1;i;i--)s[++n]=s[i];
	printf("%s",s+1);
}

int main()
{
	int T=1;
	//R(T);
	while(T--)solve();
	return 0;
}