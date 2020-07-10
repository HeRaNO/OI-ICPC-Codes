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

int pre[MAXN],sum[MAXN];
int pick[105],a[105],n;

int ask()
{
	W(1);
	for(int i=1;i<=n;i++)printf("%d ",pick[i]);W("");
	fflush(stdout);
	string s;
	R(s);
	if(s[0]=='r')return 1;
	if(s[0]=='y')return 0;
	if(s[0]=='g')return -1;
}

void solve()
{
	R(n);
	for(int i=1;i<=n;i++)
	{
		R(a[i]);
		for(int j=0;j<=1000000;j++)
		{
			if(!j||pre[j])
			{
				if(!pre[j+a[i]])pre[j+a[i]]=i;
			}
		}
	}
	Vi v;
	for(int j=1;j<=1000000;j++)
	{
		if(pre[j])v.pb(j);
		sum[j]=sum[j-1]+(pre[j]>0);
	}
	int l=1,r=1000000;
	while(l<=r)
	{
		int res=sum[r]-sum[l-1];
		if(r==l)
		{
			W(2);
			W(r);
			return;
		}
		if(!res)
		{
			W(2);
			W(-1);
			return;
		}
		int mid=(l+r)>>1;
		int p=GETPOS(v,mid);
		if(p==SZ(v))p--;
		if(p&&abs(mid-v[p-1])<abs(mid-v[p]))p--;
		memset(pick,0,sizeof(pick));
		int qq=v[p];
		while(qq)pick[pre[qq]]++,qq-=a[pre[qq]];
		int op=ask();
		if(op==0)
		{
			W(2);
			W(v[p]);
			return;
		}
		if(op==1)r=mid-1;
		if(op==-1)l=mid+1;
	}
	W(2);
	W(l);
}

int main()
{
	int T=1;
	//R(T);
	while(T--)solve();
	return 0;
}