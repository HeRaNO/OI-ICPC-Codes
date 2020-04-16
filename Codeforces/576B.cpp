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

int n,p[MAXN],cnt=0;
vector<int> cyc[MAXN];
bool vis[MAXN];

int main()
{
	_R(n);
	for(int i=1;i<=n;i++)_R(p[i]);
	for(int i=1;i<=n;i++)if(!vis[i])
	{
		cnt++;
		for(int j=i;!vis[j];j=p[j])
		{
			vis[j]=1;
			cyc[cnt].pb(j);
		}
	}
	for(int i=1;i<=cnt;i++)if(SZ(cyc[i])==1)
	{
		puts("YES");
		for(int j=1;j<=n;j++)if(j!=cyc[i][0]){_W(j);_W(cyc[i][0]);_WL();}
		return 0;
	}
	bool f=0;
	for(int i=1;i<=cnt;i++)f|=(SZ(cyc[i])&1);
	if(f)return puts("NO"),0;
	int id=0;
	for(int i=1;i<=cnt;i++)if(SZ(cyc[i])==2)id=i;
	if(!id)return puts("NO"),0;
	puts("YES");
	for(int i=1;i<=cnt;i++)if(i!=id)
	{
		for(int j=0;j<SZ(cyc[i]);j+=2)
		{
			_W(cyc[id][0]);_W(cyc[i][j]);_WL();
			_W(cyc[id][1]);_W(cyc[i][j+1]);_WL();
		}
	}
	_W(cyc[id][0]);_W(cyc[id][1]);
	return 0;
}