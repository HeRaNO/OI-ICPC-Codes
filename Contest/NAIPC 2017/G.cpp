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

struct ISAP {
	struct Edge {
		ll v, w, nxt;
	} edge[MAXM];
	ll tot, num, s, t,n;
	ll head[MAXN];
	void init() {
		memset(head, -1, sizeof(head));
		tot = 0;
	}
	void add_Edge(ll u, ll v, ll w) {
		assert(u&&v);
		edge[tot].v = v;
		edge[tot].w = w;
		edge[tot].nxt = head[u];
		head[u] = tot++;
		edge[tot].v = u;
		edge[tot].w = 0;
		edge[tot].nxt = head[v];
		head[v] = tot++;
	}

	ll  d[MAXN], vis[MAXN], gap[MAXN];
	void bfs() {
		memset(d, 0, (n+5)*sizeof(ll));
		memset(gap, 0, (n+5)*sizeof(ll));
		memset(vis, 0, (n+5)*sizeof(ll));
		queue<int>q;
		q.push(t);
		vis[t] = 1;
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (int i = head[u]; ~i; i = edge[i].nxt) {
				int v = edge[i].v;
				if (!vis[v]) {
					d[v] = d[u] + 1;
					gap[d[v]]++;
					q.push(v);
					vis[v] = 1;
				}
			}
		}
	}

	ll last[MAXN];
	ll dfs(int u, ll f) {
		if (u == t) return f;
		ll sap = 0;
		for (int i = last[u]; ~i; i = edge[i].nxt) {
			int v = edge[i].v;
			if (edge[i].w > 0 && d[u] == d[v] + 1) {
				last[u] = i;
				ll tmp = dfs(v, min(f - sap, edge[i].w));
				edge[i].w -= tmp;
				edge[i ^ 1].w += tmp;
				sap += tmp;
				if (sap == f) return sap;
			}
		}
		if (d[s] >= num) return sap;
		if (!(--gap[d[u]])) d[s] = num;
		++gap[++d[u]];
		last[u] = head[u];
		return sap;
	}

	ll solve(int st, int ed, int n) {
		ll flow = 0;
		num = n;
		s = st;
		t = ed;
		bfs();
		memcpy(last, head, sizeof(head));
		while (d[s] < num) flow += dfs(s, INF);
		return flow;
	}
} G;

int lg2[MAXN];
int a[60][60];
int idx[60][60][20][20];

void deal(int a,int b,int c,int d,int id)
{
	int p1=lg2[b-a],p2=lg2[d-c];
	G.add_Edge(id,idx[a][c][p1][p2],INF);
	G.add_Edge(id,idx[b-(1<<p1)+1][c][p1][p2],INF);
	G.add_Edge(id,idx[a][d-(1<<p2)+1][p1][p2],INF);
	G.add_Edge(id,idx[b-(1<<p1)+1][d-(1<<p2)+1][p1][p2],INF);
	//W(a,b,c,d,b-(1<<p1)+1,d-(1<<p2)+1);
}

void solve()
{
	G.init();
	G.s=++G.n;
	G.t=++G.n;
	for(int i=2;i<=60;i++)lg2[i]=lg2[i>>1]+1;
	int n,m,k;
	R(n,m,k);
	for(int i=0;(1<<i)<=n;i++)
		for(int j=0;(1<<j)<=m;j++)
			for(int x=0;x+(1<<i)<=n;x++)
				for(int y=0;y+(1<<j)<=m;y++)
					idx[x][y][i][j]=++G.n;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			R(a[i][j]);
			G.add_Edge(idx[i][j][0][0],G.t,a[i][j]);
		}
	for(int i=1;(1<<i)<=n;i++)
		for(int x=0;x+(1<<i)<=n;x++)
			for(int y=0;y<m;y++)
			{
				G.add_Edge(idx[x][y][i][0],idx[x][y][i-1][0],INF);
				G.add_Edge(idx[x][y][i][0],idx[x+(1<<(i-1))][y][i-1][0],INF);
			}
	for(int i=0;(1<<i)<=n;i++)
		for(int j=1;(1<<j)<=m;j++)
		{
			for(int x=0;x+(1<<i)<=n;x++)
				for(int y=0;y+(1<<j)<=m;y++)
				{
					G.add_Edge(idx[x][y][i][j],idx[x][y+(1<<(j-1))][i][j-1],INF);
					G.add_Edge(idx[x][y][i][j],idx[x][y][i][j-1],INF);
				}
		}
	for(int i=1;i<=k;i++)
	{
		int a,b,c,d,w;
		R(a,b,c,d,w);
		G.add_Edge(G.s,++G.n,w);
		deal(a-1,b-1,c-1,d-1,G.n);
	}
	W(G.solve(G.s,G.t,G.n));
}

int main()
{
	int T=1;
	//R(T);
	while(T--)solve();
	return 0;
}