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
const int MAXN=2e6+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
const int inv2=5e8+4;
const int Lim=1<<20;

int sg[505][505],vis[505*505];
int n,m,k,cnt,ans;

int get_SG(int x,int y,int t)
{
	if(~sg[x][y])return sg[x][y];
	for(int i=x-1;i;i--)if(i!=y)vis[get_SG(i,y,t)]=t;
	for(int i=y-1;i;i--)if(i!=x)vis[get_SG(x,i,t)]=t;
	for(int i=1;i<min(x,y);i++)vis[get_SG(x-i,y-i,t)]=t;
	for(int i=0;;i++)if(vis[i]!=t)return sg[x][y]=i;
}

void solve()
{
	memset(sg,-1,sizeof(sg));
	n=m=100;for(int i=1;i<=n;i++)sg[i][0]=sg[0][i]=sg[i][i]=0;
	scanf("%d",&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		get_SG(i,j,++cnt);
	for(int i=1;i<=k;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		if(x==0||y==0||x==y)return W("Y");
		ans^=sg[x][y];
	}
	if(!ans)puts("N");
	else puts("Y");
}

int main()
{
	//freopen("in.txt","r",stdin);
	int t=1;
	//R(t);
	while(t--)solve();
	return 0;
}