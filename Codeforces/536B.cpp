#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define lowbit(x) x&-x
#define pb push_back
#define ls (id<<1)
#define rs (id<<1|1)
#define Rint register int
#define ALL(x) (x).begin(),(x).end()
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
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.F); putchar(' '); _W(x.S);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }
const int MAXN=2e6+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
const int inv2=5e8+4;
const int Lim=1<<20;

set<int> st;
int nxt[MAXN];
void chk(string &a)
{
	string tmp;
	tmp+=a;
	for(int i=1;i<SZ(tmp);i++)
	{
		int u=nxt[i-1];
		while(u>0&&tmp[u]!=tmp[i])u=nxt[u-1];
		if(tmp[u]==tmp[i])u++;
		nxt[i]=u;
	}
	int p=nxt[SZ(tmp)-1];
	while(p)
	{
		st.insert(p);
		p=nxt[p-1];
	}
}

int n,m;
string s;
int y[MAXN];
ll ksm(ll x,ll v){ll ans=1;for(;v;x=x*x%MOD,v>>=1)if(v&1)ans=ans*x%MOD;return ans;}
ll sum[MAXN];

void solve()
{
	R(n,m,s);chk(s);
	for(int i=1;i<=m;i++)R(y[i]);
	int sz=SZ(s),mx=0;
	for(int i=1;i<=m;i++)
	{
		sum[y[i]]++;
		sum[y[i]+sz]--;
		if(mx<=y[i])mx=y[i]+sz;
		else if(!st.count(mx-y[i]))return W(0);
	}
	ll ans=0;
	for(int i=1;i<=n;i++)sum[i]+=sum[i-1],ans+=(sum[i]==0);
	W(ksm(26,ans));
}

int main()
{
	int t=1;
	//R(t);
	while(t--)solve();
	return 0;
}