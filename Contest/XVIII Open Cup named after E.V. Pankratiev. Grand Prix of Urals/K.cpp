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
const int MAXN=1e6+10,MAXM=2e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int inv2=(MOD+1)/2;
const int Lim=1<<20;

int n,m,D[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
char s[60][60];

queue<tuple<int,int,int,int>> q;
int dis[60][60][60][60],DIS[60][60];
int pre[60][60][60][60];

void deal(int a,int b,int c,int d,int w,int p=-1)
{
	if(a<1||a>n||c<1||c>n)return;
	if(b<1||b>m||d<1||d>m)return;
	if(~dis[a][b][c][d])return;
	if(s[a][b]=='#'||s[c][d]=='#')return;
	dis[a][b][c][d]=w;
	pre[a][b][c][d]=p;
	q.push({a,b,c,d});
}

pii P[60][60];

void solve()
{
	memset(pre,-1,sizeof(pre));
	memset(dis,-1,sizeof(dis));
	R(n,m);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			deal(i,j,i,j,0);
			deal(i,j,i+1,j,1);
			deal(i,j,i-1,j,1);
			deal(i,j,i,j+1,1);
			deal(i,j,i,j-1,1);
		}
	while(!q.empty())
	{
		int a,b,c,d;
		tie(a,b,c,d)=q.front();q.pop();
		int w=dis[a][b][c][d];
		deal(a-1,b,c+1,d,w+2,0);
		deal(a+1,b,c-1,d,w+2,1);
		deal(a,b+1,c,d-1,w+2,3);
		deal(a,b-1,c,d+1,w+2,2);
	}
	memset(DIS,-1,sizeof(DIS));
	int sx,sy,tx,ty;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]=='S')sx=i,sy=j;
			if(s[i][j]=='F')tx=i,ty=j;
		}
	DIS[tx][ty]=0;
	queue<pii> qq;
	qq.push({tx,ty});
	while(!qq.empty())
	{
		int a,b;tie(a,b)=qq.front();qq.pop();
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			if(DIS[i][j]==-1&&dis[a][b][i][j]<=100&&dis[a][b][i][j]>=0)
			DIS[i][j]=DIS[a][b]+1,qq.push({i,j}),P[i][j]={a,b};
	}
	int x=sx,y=sy;
	W(DIS[x][y]);
	if(DIS[x][y]==-1)return;
	while(x!=tx||y!=ty)
	{
		string S;
		int a=x,b=y,c,d;tie(c,d)=P[x][y];
		while(pre[a][b][c][d]!=-1)
		{
			int p=pre[a][b][c][d];
			a+=D[p][0],b+=D[p][1];
			c-=D[p][0],d-=D[p][1];
			if(p==0)S+='D';
			if(p==1)S+='U';
			if(p==2)S+='R';
			if(p==3)S+='L';
		}
		string tmp=S;
		reverse(ALL(tmp));//W(x,y,P[x][y].fi,P[x][y].se);
		if(a<c)S+='D';
		if(b<d)S+='R';
		if(a>c)S+='U';
		if(b>d)S+='L';
		S+=tmp;
		W(S);
		tie(x,y)=P[x][y];
	}
}

int main()
{
	int T=1;
	//R(T);
	while(T--)solve();
	return 0;
}

/*
5 5
S....
.....
.#...
.....
....F
*/