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

namespace SA{
	int sa[MAXN],h[MAXN],rk[MAXN],c[MAXN],l[MAXN],p[MAXN],s[MAXN<<1],t[MAXN<<1],n;
	#define rep(i,j,k) for(int i=(j),LIM=(k);i<=LIM;i++)
	#define per(i,j,k) for(int i=(j),LIM=(k);i>=LIM;i--)
	#define pushS(x) sa[l[s[x]]--]=x
	#define pushL(x) sa[l[s[x]]++]=x
	#define _Sort(v) fill(sa,sa+n,-1),fill(c,c+m,0);                             \
	rep(i,0,n-1) c[s[i]]++;rep(i,1,m-1) c[i]+=c[i-1];                            \
	rep(i,0,m-1) l[i]=c[i]-1;per(i,n1-1,0) pushS(v[i]);                          \
	rep(i,0,m-1) l[i]=c[i-1];rep(i,0,n-1) if(sa[i]>0&&t[sa[i]-1]) pushL(sa[i]-1);\
	rep(i,0,m-1) l[i]=c[i]-1;per(i,n-1,0) if(sa[i]>0&&!t[sa[i]-1])pushS(sa[i]-1);
	void sais(int n,int m,int *s,int *t,int *p){
		int n1 = t[n-1] = 0 , ch = rk[0] = -1 , *s1 = s+n;
		per(i,n-2,0) t[i]=s[i]^s[i+1]?s[i]>s[i+1]:t[i+1];
		rep(i,1,n-1) rk[i]=t[i-1]&&!t[i]?p[n1]=i,n1++:-1;
		_Sort(p);
		for(int i=0,x,y;i<n;i++) if(~(x=rk[sa[i]])){
			if(ch<1||(p[x+1]-p[x])^(p[y+1]-p[y])) ch++;
			else for(int j=p[x],k=p[y];j<=p[x+1];j++,k++)
				if((s[j]<<1|t[j])^(s[k]<<1|t[k])){ ch++;break; }
			s1[y=x]=ch;}
		if(ch+1<n1) sais(n1,ch+1,s1,t+n,p+n1);
		else rep(i,0,n1-1) sa[s1[i]]=i;
		rep(i,0,n1-1) s1[i]=p[sa[i]];
		_Sort(s1);
	}
	template<class T>void SA(int n,const T &S){
		memset(sa,0,(n+5)*sizeof(int));
		memset(p,0,(n+5)*sizeof(int));
		memset(t,0,2*(n+5)*sizeof(int));
		memset(rk,0,(n+5)*sizeof(int));
		memset(h,0,(n+5)*sizeof(int));
		memset(c,0,(n+5)*sizeof(int));
		memset(l,0,(n+5)*sizeof(int));
		memset(s,0,2*(n+5)*sizeof(int));
		rep(i,0,n-1) s[i]=S[i];s[n++]=0;
		sais(n,500,s,t,p);
		rep(i,0,n-1) rk[sa[i]]=i;
		for(int i=0,k=0;i<n-1;h[rk[i++]]=k)
			for(k&&k--;i+k<n&&s[i+k]==s[sa[rk[i]-1]+k];k++);
	}
}

int n;
char s[MAXN];
int b[MAXN],c[MAXN];
int p[MAXN];
int lst[30];

int main()
{
	while(scanf("%d",&n)==1)
	{
		memset(b,0,(n+5)*sizeof(int));
		memset(c,0,(n+5)*sizeof(int));
		memset(p,0,(n+5)*sizeof(int));
		memset(lst,-1,sizeof(lst));
		R(s);
		for(int i=0;i<n;i++)
		{
			if(lst[s[i]-'a']>=0)b[i]=i-lst[s[i]-'a'];
			else b[i]=0;
			lst[s[i]-'a']=i;
		}
		SA::SA(n,b);
		lst[0]=lst[1]=-1;
		Vi vec;
		for(int i=n-1;~i;i--)
		{
			if(lst[(s[i]-'a')^1]==-1)p[i]=1,c[i]=n-i;
			else p[i]=0,c[i]=lst[(s[i]-'a')^1]-i;
			lst[s[i]-'a']=i;
			vec.pb(i+1);
		}
		SA::rk[n]=-1;
		sort(ALL(vec),[&](int aa,int bb){
			 int a=aa-1,b=bb-1;
			 if(c[a]^c[b])return c[a]<c[b];
			 if(p[a]^p[b])return p[a]>p[b];
			 //W(a,b,a+c[a]+1,b+c[b]+1);
			 return SA::rk[a+c[a]+1]<SA::rk[b+c[b]+1];
		});
		SA::rk[n]=0;
		W(vec);
	}
	return 0;
}