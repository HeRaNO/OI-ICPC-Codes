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
const int MAXN=4e5+10,MAXM=2e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int inv2=(MOD+1)/2;
const int Lim=1<<20;

const int b1=233,b2=137,m1=1e9+7,m2=1e9+9;
char s[500][500];
set<pii> S;

pii gethash(int pi,int pj,int n,int m)
{
	ll h1=0,h2=0;
	for(int i=pi;i<pi+n;i++)
		for(int j=pj;j<pj+m;j++)
		{
			h1=(h1*b1+s[i][j])%m1;
			h2=(h2*b2+s[i][j])%m2;
		}
	return {h1,h2};
}

char t[500][500];

void deal(int pi,int pj,int n,int m)
{
	if(S.count(gethash(pi,pj,n,m)))return;
	for(int kase=1;kase<=3;kase++)
	{
		for(int i=pi;i<pi+n;i++)
			for(int j=pj;j<pj+m;j++)
			{
				t[i][j]=s[i][j];
			}
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				s[i+pi][j+pj]=t[n-j-1+pi][i+pj];
			}
		if(S.count(gethash(pi,pj,n,m)))return;
	}
	S.insert(gethash(pi,pj,n,m));
}

void deal2(int pi,int pj,int n,int m)
{
	if(S.count(gethash(pi,pj,n,m)))return;
	for(int i=pi;i<pi+n;i++)
		for(int j=pj;j<pj+m;j++)
		{
			t[i][j]=s[i][j];
		}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			s[n-i+pi-1][m-j+pj-1]=t[i+pi][j+pj];
		}
	if(S.count(gethash(pi,pj,n,m)))return;
	S.insert(gethash(pi,pj,n,m));
}

void solve()
{
	int n,m,sl=0,sr=0;
	R(n,m);
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=2;i<=m;i++)if(s[2][i]=='#')
	{
		sl=i-2;
		break;
	}
	for(int i=2;i<=n;i++)if(s[i][2]=='#')
	{
		sr=i-2;
		break;
	}
	if(sl==1&&sr==1)
	{
		int cnt[]={0,0};
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				if(s[i][j]=='+')cnt[0]=1;
				if(s[i][j]=='.')cnt[1]=1;
			}
		return W(cnt[0]+cnt[1]);
	}
	if(sl==sr)
	{
		for(int i=2;i<=n;i+=sr+1)
			for(int j=2;j<=m;j+=sl+1)
			{
				deal(i,j,sr,sl);
			}
	}
	else
	{
		for(int i=2;i<=n;i+=sr+1)
			for(int j=2;j<=m;j+=sl+1)
			{
				deal2(i,j,sr,sl);
			}
	}
	W(SZ(S));
}

int main()
{
	int T=1;
	//R(T);
	while(T--)solve();
	return 0;
}