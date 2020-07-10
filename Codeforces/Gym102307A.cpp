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

struct Node
{
	int dx,dy,x,y;
	bool operator < (const Node &rhs)const
	{
		if(dx^rhs.dx)return dx<rhs.dx;
		if(dy^rhs.dy)return dy<rhs.dy;
		if(x^rhs.x)return x<rhs.x;
		return y<rhs.y;
	}
};

void solve()
{
	map<pii,ll> mp;
	set<Node> s;
	set<int> sttt;
	mp.clear();
	ll ans=0;
	int n;
	R(n);
	for(int i=1;i<=n;i++)
	{
		int x1,x2,y1,y2;
		R(x1,y1,x2,y2);
		int dx=x2-x1,dy=y2-y1;
		int g=__gcd(dx,dy);
		dx/=g;dy/=g;
		if(dx<0)
		{
			dx=-dx;
			dy=-dy;
		}
		if(dx)
		{
			assert(dx>0);
			int nx=(x1%dx+dx)%dx;
			int ny=y1+(nx-x1)/dx*dy;
			//W(dx,dy,nx,ny);
			if(!s.count({dx,dy,nx,ny}))
			{
				ans+=mp[{-dy,dx}];
				ans+=mp[{dy,-dx}];
				mp[{dx,dy}]++;
				s.insert({dx,dy,nx,ny});
			}
		}
		else
		{
			if(!sttt.count(x1))
			{
				ans+=mp[{-dy,dx}];
				ans+=mp[{dy,-dx}];
				mp[{dx,dy}]++;
				sttt.insert(x1);
			}
			//W(SZ(sttt),*sttt.begin());
		}
		//W(dx,dy,ans);
	}
	W(ans);
}

int main()
{
	int T=1;
	R(T);
	while(T--)solve();
	return 0;
}