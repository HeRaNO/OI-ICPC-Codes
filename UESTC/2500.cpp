// By ZXyang
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define lowbit(x) x&-x
#define pb push_back
#define ls (u<<1)
#define rs (u<<1|1)
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
const int MOD=1e9+7,mod=1e9+7;
ll qpow(ll a,ll b) {ll res=1;a%=MOD; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
const int MAXN=4e5+10,MAXM=2e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int inv2=5e8+4;
const int Lim=1<<20;


int nxt[MAXN];
void KMP(vector<int> &p)
{
	nxt[0]=-1;
	for(int i=1;i<SZ(p);i++)
	{
		int u=nxt[i-1];
		while(p[u+1]!=p[i]&&u>-1)u=nxt[u];
		if(p[i]==p[u+1])u++;nxt[i]=u;
	}
}

int p[30],cyccnt,mp[30],n,m,ans[MAXN];
vector<int> cyc[30];
char s[MAXN],t[MAXN];
bool vis[30];
vector<int> tmp;

const int MN=(1<<20);
const double pi=acos(-1);
struct cp
{
	double r,i;
	cp(double r=0,double i=0):r(r),i(i){}
	cp operator+(cp b){return cp(r+b.r,i+b.i);}
	cp operator-(cp b){return cp(r-b.r,i-b.i);}
	cp operator*(cp b){return cp(r*b.r-i*b.i,r*b.i+i*b.r);}
}w[2][MN+5],F[MN+5],G[MN+5],mp1[30],mp2[30];
int N,RE[MN+5],u[MN+5][6][6];
void init(int n)
{
	for(N=1;N<=n;N<<=1);
	cp g(cos(2*pi/N),sin(2*pi/N));int i,j,k;
	for(i=w[0][0].r=1;i<N;++i)w[0][i]=w[0][i-1]*g;
	for(i=w[1][0].r=1;i<N;++i)w[1][i]=w[0][N-i];
	for(i=j=0;i<N;RE[++i]=j)for(k=N>>1;(j^=k)<k;k>>=1);
}
void fft(cp*x,int v)
{
	int i,j,k;
	for(i=0;i<N;++i)if(i<RE[i])swap(x[i],x[RE[i]]);
	for(i=1;i<N;i<<=1)for(j=0;j<N;j+=i<<1)for(k=0;k<i;++k)
	{
		cp p=x[i+j+k]*w[v][N/(i<<1)*k];
		x[i+j+k]=x[j+k]-p;x[j+k]=x[j+k]+p;
	}
	if(v)for(i=0;i<N;++i)x[i].r/=N,x[i].i/=N;
}

int main()
{
	//freopen("24.in","r",stdin);
	for(int i=0;i<26;i++)scanf("%d",&p[i]),p[i]--;
	scanf("%s%s",s,t);n=strlen(s);m=strlen(t);
	init(n+m);
	for(int i=0;i<26;i++)if(!vis[i])
	{
		cyccnt++;
		for(int j=i;!vis[j];j=p[j])
		{
			vis[j]=1;
			cyc[cyccnt].pb(j);
			mp[j]=cyccnt;
		}
	}
	for(int i=0;i<n;i++)tmp.pb(mp[s[i]-'a']);tmp.pb(-1);
	for(int i=0;i<m;i++)tmp.pb(mp[t[i]-'a']);
	KMP(tmp);
	for(int i=n*2;i<n+m+1;i++)if(nxt[i]==n-1)ans[i-n-1]=1;
	for(int i=1;i<=cyccnt;i++)
	{
		int k=SZ(cyc[i]);
		for(int j=0;j<SZ(cyc[i]);j++)
		{
			mp1[cyc[i][j]]=cp(cos((db)2*pi*j/k),sin((db)2*pi*j/k));
			mp2[cyc[i][j]]=cp(cos((db)pi/k-(db)2*pi*j/k),sin((db)pi/k-(db)2*pi*j/k));
		}
	}
	reverse(s,s+n);
	db err=0;
	for(int i=0;i<n;i++)err+=(mp1[s[i]-'a']*mp2[s[i]-'a']).r;
	for(int i=0;i<n;i++)F[i]=mp1[s[i]-'a'];
	for(int i=0;i<m;i++)G[i]=mp2[t[i]-'a'];
	fft(F,0),fft(G,0);
	for(int i=0;i<N;i++)F[i]=F[i]*G[i];
	fft(F,1);
	for(int i=n-1;i<m;i++)if(fabs(F[i].r-err)>0.01)ans[i]=0;
	for(int i=n-1;i<m;i++)printf("%d",ans[i]);
	return 0;
}