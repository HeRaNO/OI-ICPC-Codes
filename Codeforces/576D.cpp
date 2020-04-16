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

int n,m;
struct Node
{
	int u,v,d;
	bool operator < (const Node &rhs)const
	{
		return d<rhs.d;
	}
}e[MAXN];

ll ans=llINF;
ll dis[MAXN];

struct Matrix
{
	bitset<155> a[155];
	Matrix()
	{
		for(int i=1;i<=n;i++)a[i].reset();
	}
	Matrix operator * (const Matrix &rhs)const
	{
		Matrix res;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			if(a[j][i])res.a[j]|=rhs.a[i];
		return res;
	}
}g,t;

void ksm(ll d)
{
	Matrix tmp=g;
	while(d)
	{
		if(d&1)t=t*tmp;
		tmp=tmp*tmp;
		d>>=1;
	}
}

ll f[155][155];

void chk(int d,int i)
{
	memset(f,0x3f,sizeof(f));
	for(int j=1;j<=i;j++)f[e[j].u][e[j].v]=1;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for(int i=1;i<=n;i++)if(t.a[1][i])ans=min(ans,d+f[i][n]);
}

int main()
{
	_R(n);_R(m);
	for(int i=1;i<=m;i++)
	{
		_R(e[i].u);_R(e[i].v);_R(e[i].d);
	}
	sort(e+1,e+m+1);
	int now=1;
	for(int i=1;i<=n;i++)t.a[i][i]=1;
	while(e[now].d==0)
	{
		g.a[e[now].u][e[now].v]=1;
		now++;
	}
	chk(0,now-1);
	for(int i=now;i<=m;i++)
	{
		ksm(e[i].d-e[i-1].d);
		g.a[e[i].u][e[i].v]=1;
		chk(e[i].d,i);
	}
	if(ans>=1e10)puts("Impossible");
	else _W(ans);
	return 0;
}
