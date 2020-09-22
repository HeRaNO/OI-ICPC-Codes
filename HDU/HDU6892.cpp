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
const int MAXN=2e6+10,MAXM=2e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX,SLINF=0x3f3f3f3f3f3f3f3fLL;
const int inv2=(MOD+1)/2;
const int Lim=1<<20;

bool ispri[MAXM];
int p[MAXN],mu[MAXM],phi[MAXM],sum[MAXM],pcnt;
void get_pri(int n)
{
	ispri[1]=mu[1]=phi[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!ispri[i])p[++pcnt]=i,mu[i]=-1,phi[i]=i-1;
		for(int j=1;j<=pcnt&&i*p[j]<=n;j++)
		{
			ispri[i*p[j]]=1;
			if(i%p[j]==0)
			{
				phi[i*p[j]]=p[j]*phi[i];
				break;
			}
			mu[i*p[j]]=-mu[i];
			phi[i*p[j]]=phi[i]*(p[j]-1);
		}
	}
}

int l[MAXN];
void solve()
{
	int n,ans=0,pile=0;
	R(n);
	for(int i=1;i<=n;i++)R(l[i]);
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		if(l[i]%2==0)cnt++;
		while(l[i]%2==0)l[i]/=2;
		for(int j=2;j<=pcnt;j++)
		{
			while(l[i]%p[j]==0)l[i]/=p[j],cnt++;
		}
		if(l[i]>1)cnt++;
		ans^=cnt;
	}
	if(ans)W("W");
	else W("L");
}

int main()
{
	get_pri(32000);
	//freopen("input.txt","r",stdin);
	int T=1;
	R(T);
	while(T--)solve();
	return 0;
}
