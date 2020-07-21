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
const int MOD=998244353,mod=998244353;
ll qpow(ll a,ll b) {ll res=1;a%=MOD; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
const int MAXN=2e5+10,MAXM=2e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int inv2=(MOD+1)/2;
const int Lim=1<<20;

char s[MAXN],t[MAXN];
int n;
int cnt[MAXN][10];
Vi v[MAXN];
ll ans;
Vi allvec;

void solve()
{
	//freopen("input.txt","r",stdin);
	scanf("%s",t+1);
	n=LEN(t+1);
	for(int c='a';c<='j';c++)
	{
		for(int i=1;i<=n;i++)s[i]=t[i];
		allvec.resize(0);
		for(int i=n;i;i--)
		{
			v[i].resize(10);
			int p=i;
			for(int j=i;j<n;j++)
			{
				if(s[j]<=s[j+1])break;
				s[j+1]=s[j];p=j+1;
			}
			for(int j=p;j>=i;j--)
			{
				for(int k=0;k<10;k++)cnt[j][k]=cnt[j+1][k];
				cnt[j][s[j]-'a']++;
				if(s[j]==c)
				{
					for(int k=0;k<10;k++)v[j][k]=cnt[j][k];
					allvec.pb(j),ans+=n-j+1;
				}
			}
		}
		//for(int i=1;i<=n;i++)W(v[i]);
		sort(ALL(allvec),[&](int a,int b){return v[a]<v[b];});
		for(int pp=1;pp<SZ(allvec);pp++)
		{
			int i=allvec[pp],k=allvec[pp-1];
			ll p=0;
			for(int j=0;j<10;j++)
			{
				if(v[i][j]==v[k][j])p+=v[i][j];
				else
				{
					p+=min(v[i][j],v[k][j]);
					break;
				}
			}
			ans-=p;
		}
	}
	W(ans);
}

int main()
{
	int T=1;
	//R(T);
	while(T--)solve();
	return 0;
}