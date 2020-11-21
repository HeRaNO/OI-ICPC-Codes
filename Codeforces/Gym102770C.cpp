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
void _W(const ull &x) { printf("%llu", x); }
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.fi);putchar(' '); _W(x.se);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }
const int MOD=1e9+7,mod=998244353;
ll qpow(ll a,ll b) {ll res=1;a%=MOD; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
const int MAXN=4e6+10,MAXM=2e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX,SLINF=0x3f3f3f3f3f3f3f3fLL;
const int inv2=(MOD+1)/2;
const int Lim=1<<20;

struct ACautomaton
{
	struct Node
	{
		int fail,son[26],dep;
		ll val;
	}t[MAXN];
	bool vis[MAXN];
	int cnt=0;
	void init()
	{
		for(int i=0;i<=cnt+5;i++)
		{
			t[i].val=t[i].fail=t[i].dep=0;
			vis[i]=false;
			memset(t[i].son,0,sizeof(t[i].son));
		}
		cnt=0;
	}
	void insert_Trie(char *s,ll val)
	{
		int u=0,n=strlen(s);
		for(int i=0;i<n;i++)
		{
			if(!t[u].son[s[i]-'a'])t[u].son[s[i]-'a']=++cnt,t[cnt].dep=t[u].dep+1;
			u=t[u].son[s[i]-'a'];
		}
		vis[u]=true;
		t[u].val+=val;
	}
	queue<int> q;
	void getfail()
	{
		for(int i=0;i<26;i++)if(t[0].son[i])q.push(t[0].son[i]);
		while(!q.empty())
		{
			int u=q.front();q.pop();
			for(int i=0;i<26;i++)
			{
				if(t[u].son[i])
				{
					t[t[u].son[i]].fail=t[t[u].fail].son[i];
					q.push(t[u].son[i]);
				}
				else t[u].son[i]=t[t[u].fail].son[i];
			}
		}
	}
	ll calc(char *s,int n)
	{
		if(!n)return 0;
		s[n]='\0';
		int u=0;
		ll ans=0;
		for(int i=0;i<n;i++)
		{
			u=t[u].son[s[i]-'a'];
		}
		if(t[u].dep!=n)return -1;
		if(!vis[u])return -1;
		return t[u].val;
	}
}G;

char s[1005][1005];
char t[MAXN];
int n,m;
ll cp[30];

void solve()
{
	ll ans=0;
	R(n,m);
	G.init();
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s[i]+1);
		s[i][n+1]='#';s[i][n+2]='\0';
		s[n+1][i]='#';s[n+2][i]='\0';
	}
	memset(cp,0,sizeof(cp));
	for(int i=1;i<=m;i++)
	{
		int p;
		R(t,p);
		int nn=LEN(t);
		if(nn==1)
		{
			cp[t[0]-'a']+=p;
		}
		G.insert_Trie(t,p);
	}
	G.getfail();
	for(int i=1;i<=n;i++)
	{
		int tot=0;
		for(int j=1;j<=n+1;j++)
		{
			if(s[i][j]=='#')
			{
				ll res=G.calc(t+1,tot);
				if(res==-1)return W(-1);
				ans+=res,tot=0;
			}
			else t[++tot]=s[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		int lst=0,tot=0;
		for(int j=1;j<=n+1;j++)
		{
			if(s[j][i]=='#')
			{
				ll res=G.calc(t+1,tot);
				if(res==-1)return W(-1);
				ans+=res,tot=0;
			}
			else t[++tot]=s[j][i];
		}
	}
	W(ans);
}

int main()
{
	//freopen("input.txt","r",stdin);
	int T=1;
	R(T);
	while(T--)solve();
	return 0;
}