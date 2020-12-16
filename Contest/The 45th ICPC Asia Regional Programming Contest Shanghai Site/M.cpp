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
const int MAXN=4e5+10,MAXM=3e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int inv2=(MOD+1)/2;
const int Lim=1<<20;

map<string,int> mp[MAXN];
int n,m,tot;
char s[MAXN];
int insert_Trie(int last,string &s)
{
	if(!mp[last][s])mp[last][s]=++tot;
	return mp[last][s];
}
int dp[MAXN];
bool cut[MAXN];

void solve()
{
	R(n,m);
	tot=0;
	for(int i=1;i<=n;i++)
	{
		R(s);
		int len=LEN(s);
		int u=0,v=0;
		string tmp;
		while(v<len)
		{
			if(s[v]=='/')
			{
				u=insert_Trie(u,tmp);
				tmp.clear();
			}
			else tmp+=s[v];
			v++;
		}
		u=insert_Trie(u,tmp);
	}
	for(int i=1;i<=m;i++)
	{
		R(s);
		int len=LEN(s);
		int u=0,v=0;
		string tmp;
		while(v<len)
		{
			if(s[v]=='/')
			{
				u=insert_Trie(u,tmp);
				tmp.clear();
			}
			else tmp+=s[v];
			v++;
		}
		u=insert_Trie(u,tmp);
		dp[u]=1;
	}
	for(int i=tot;~i;i--)
		for(auto j:mp[i])
		dp[i]+=dp[j.se];
	int ans=0;
	for(int i=1;i<=tot;i++)
	{
		if(!dp[i]&&!cut[i])
		{
			cut[i]=1;
			ans++;
		}
		if(cut[i])
		{
			for(auto j:mp[i])
				cut[j.se]+=cut[i];
		}
	}
	for(int i=0;i<=tot+5;++i)mp[i].clear();
	memset(cut,0,(tot+5));
	memset(dp,0,(tot+5)*sizeof(int));
	W(ans);
}

int main()
{
	int T=1;
	scanf("%d",&T);
	for(int kase=1;kase<=T;kase++)
	{
		//printf("Case #%d: ",kase);
		solve();
	}
	return 0;
}
