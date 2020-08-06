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
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.fi);putchar(' '); _W(x.se);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }
const int MOD=998244353,mod=998244353;
ll qpow(ll a,ll b) {ll res=1;a%=MOD; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
const int MAXN=2e6+10,MAXM=2e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int inv2=(MOD+1)/2;
const int Lim=1<<20;

int a[MAXN],ans[MAXN];
int n;
int nxt(int i)
{
	return (i+1)%n;
}
int pre(int i)
{
	return (i-1+n)%n;
}

int cnt[MAXN];

const int SIZ =30000000 +3;
char buf1[SIZ];
char *p1=buf1,*p2=buf1;
inline char readchar()
{
	if(p1==p2)p1=buf1,p2=buf1+fread(buf1,1,SIZ,stdin);
	return p1==p2?EOF:*p1++;
}
inline int read()
{
	int ret,c;
	while((c=readchar())> '9'|c< '0');ret=c-'0';
	while((c=readchar())>='0'&&c<='9')ret=ret*10+c-'0';
	return ret;
}

queue<int> q;
void solve()
{
	n=read();
	for(int i=0;i<n;i++)a[i]=read();
	int p=clock();
	for(int i=0;i<n;i++)ans[i]=i,cnt[i]++;
	for(int i=0;i<n;i++)
	{
		if(a[nxt(i)]*cnt[i]>a[i]*(cnt[nxt(i)]+1))
			q.push(i);
	}
	if(q.empty())
	{
		for(int i=0;i<n;i++)printf("%d ",ans[i]+1);
		return;
	}
	while(clock()-p<CLOCKS_PER_SEC*1.5)
	{
		int i=q.front();q.pop();
		if(ans[i]==i)
		{
			if(a[nxt(i)]*cnt[i]>a[i]*(cnt[nxt(i)]+1))
			{
				ans[i]=nxt(i);
				cnt[nxt(i)]++;
				cnt[i]--;
				q.push(nxt(i));
				q.push(pre(i));
			}
		}
		else if(ans[i]==i+1)
		{
			if(a[i]*cnt[nxt(i)]>a[nxt(i)]*(cnt[i]+1))
			{
				ans[i]=i;
				cnt[i]++;
				cnt[nxt(i)]--;
				q.push(nxt(i));
				q.push(pre(i));
			}
		}
		if(q.empty())
		{
			for(int i=0;i<n;i++)printf("%d ",ans[i]+1);
			return;
		}
	}
	W(-1);
}

int main()
{
	int T=1;
	//R(T);
	while(T--)solve();
	return 0;
}