#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
#define lowbit(x) x&-x
#define pb emplace_back
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
void _R(int& x){scanf("%d",&x);}
void _R(ll& x){scanf("%lld",&x);}
void _R(db& x){scanf("%lf",&x);}
void _R(char *x){scanf("%s",x);}
void _W(const int &x){printf("%d ",x);}
void _W(const ll &x){printf("%lld ",x);}
void _W(const db &x){printf("%lf ",x);}
void _W(const char *x){printf("%s",x);}
void _WC(const char &x){putchar(x);}
void _WL(){puts("");}
const int MAXN=2e6+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1004535809,mod=998244353;
const int inv2=5e8+4;
const int Lim=1<<20;

ll a,b,c,d,m,p;

ll calc(ll a1,ll d,ll c)
{
	a1++;c--;
	ll num=(d-m+p)/p-(c-m+p)/p;
	//cout<<num<<" "<<d<<" "<<c<<endl;
	return a1*num+p*num*(num-1)/2;
}

int kase;

void solve()
{
	_R(a);_R(b);_R(c);_R(d);_R(p);_R(m);
	ll mn=min(b-a,d-c)+1;
	ll l=mn+a+c-2,r=b+d-mn+2;
	ll sum=(l-(a+c)+2)*(l-(a+c)+1)/2+((b+d)-r+2)*((b+d)-r+1)/2+(r-l-1)*mn;
	ll ans=0;
	ans=calc((m-(a+c)%p+p)%p,l,(a+c))+calc(((b+d)%p-m+p)%p,(b+d),r)+mn*((r-1-m+p)/p-(l-m+p)/p);
	//cout<<(r-m-1+p)/p<<" "<<(l-m+p)/p<<endl;
	//cout<<sum<<" "<<ans<<endl;
	ll g=__gcd(ans,sum);ans/=g;sum/=g;
	printf("Case #%d: %lld/%lld\n",++kase,ans,sum);
}

int main()
{
	int T=1;
	_R(T);
	while(T--)solve();
	return 0;
}

/*
4
0 5 0 5 3 0
0 999999 0 999999 1000000 0
0 3 0 3 8 7
3 3 4 4 7 0
*/