#include<bits/stdc++.h>
#include<cstdio>
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
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.F); putchar(' '); _W(x.S);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }
const int MOD=1e9+7,mod=1e9+7;
ll qpow(ll a,ll b) {ll res=1;a%=MOD; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
const int MAXN=2e6+10,MAXM=2e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int inv2=5e8+4;
const int Lim=1<<20;

pll e[MAXN];
bool vis[MAXN];
int ans;
ll n,k,m;
priority_queue<pll,vector<pll>,greater<pll> > pq1,pq2,pq3;

void solve()
{
	memset(vis,0,(n+5));
	Vi vec;
	while(!pq1.empty())pq1.pop();
	while(!pq2.empty())pq2.pop();
	while(!pq3.empty())pq3.pop();
	for(int i=1;i<=n;i++)
	{
		R(e[i].fi,e[i].se);
		vec.pb(i);
	}
	sort(ALL(vec),[&](int a,int b){return e[a].se<e[b].se;});
	for(int i=0;i<k;i++)
	{
		int j=vec[i];
		if(m<e[j].se)
		{
			return;
		}
		ans++;
		m-=e[j].se;
		vis[j]=1;
		pq1.push({e[j].fi-e[j].se,j});
	}
	for(int i=1;i<=n;i++)if(!vis[i])
	{
		pq2.push({e[i].fi,i});
		pq3.push({e[i].se,i});
	}
	while(1)
	{
		while(!pq2.empty()&&vis[pq2.top().se])pq2.pop();
		while(!pq3.empty()&&vis[pq3.top().se])pq3.pop();
		ll op=0,mn=llINF;
		if(!pq2.empty()&&mn>pq2.top().fi)
		{
			mn=pq2.top().fi;
			op=1;
		}
		if(!pq1.empty()&&!pq3.empty()&&mn>pq3.top().fi+pq1.top().fi)
		{
			mn=pq3.top().fi+pq1.top().fi;
			op=2;
		}
		if(m<mn)return;
		m-=mn;
		ans++;
		if(op==2)
		{
			vis[pq3.top().se]=1;
			pq3.pop();
			pq1.pop();
		}
		if(op==1)
		{
			vis[pq2.top().se]=1;
			pq2.pop();
		}
		//for(int j=1;j<=n;j++)printf("%d ",vis[j]);W("");
	}
}

int main()
{
	int T=1;
	//R(T);
	while(scanf("%lld %lld %lld",&n,&k,&m)==3)
	{
		solve();
		W(ans);
		ans=0;
	}
	return 0;
}