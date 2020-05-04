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

struct Node
{
	ll id,x,y;
	db val;
	bool operator < (const Node &rhs)const
	{
		return val>rhs.val;
	}
}e[MAXN];

priority_queue<Node> pq;
int p[MAXN];
bool vis[MAXN];
vector<int> g[MAXN];

void solve()
{
	int n,m,k;
	R(n,m,k);
	for(int i=1;i<=k;++i)
	{
		scanf("%d",&p[i]);
	}
	for(int i=1;i<=n;i++)e[i].id=i;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		R(u,v);
		g[u].pb(v);g[v].pb(u);
		e[u].x++,e[u].y++;
		e[v].x++,e[v].y++;
	}
	for(int i=1;i<=k;i++)
	{
		vis[p[i]]=1;
		for(auto j:g[p[i]])
		{
			e[j].y--;
		}
	}
	for(int i=1;i<=n;i++)e[i].val=(db)e[i].y/e[i].x;
	for(int i=1;i<=n;i++)if(!vis[i])
	{
		pq.push(e[i]);
	}
	db ans=pq.top().val;
	int id=0,cnt=0;
	Vi ANS;
	while(!pq.empty())
	{
		Node tmp=pq.top();pq.pop();
		if(vis[tmp.id])continue;
		vis[tmp.id]=1;
		cnt++;
		for(auto v:g[tmp.id])
		{
			if(vis[v])continue;
			e[v].y--;
			e[v].val=(db)e[v].y/e[v].x;
			pq.push(e[v]);
		}
		while(!pq.empty()&&vis[pq.top().id])pq.pop();
		db res=-1;
		if(!pq.empty())res=max(res,pq.top().val);
		if(ans<res)
		{
			ans=res;
			id=cnt;
		}
		ANS.pb(tmp.id);
	}
	W(SZ(ANS)-id);
	for(int i=id;i<SZ(ANS);i++)printf("%d ",ANS[i]);
}

int main()
{
	//freopen("in.txt","r",stdin);
	int t=1;
	//R(t);
	while(t--)solve();
	return 0;
}