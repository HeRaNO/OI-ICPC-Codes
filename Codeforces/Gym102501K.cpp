#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const int MAXN=2e6+10,MAXM=1e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
#define lowbit(x) x&-x
const int inv2=5e8+4;
#define pb push_back
const int N=100050;
const int inf=0x3f3f3f3f;
vector <int> vec,ans;
vector <int> g[N];
int n,m,t;
int dp[N],a[N];
bool vis[N];
int head[MAXN],_next[MAXM],to[MAXM],ecnt;
void add_Edge(int u,int v)
{
	_next[++ecnt]=head[u];
	to[ecnt]=v;
	head[u]=ecnt;
}
int tot,dfn[MAXN],low[MAXN];
int cir[MAXN],cirnum;
stack<int> s;
void tarjan(int u)
{
	dfn[u]=low[u]=++tot;
	s.push(u);
	for(int i=head[u];i;i=_next[i])
	{
		int v=to[i];
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(!cir[v])low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u])
	{
		cir[u]=++cirnum;
		while(s.top()!=u)
		{
			cir[s.top()]=cirnum;
			s.pop();
		}
		s.pop();
	}
}

void dfs(int u,int fa)
{
	vis[u]=1;
	dp[u]=a[u];
	for(auto v:g[u])
	{
		if(v==fa)continue;
		if(!vis[v])
		dfs(v,u);
		dp[u]+=dp[v];

	}
}

int main()
{
	scanf("%d%d%d",&n,&m,&t);
	t++;
	for(int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x++;
		y++;
		if(y!=t)add_Edge(x,y);
		if(y==t)vec.pb(x);
	}
	for(int i=1;i<=n;++i)
	{
		if(i==t)continue;
		if(!dfn[i])tarjan(i);
	}
	for(int i=1;i<=n;++i)
	{
		if(i==t)continue;
		for(int j=head[i];j;j=_next[j])
		{
			int v=to[j];
			if(cir[i]!=cir[v])g[cir[i]].pb(cir[v]);
		}
	}
	for(auto i:vec)a[cir[i]]++;
	for(int i=1;i<=cirnum;++i)
	{
		if(!vis[i])dfs(i,0);
	}
	for(auto i:vec)
	{
		if(dp[cir[i]]==1)ans.push_back(i);
	}
	cout<<ans.size()<<endl;
	for(auto i:ans)printf("%d\n",i-1);
	return 0;
}