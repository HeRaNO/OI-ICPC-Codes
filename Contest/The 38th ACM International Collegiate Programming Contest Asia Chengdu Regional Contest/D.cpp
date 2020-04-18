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

int kase;

int head[105],ecnt;
struct Edge
{
	int v,nxt,t,m;
}e[MAXN];

void add_Edge(int u,int v,int t,int m)
{
	e[++ecnt]={v,head[u],t,m};head[u]=ecnt;
}

int dp[102][6][6][205],vis[102][6][6][205];

void init()
{
	memset(head,0,sizeof(head));
	memset(dp,-1,sizeof(dp));
	memset(vis,0,sizeof(vis));
	ecnt=0;
}

int n,mm,B,K,R,T;
int p[105][6];

struct Node
{
	int u,d,salt,t,m;
	bool operator < (const Node &rhs)const
	{
		return t>rhs.t;
	}
};

priority_queue<Node> pq;

void pu(int v,int d,int s,int t,int m)
{
	if(t>T)return;
	if(m<0)return;
	dp[v][d][s][t]=max(dp[v][d][s][t],m);
	if(!vis[v][d][s][t])
	{
		vis[v][d][s][t]=1;
		pq.push({v,d,s,t,m});
	}
}

void bfs()
{
	pq.push({1,0,0,0,R});
	vis[1][0][0][0]=1;
	dp[1][0][0][0]=R;
	while(!pq.empty())
	{
		Node u=pq.top();pq.pop();
		u.m=dp[u.u][u.d][u.salt][u.t];
		vis[u.u][u.d][u.salt][u.t]=0;
		if(u.u==n)continue;
		if(u.u!=1&&u.u!=n)
		{
			int nxt=(u.d+1)%K;
			if(u.salt)pu(u.u,nxt,u.salt-1,u.t+1,u.m+p[u.u][nxt]);
			if(u.salt<B)pu(u.u,nxt,u.salt+1,u.t+1,u.m-p[u.u][nxt]);
			pu(u.u,nxt,u.salt,u.t+1,u.m);
		}
		for(int i=head[u.u];i;i=e[i].nxt)
		{
			int v=e[i].v,t=e[i].t+u.t;
			if(v==n&&u.d!=0)continue;
			if(u.m<e[i].m)continue;
			if(u.salt&&v!=n&&v!=1)
			{
				pu(v,u.d,u.salt-1,t,u.m-e[i].m+p[v][u.d]);
			}
			if(u.salt<B&&v!=n&&v!=1)
			{
				pu(v,u.d,u.salt+1,t,u.m-e[i].m-p[v][u.d]);
			}
			pu(v,u.d,u.salt,t,u.m-e[i].m);
		}
	}
}

void solve()
{
	printf("Case #%d: ",++kase);
	init();
	scanf("%d%d%d%d%d%d",&n,&mm,&B,&K,&R,&T);
	for(int i=0;i<K;i++)
		for(int j=1;j<=n;j++)scanf("%d",&p[j][i]);
	for(int i=1;i<=mm;i++)
	{
		int u,v,t,m;
		scanf("%d%d%d%d",&u,&v,&t,&m);
		add_Edge(u,v,t,m);
	}
	bfs();
	int ans=-1;
	for(int i=0;i<=B;i++)
		for(int j=0;j<=T;j++)ans=max(ans,dp[n][0][i][j]);
	if(ans==-1)puts("Forever Alone");
	else printf("%d\n",ans);
}

int main()
{
	int T=1;
	_R(T);
	while(T--)solve();
	return 0;
}