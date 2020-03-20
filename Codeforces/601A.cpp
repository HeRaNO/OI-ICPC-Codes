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
typedef long long ll;
typedef pair<ll,ll> pii;
typedef double db;
const int MAXN=3e6+10,MAXM=2e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
const int inv2=5e8+4;

struct Dijkstra_with_pile
{
	int head[MAXN],to[MAXM],_next[MAXM],ecnt=0;
	ll val[MAXM];
	void init(int n=MAXN)
	{
		memset(head,0,n*sizeof(ll));
		ecnt=0;
	}
	void add_Edge(int u,int v,ll w)
	{
		_next[++ecnt]=head[u];
		to[ecnt]=v;
		val[ecnt]=w;
		head[u]=ecnt;
	}
	ll dis[MAXN];
	priority_queue<pii,vector<pii>,greater<pii> >pq;
	void dijkstra(int s)
	{
		memset(dis,0x3f,sizeof(dis));
		dis[s]=0;
		while(!pq.empty())pq.pop();
		pq.push({0,s});
		while(!pq.empty())
		{
			int u=pq.top().second;
			pq.pop();
			for(int i=head[u];i;i=_next[i])
			{
				int v=to[i];
				if(dis[v]>dis[u]+val[i])
				{
					dis[v]=dis[u]+val[i];
					pq.push({dis[v],v});
				}
			}
		}
	}
}G;

int g[405][405],n,m;

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u][v]=g[v][u]=1;
	}
	if(g[1][n])
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		g[i][j]^=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		if(g[i][j])G.add_Edge(i,j,1);
	G.dijkstra(1);
	if(G.dis[n]>INF)return puts("-1"),0;
	cout<<G.dis[n];
	return 0;
}