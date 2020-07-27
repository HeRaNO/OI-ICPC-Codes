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
const int inv2=(MOD+1)/2;
const int Lim=1<<20;

ll dis[605][605],dp[605][605];
int n,m,K,b[605];

void mymin(ll &a,ll b)
{
	a=min(a,b);
}

void solve()
{
	memset(dis,0x1f,sizeof(dis));
	R(n,m,K);
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		ll u,v,w;
		R(u,v,w);
		dis[v][u]=dis[u][v]=min(dis[u][v],w);
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	b[0]=1;
	memset(dp,0x1f,sizeof(dp));;
	dp[0][1]=0;
	for(int i=1;i<=K;i++)R(b[i*2-1],b[i*2]);
	for(int k=1;k<=K*2;k++)
	{
		//for(int i=1;i<=n;i++)mymin(dp[k-1][b[k-1]],dp[k-1][i]);
		for(int i=1;i<=n;i++)
		{
			int u=b[k-1],v=b[k];
			mymin(dp[k][i],dp[k-1][i]+min(dis[u][v],dis[i][v]));
			//mymin(dp[k][u],dp[k-1][i]+min(dis[u][v],dis[i][v]));
			for(int j=1;j<=n;j++)
			{
				ll dis1=min(dis[u][j],dis[i][j]);
				ll dis2=min(min(dis[u][v],dis[i][v]),dis[j][v]);
 
				mymin(dp[k][j],dp[k-1][i]+dis1+dis2);
			}
		}
	}
	ll ans=llINF;
	for(int i=1;i<=n;i++)mymin(ans,dp[K*2][i]);
	W(ans);
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("test_output.txt","w",stdout);
	int T=1;
	//R(T);
	while(T--)solve();
	return 0;
}