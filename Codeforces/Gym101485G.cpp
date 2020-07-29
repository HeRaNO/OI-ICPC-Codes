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
const int MAXN=6e5+10,MAXM=2e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int inv2=(MOD+1)/2;
const int Lim=1<<20;

struct Node
{
	int x,y,z;
	bool b;
	int *ans;
	bool operator == (const Node &a)const
	{
		return x==a.x&&y==a.y&&z==a.z;
	}
}a[MAXN],b[MAXN],c[MAXN];

bool cmp(Node &a,Node &b)
{
	if(b.x^a.x)return a.x<b.x;
	if(b.y^a.y)return a.y<b.y;
	return a.z<b.z;
}

int n,k,ans[MAXN]={0},d[MAXN]={0};bool f=0;

void merge2(int l,int r)
{
	if(l==r)return;
	int mid=(l+r)>>1;
	merge2(l,mid);
	merge2(mid+1,r);
	for(int i=l,j=l,k=mid+1,cnt=0;i<=r;i++)
	{
		if((k>r||b[j].z<=b[k].z)&&j<=mid)c[i]=b[j++],cnt+=c[i].b;
		else
		{
			c[i]=b[k++];
			if(!c[i].b)*c[i].ans+=cnt;
		}
	}
	for(int i=l;i<=r;i++)b[i]=c[i];
}

void merge1(int l,int r)
{
	if(l==r)return;
	int mid=(l+r)>>1;
	merge1(l,mid);
	merge1(mid+1,r);
	for(int i=l,j=l,k=mid+1;i<=r;i++)
	{
		if((k>r||a[j].y<=a[k].y)&&j<=mid)b[i]=a[j++],b[i].b=1;
		else b[i]=a[k++],b[i].b=0;
	}
	for(int i=l;i<=r;i++)a[i]=b[i];
	if(l==1&&r==5)f=1;
	merge2(l,r);
}

void solve()
{
	int n;
	R(n);
	for(int i=1;i<=n;i++)
	{
		int p;R(p);
		a[p].x=i;
	}
	for(int i=1;i<=n;i++)
	{
		int p;R(p);
		a[p].y=i;
	}
	for(int i=1;i<=n;i++)
	{
		int p;R(p);
		a[p].z=i;
	}
	for(int i=1;i<=n;i++)
	{
		a[i].ans=&ans[i];
		ans[i]=0;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=n-1;i;i--)if(a[i]==a[i+1])
		*a[i].ans=*a[i+1].ans+1;
	merge1(1,n);
	ll ANS=0;
	for(int i=1;i<=n;i++)ANS+=ans[i];
	W(ANS);
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