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
const int MAXN=7e6+10,MAXM=2e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int inv2=(MOD+1)/2;
const int Lim=1<<20;


template<size_t size>
struct SuffixArray {
	bool t[size << 1];
	int sa[size], ht[size], rk[size];
	inline bool islms(const int i, const bool *t) {
		return i > 0 && t[i] && !t[i - 1];
	}
	template<class T>
	inline void sort(T s, int *sa, const int len, const int sigma, const int sz, bool *t, int *b, int *cb, int *p) {
		memset(b, 0, sizeof(int) * sigma);
		memset(sa, -1, sizeof(int) * len);
		for (register int i = 0; i < len; i++) b[s[i]]++;
		cb[0] = b[0];
		for (register int i = 1; i < sigma; i++) cb[i] = cb[i - 1] + b[i];
		for (register int i = sz - 1; i >= 0; i--) sa[--cb[s[p[i]]]] = p[i];
		for (register int i = 1; i < sigma; i++) cb[i] = cb[i - 1] + b[i - 1];
		for (register int i = 0; i < len; i++) if (sa[i] > 0 && !t[sa[i] - 1]) sa[cb[s[sa[i] - 1]]++] = sa[i] - 1;
		cb[0] = b[0];
		for (register int i = 1; i < sigma; i++) cb[i] = cb[i - 1] + b[i];
		for (register int i = len - 1; i >= 0; i--) if (sa[i] > 0 && t[sa[i] - 1]) sa[--cb[s[sa[i] - 1]]] = sa[i] - 1;
	}
	template<class T>
	inline void sais(T s, int *sa, const int len, bool *t, int *b, int *b1, const int sigma) {
		register int i, j, x, p = -1, cnt = 0, sz = 0, *cb = b + sigma;
		for (t[len - 1] = 1, i = len - 2; i >= 0; i--) t[i] = s[i] < s[i + 1] || (s[i] == s[i + 1] && t[i + 1]);
		for (i = 1; i < len; i++) if (t[i] && !t[i - 1]) b1[sz++] = i;
		sort(s, sa, len, sigma, sz, t, b, cb, b1);
		for (i = sz = 0; i < len; i++) if (islms(sa[i], t)) sa[sz++] = sa[i];
		for (i = sz; i < len; i++) sa[i] = -1;
		for (i = 0; i < sz; i++) {
			for (x = sa[i], j = 0; j < len; j++) {
				if (p == -1 || s[x + j] != s[p + j] || t[x + j] != t[p + j]) { cnt++, p = x; break; }
				else if (j > 0 && (islms(x + j, t) || islms(p + j, t))) break;
			}
			sa[sz + (x >>= 1)] = cnt - 1;
		}
		for (i = j = len - 1; i >= sz; i--) if (sa[i] >= 0) sa[j--] = sa[i];
		register int *s1 = sa + len - sz, *b2 = b1 + sz;
		if (cnt < sz) sais(s1, sa, sz, t + len, b, b1 + sz, cnt);
		else for (i = 0; i < sz; i++) sa[s1[i]] = i;
		for (i = 0; i < sz; i++) b2[i] = b1[sa[i]];
		sort(s, sa, len, sigma, sz, t, b, cb, b2);
	}
	template<class T>
	inline void getHeight(T s, int n) {
		for (register int i = 1; i <= n; i++) rk[sa[i]] = i;
		register int j = 0, k = 0;
		for (register int i = 0; i < n; ht[rk[i++]] = k)
			for (k ? k-- : 0, j = sa[rk[i] - 1]; s[i + k] == s[j + k]; k++);
	}
	template<class T>
	inline void init(T s, int len,int sigma) {
		memset(sa,0,(len+5)*sizeof(int));
		memset(rk,0,(len+5)*sizeof(int));
		memset(t,0,(len+5)*2);
		sais(s, sa, len+1, t, rk, ht, sigma), rk[0] = 0;
	}
	int lg[size],st[size][20],n;
	void getlcp(int sz)
	{
		n=sz;
		for(int i=1;i<=n;i++)lg[i]=lg[i-1]+(1<<lg[i-1]+1==i);
		for(int i=1;i<=n;i++)st[i][0]=ht[i];
		for(int j=1;1<<j<=n;j++)
			for(int i=1;i+(1<<j)-1<=n;i++)
			st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	}
	int lcp(int i,int j)
	{
		if(i==j)return n-i+1;
		i=rk[i];j=rk[j];
		if(i>j)swap(i,j);
		i++;int k=lg[j-i+1];
		//W(i,j,k,j-(1<<k)+1,min(st[i][k],st[j-(1<<k)+1][k]));
		return min(st[i][k],st[j-(1<<k)+1][k]);
	}
};
SuffixArray<MAXN>SA;
char s[MAXN];
char t[MAXN];
char ns[MAXN];
int n;

int chk(int n)
{
	int ans=0,i=0;
	for(int i=0;i<n;++i)ns[i+n]=ns[i];
	n*=2;
	while(i<n/2)
	{
		ans=i;
		int j=i+1,k=i;
		while(j<n&&ns[k]<=ns[j])
		{
			if(ns[k]<ns[j])k=i;
			else k++;
			j++;
		}
		while(i<=k)i+=j-k;
	}
	return ans;
}

void solve()
{
	scanf("%d%s",&n, s);
	if(n==1)return W("No");
	Vi fact;
	for(int i=2;i*i<n;i++)if(n%i==0)fact.pb(i),fact.pb(n/i);
	fact.pb(1);
	int p=sqrt(n);
	if(p*p==n)fact.pb(p);
	for(auto d:fact)
	{
		bool used=0,f=0;
		for(int i=0;i<n;i+=d)
		{
			for(int j=0;j<d;j++)ns[j]=s[i+j];ns[d]='\0';
			int pos=chk(d);
			if(!used)
			{
				int cnt=0;used=1;
				for(int j=pos;j<d;j++)t[cnt++]=ns[j];
				for(int j=0;j<pos;j++)t[cnt++]=ns[j];
			}
			else
			{
				int cnt=0;
				for(int j=pos;j<d;j++)
				{
					if(t[cnt]!=ns[j]){f=1;break;}
					cnt++;
				}
				for(int j=0;j<pos;j++)
				{
					if(t[cnt]!=ns[j]){f=1;break;}
					cnt++;
				}
			}
			if(f)break;
		}
		if(!f)return W("Yes");
	}
	W("No");
}

int main()
{
	int T=1;
	R(T);
	while(T--)solve();
	return 0;
}