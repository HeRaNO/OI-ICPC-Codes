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
#define Flush fflush(stdout)
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
const int MAXN=1e6+10,MAXM=2e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX,SLINF=0x3f3f3f3f3f3f3f3fLL;
const int inv2=(MOD+1)/2;
const int Lim=1<<20;

struct Dijkstra_with_pile
{
	int head[MAXN],to[MAXM],_next[MAXM],ecnt=0;
	ll val[MAXM];
	void init(int n=MAXN)
	{
		memset(head,0,n*sizeof(int));
		ecnt=0;
	}
	void add_Edge(int u,int v,ll w)
	{
		_next[++ecnt]=head[u];
		to[ecnt]=v;
		val[ecnt]=w;
		head[u]=ecnt;
	}
	ll dis[MAXN];
	priority_queue<pll,vector<pll>,greater<pll> >pq;
	void dijkstra(int s)
	{
		memset(dis,0x3f,sizeof(dis));
		dis[s]=0;
		while(!pq.empty())pq.pop();
		pq.push({0,s});
		while(!pq.empty())
		{
			int u=pq.top().second,p=pq.top().first;
			pq.pop();
			if(p>dis[u])continue;
			for(int i=head[u];i;i=_next[i])
			{
				int v=to[i];
				if(dis[v]>dis[u]+val[i])
				{
					dis[v]=dis[u]+val[i];
					pq.push({dis[v],v});
				}
			}
		}
	}
}G;

int n,m,k;
int f[MAXN],d[MAXN];
ll g[50][50];
ll dp[30][(1<<18)+5];
ll ans=0,VAL=1e15;
void solve()
{
	R(n,m,k);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		R(u,v,w);
		G.add_Edge(u,v,w);
		G.add_Edge(v,u,w);
	}
	for(int i=0;i<k;i++)
	{
		R(f[i],d[i]);
		G.dijkstra(f[i]);
		ans+=min(G.dis[d[i]],VAL);
	}
	for(int i=0;i<k;i++)
	{
		G.dijkstra(d[i]);
		for(int j=0;j<k;j++)if(i!=j)
		{
			g[i][j]=G.dis[f[j]];
			if(g[i][j]>VAL)g[i][j]=VAL;
		}
	}
	int all=(1<<k);
	memset(dp,0x3f,sizeof(dp));
	for(int i=0;i<k;i++)
	dp[i][(1<<i)]=0;
	for(int st=0;st<all;st++)
	{
		for(int i=0;i<k;i++)if(st&(1<<i))
			for(int j=0;j<k;j++)if(!(st&(1<<j)))
			{
				dp[j][st|(1<<j)]=min(dp[j][st|(1<<j)],dp[i][st]+g[i][j]);
			}
	}
	ll res=llINF;
	for(int i=0;i<k;i++)
		res=min(res,dp[i][all-1]);
	if(ans+res>=VAL)return W(-1);
	W(ans+res);
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
