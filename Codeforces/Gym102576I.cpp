#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
#define lowbit(x) x&-x
#define pb push_back
#define ls (id<<1)
#define rs (id<<1|1)
#define Rint register int
#define UNI(x) sort(ALL(x)),x.resize(unique(ALL(x))-x.begin())
#define GETPOS(c,x) (lower_bound(ALL(c),x)-c.begin())
#define LEN(x) strlen(x)
#define MS0(x) memset((x),0,sizeof((x)))
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
const int MAXN=5e5+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
const int inv2=5e8+4;
const int Lim=1<<20;

char s[MAXN];
int a[MAXN],b[MAXN],n;
vector<string> ans;

bool cmp()
{
	for(int i=n-1;~i;i--)
	{
		if(a[i]<b[i])return true;
		if(a[i]>b[i])return false;
	}
	return false;
}

void sub()
{
	for(int i=0;i<n;i++)
	{
		a[i]-=b[i];
		if(a[i]<0)
		{
			a[i]+=10;
			a[i+1]--;
		}
	}
	while(n&&!a[n-1])n--;
}

void gao()
{
	for(int i=n-1;i>=(n)/2;i--)b[i]=b[n-i-1]=a[i];
	//for(int i=n-1;i>=0;i--)cout<<a[i];puts("!");
	//for(int i=n-1;i>=0;i--)cout<<b[i];puts("");
	if(cmp())
	{
		int u=n/2;
		while(!b[u])
		{
			b[u]=9;
			u++;
		}
		b[u]--;
		while(n&&!b[n-1])n--;
	}
	string s;
	for(int i=0;i<n/2;i++)b[i]=b[n-i-1];
	for(int i=n-1;i>=0;i--)s+='0'+b[i];
	//for(int i=n-1;i>=0;i--)cout<<a[i];puts("");
	sub();

	ans.pb(s);
}

void solve()
{
	R(s);n=LEN(s);ans.resize(0);
	for(int i=0;i<n;i++)a[n-i-1]=s[i]-'0';
	while(!a[n-1])n--;
	while(n)gao();
	W(SZ(ans));
	for(auto j:ans)W(j);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int t=1;
	R(t);
	while(t--)solve();
	return 0;
}