#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
#define lowbit(x) x&-x
#define pb push_back
#define ls (id<<1)
#define rs (id<<1|1)
#define Rint register int
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

int n;
ll dp[2005][1<<10];
struct Node
{
	int m,i,f,o;
}e[MAXN];

int cnt;
void solve()
{
	Vi vec;
	R(n);
	for(int i=1;i<=n;i++)
	{
		int m;
		R(m);
		for(int j=1;j<=m;j++)
		{
			int a,b,c;R(a,b,c);
			vec.pb(a);vec.pb(b);
			e[++cnt]={i-1,a,b,c};
		}
	}
	vec.pb(0);
	UNI(vec);
	sort(e+1,e+cnt+1,[&](Node a,Node b){return a.f<b.f;});
	for(int i=1;i<=cnt;i++)
	{
		e[i].f=GETPOS(vec,e[i].f);
		e[i].i=GETPOS(vec,e[i].i);
	}
	memset(dp,-0x3f,sizeof(dp));
	dp[0][0]=0;int l=1;
	for(int i=1;i<SZ(vec);i++)
	{
		vector<Node> tmp;Vll ans;
		while(e[l].f==i)tmp.pb(e[l++]);
		for(int j=0;j<(1<<n);j++)
		{
			dp[i][j]=dp[i-1][j];
			for(auto k:tmp)
			{
				dp[i][j]=max(dp[i][j],dp[k.i][j]+k.o);
				if(j&(1<<k.m))dp[i][j]=max(dp[i][j],dp[k.i][j^(1<<k.m)]+k.o);
			}
		}
	}
	if(dp[SZ(vec)-1][(1<<n)-1]>0)W(dp[SZ(vec)-1][(1<<n)-1]);
	else W(-1);
}

int main()
{
	//freopen("in.txt","r",stdin);
	int t=1;
	//R(t);
	while(t--)solve();
	return 0;
}