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

const ll M=1e15+37;
char s[2][4][35];
ll pre[2][35],n[2],ans[2];
Vll v[2];

void dfs1(int dep,int mxdep,int p,ll val)
{
	if(dep==mxdep)
	{
		//W(val);
		v[p].pb(val);
		return;
	}
	for(int i=0;i<3;i++)
	{
		dfs1(dep+1,mxdep,p,(val+s[p][i][dep]*pre[p][dep])%M);
	}
}

void dfs2(int dep,int mxdep,int p,ll val)
{
	if(dep==mxdep)
	{
		//W(val,v[p][0]);
		ans[p]=min(ans[p],(val+v[p][0])%M);
		int l=0,r=SZ(v[p])-1,res=0;
		while(l<=r)
		{
			ll mid=(l+r)>>1;
			if(v[p][mid]+val>=M)r=mid-1,res=mid;
			else l=mid+1;
		}
		ans[p]=min(ans[p],(val+v[p][res])%M);
		return;
	}
	for(int i=0;i<3;i++)
	{
		dfs2(dep+1,mxdep,p,(val+s[p][i][dep]*pre[p][dep])%M);
	}
}

void solve()
{
	ans[0]=ans[1]=M-1;
	R(n[0],n[1]);
	for(int i=0;i<3;i++)R(s[0][i]);
	for(int i=0;i<3;i++)R(s[1][i]);
	pre[0][n[0]-1]=1;pre[1][n[1]-1]=1;
	for(int i=n[0]-2;~i;i--)pre[0][i]=pre[0][i+1]*127%M;
	for(int i=n[1]-2;~i;i--)pre[1][i]=pre[1][i+1]*127%M;
	dfs1(0,n[0]/2,0,0);sort(ALL(v[0]));dfs2(n[0]/2,n[0],0,0);
	dfs1(0,n[1]/2,1,0);sort(ALL(v[1]));dfs2(n[1]/2,n[1],1,0);
	//W(ans[0],ans[1]);
	if(ans[0]<ans[1])W("Owls");
	else if(ans[0]==ans[1])W("Tie");
	else W("Goats");
}

int main()
{
	int T=1;
	//R(T);
	while(T--)solve();
	return 0;
}