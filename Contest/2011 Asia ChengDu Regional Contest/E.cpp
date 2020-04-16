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
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
const int MAXN=4e4+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1004535809,mod=998244353;
const int inv2=5e8+4;
const int Lim=1<<20;

int n,m;
int head[MAXN],to[MAXM],_next[MAXM],ecnt;

void add_edge(int u,int v)
{
	_next[++ecnt]=head[u];
	to[ecnt]=v;
	head[u]=ecnt;
}

int low[MAXN],dfn[MAXN],tot;
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
	if(low[u]==dfn[u])
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

int b[MAXN];

void solve()
{
	tot=ecnt=cirnum=0;
	memset(head,0,sizeof(head));
	memset(low,0,sizeof(low));
	memset(dfn,0,sizeof(dfn));
	memset(cir,0,sizeof(cir));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]),b[i]--;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		if(!w)
		{
			if(b[u]==b[v])
			{
				add_edge(u,v);add_edge(v,u);
				add_edge(u+n,v+n);add_edge(v+n,u+n);
			}
			else
			{
				if(b[u]==(b[v]+1)%3)
				{
					add_edge(u+n,v);add_edge(v,u+n);
					add_edge(v+n,v);add_edge(u,u+n);
				}
				else
				{
					add_edge(v+n,u);add_edge(u,v+n);
					add_edge(v,v+n);add_edge(u+n,u);
				}
			}
		}
		else
		{
			if(b[u]==b[v])
			{
				add_edge(u,v+n);add_edge(v+n,u);
				add_edge(v,u+n);add_edge(u+n,v);
			}
			else
			{
				if(b[u]==(b[v]+1)%3)
				{
					add_edge(u+n,v+n);add_edge(v,u);
				}
				else
				{
					add_edge(v+n,u+n);add_edge(u,v);
				}
			}
		}
	}
	for(int i=1;i<=n*2;i++)if(!dfn[i])tarjan(i);
	//for(int i=1;i<=n;i++)cout<<(cir[i]>cir[i+n])<<" ";
	for(int i=1;i<=n;i++)
		if(cir[i]==cir[i+n])
		return puts("no"),void();
	puts("yes");
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}