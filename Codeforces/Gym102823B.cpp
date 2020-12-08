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
const int MOD=998244353,mod=998244353;
ll qpow(ll a,ll b) {ll res=1;a%=MOD; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
const int MAXN=5e5+10,MAXM=2e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int inv2=(MOD+1)/2;
const int Lim=1<<20;

int add (int a, int b) { return (a += b) >= mod ? a - mod : a; }
int sub (int a, int b) { return (a -= b) >= 0 ? a : a + mod; }
int mul (long long a, int b) { return a * b % mod; }
int ksm (ll a, ll b) { ll ret = 1; while (b) { if (b & 1) ret = 1ll * ret * a % mod; a = 1ll * a * a % mod; b >>= 1; } return ret; }

int rev[Lim+5],lg2[Lim+5],rt[Lim+5],irt[Lim+5];
int k,lim,type;

void init()         //��ԭ��
{
	for(int i=2;i<=Lim;i++)lg2[i]=lg2[i>>1]+1;
	rt[0]=1;
	rt[1]=ksm(3,(MOD-1)/Lim);   //��һ��ԭ��
	irt[0]=1;
	irt[1]=ksm(rt[1],MOD-2);   //����С
	for(int i=2;i<=Lim;i++)
	{
		rt[i]=mul(rt[i-1],rt[1]);
		irt[i]=mul(irt[i-1],irt[1]);
	}
}

void NTT(Vi &f,int type,int lim)
{
	f.resize(lim);
	int w,y,l=lg2[lim]-1;
	for(int i=1;i<lim;i++)
	{
		rev[i]=(rev[i>>1]>>1)|((i&1)<<l);
		if(i>=rev[i])continue;
		swap(f[i],f[rev[i]]);           //����
	}
	l=Lim>>1;
	for(int mid=1;mid<lim;mid<<=1)
	{
		for(int j=0;j<lim;j+=(mid<<1))
		{
			for(int k=0;k<mid;k++)
			{
				w=type==1?rt[l*k]:irt[l*k];
				y=mul(w,f[j|k|mid]);
				f[j|k|mid]=sub(f[j|k],y);
				f[j|k]=add(f[j|k],y);
			}
		}
		l>>=1;
	}
	if(type==1)return;
	y=ksm(lim,MOD-2);
	for(int i=0;i<lim;i++)
		f[i]=mul(f[i],y);
}

void NTTTMD(Vi &F,Vi &G)
{
	int n=SZ(F)+SZ(G);
	lim=1;
	while(lim<=n)lim<<=1;
	F.resize(lim);G.resize(lim);
	NTT(F,1,lim),NTT(G,1,lim);
	for(int i=0;i<lim;i++)F[i]=mul(F[i],G[i]);
	NTT(F,-1,lim);
	F.resize(n-1);
}

int n,a[MAXN],L,m;
ll inv[MAXN];
int getinv(int x)
{
	if(x==0)return 1;
	return ksm(x,MOD-2);
}
void solve()
{
	R(n,L,m);
	for(int i=0;i<n;i++)R(a[i]);
	reverse(a,a+n);
	Vi t1,t2;
	t1.resize(n),t2.resize(n);
	ll tmp=1;t1[0]=tmp;
	for(int i=1;i<n;i++)
	{
		tmp=mul(tmp,m-1+i);
		tmp=mul(tmp,inv[i]);
		t1[i]=tmp;
	}
	tmp=1;
	t2[0]=1;
	for(int i=1;i*L<n&&i<=m;i++)
	{
		tmp=mul(tmp,m-i+1);
		tmp=mul(tmp,inv[i]);
		t2[i*L]=tmp;
		if(i&1)t2[i*L]=(MOD-t2[i*L])%MOD;
	}
	NTTTMD(t1,t2);
	Vi t3;
	for(int i=0;i<n;i++)t3.pb(a[i]);
	NTTTMD(t3,t1);
	t3.resize(n);
	reverse(ALL(t3));
	W(t3);
}

int main()
{
	inv[1]=1;
	for (int i=2;i<=300000;i++) inv[i]=1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
	init();
	int T;
	scanf("%d",&T);
	for(int kase=1;kase<=T;kase++)
	{
		printf("Case %d: ",kase);
		solve();
	}
	return 0;
}