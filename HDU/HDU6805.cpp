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
const int MAXN=8e5+10,MAXM=2e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int inv2=(MOD+1)/2;
const int Lim=1<<20;

struct Dijkstra_with_pile
{
	int head[MAXN],to[MAXM],_next[MAXM],ecnt=0;
	ll val[MAXM];
	void init(int n=MAXN)
	{
		memset(head,0,n*sizeof(int));
		memset(dis,0x3f,sizeof(dis));
		ecnt=0;
	}
	void add_Edge(int u,int v,ll w)
	{
		_next[++ecnt]=head[u];
		to[ecnt]=v;
		val[ecnt]=w;
		head[u]=ecnt;
		_next[++ecnt]=head[v];
		to[ecnt]=u;
		val[ecnt]=w;
		head[v]=ecnt;
	}
	ll dis[MAXN];
	priority_queue<pll,vector<pll>,greater<pll> >pq;
	void dijkstra(int s)
	{
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

char st[MAXN];
int op[MAXN];

void solve()
{
	int n,m,s,t,x;
	R(n,m,s,t,x);
	G.init(n*2+6);
	scanf("%s",st+1);
	for(int i=1;i<=n;i++)
	{
		if(st[i]=='L')op[i]=1;
		else if(st[i]=='R')op[i]=2;
		else if(st[i]=='M')
		{
			op[i]=3;
			G.add_Edge(i,i+n,x);
		}
	}
	for(int i=1;i<=m;i++)
	{
		int u,v,d;
		R(u,v,d);
		if(op[u]==op[v])
		{
			if(op[u]==3)
			{
				G.add_Edge(u,v,d);
				G.add_Edge(u+n,v+n,d);
			}
			else G.add_Edge(u,v,d);
		}
		else
		{
			if(op[u]==3||op[v]==3)
			{
				if(op[u]==3)
				{
					if(op[v]==1)G.add_Edge(u,v,d);
					else G.add_Edge(u+n,v,d);
				}
				else
				{
					if(op[u]==1)G.add_Edge(u,v,d);
					else G.add_Edge(v+n,u,d);
				}
			}
			else
			{
				G.add_Edge(u,v,d+x);
			}
		}
	}
	G.dijkstra(s);
	G.dijkstra(s+n);
	W(min(G.dis[t],G.dis[t+n]));
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("test_output.txt","w",stdout);
	int T=1;
	R(T);
	while(T--)solve();
	return 0;
}