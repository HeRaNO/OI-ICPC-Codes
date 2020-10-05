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
const int MAXN=2e6+10,MAXM=2e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX,SLINF=0x3f3f3f3f3f3f3f3fLL;
const int inv2=(MOD+1)/2;
const int Lim=1<<20;

int n,k,ans;
char s[50][50];
int a[30],ta[30],len[10];
int nd[10],dir[10],fac[10];
bool must[30];
int getid(int x,int y)
{
	return x*n+y;
}
pii chai(int x)
{
	return {x/n,x%n};
}
void dfs(int dep)
{
	if(dep==k+1)
	{
		for(int i=0;i<n*n;i++)
			if(!a[i]&&must[i])return;
		ans++;
		return;
	}
	for(int i=0;i<n*n;i++)if(a[i]==0)
	{
		pii tmp=chai(i);
		if(tmp.fi+len[dep]<=n)
		{
			bool f=0;
			for(int j=0;j<len[dep];j++)
			{
				int p=getid(tmp.fi+j,tmp.se);
				if(a[p])
				{
					f=1;
					break;
				}
				a[p]=dep;
			}
			if(!f)dfs(dep+1);
			for(int j=0;j<len[dep];j++)
			{
				int p=getid(tmp.fi+j,tmp.se);
				if(a[p]==dep)a[p]=0;
			}
		}
		if(tmp.se+len[dep]<=n&&len[dep]>1)
		{
			bool f=0;
			for(int j=0;j<len[dep];j++)
			{
				int p=getid(tmp.fi,tmp.se+j);
				if(a[p])
				{
					f=1;
					break;
				}
				a[p]=dep;
			}
			if(!f)dfs(dep+1);
			for(int j=0;j<len[dep];j++)
			{
				int p=getid(tmp.fi,tmp.se+j);
				if(a[p]==dep)a[p]=0;
			}
		}
		a[i]=0;nd[dep]=0;
	}
}

void solve()
{
	R(n,k);
	for(int i=0;i<n;i++)scanf("%s",s[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(s[i][j]=='X')
			a[getid(i,j)]=-1;
			if(s[i][j]=='O')
			must[getid(i,j)]=1;
		}
	for(int i=1;i<=k;i++)
		R(len[i]);
	sort(len+1,len+k+1,greater<int>());
	dfs(1);
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
