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
const int MAXN=2e5+10,MAXM=2e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int inv2=5e8+4;
const int Lim=1<<20;

Vll F;
struct edge {
	int to, capacity, cost, rev;
	edge() {}
	edge(int to, int _capacity, int _cost, int _rev) :to(to), capacity(_capacity), cost(_cost), rev(_rev) {}
};
int n,m;
class Min_Cost_Max_Flow {
public:

	//调用前初始化
	void init(int n) {
		V = n;
		for (int i = 0; i <= V; ++i)G[i].clear();
	}

	//加边
	void add_Edge(int from, int to, int cap, int cost) {
		G[from].push_back(edge(to, cap, cost, G[to].size()));
		G[to].push_back(edge(from, 0, -cost, G[from].size() - 1));
	}

	//flow是自己传进去的变量，就是最后的最大流，返回的是最小费用
	void Min_cost_max_flow(int s, int t, int f) {
		fill(H, H + 1 + V, 0);
		while (f) {
			priority_queue<pii, vector<pii>, greater<pii>> q;
			fill(dis, dis + 1 + V, INF);
			dis[s] = 0;
			q.push(pii(0, s));
			while (!q.empty()) {
				pii now = q.top(); q.pop();
				int u = now.second;
				if (dis[u] < now.first)continue;
				for (int i = 0; i < G[u].size(); ++i) {
					edge& e = G[u][i];
					if (e.capacity > 0 && dis[e.to] > dis[u] + e.cost + H[u] - H[e.to]) {
						dis[e.to] = dis[u] + e.cost + H[u] - H[e.to];
						PreV[e.to] = u;
						PreE[e.to] = i;
						q.push(pii(dis[e.to], e.to));
					}
				}
			}
			if (dis[t] == INF)break;
			for (int i = 0; i <= V; ++i)H[i] += dis[i];
			F.push_back(H[n]);
			int d = f;
			for (int v = t; v != s; v = PreV[v])d = min(d, G[PreV[v]][PreE[v]].capacity);
			f -= d;
			for (int v = t; v != s; v = PreV[v]) {
				edge& e = G[PreV[v]][PreE[v]];
				e.capacity -= d;
				G[v][e.rev].capacity += d;
			}
		}
	}
private:
	int V, H[MAXN + 5], dis[MAXN + 5], PreV[MAXN + 5], PreE[MAXN + 5];
	vector<edge> G[MAXN + 5];
}G;

void solve(int u,int v)
{
	ll a=0,b=v,s=v;
	for(auto j:F)
	{
		if(s>=u)
		{
			a+=j*u;
			s-=u;
		}
		else
		{
			a+=j*s;
			s=0;
		}
	}
	if(s)return W("NaN");
	ll g=__gcd(a,b);
	printf("%lld/%lld\n",a/g,b/g);
}

int main()
{
	while(scanf("%d%d",&n,&m)==2)
	{
		G.init(n);
		F.clear();
		for(int i=1;i<=m;i++)
		{
			int u,v,c;R(u,v,c);
			G.add_Edge(u,v,1,c);
		}
		G.Min_cost_max_flow(1,n,INF);
		int q;R(q);
		while(q--)
		{
			int u,v;R(u,v);
			solve(u,v);
		}
	}
	return 0;
}