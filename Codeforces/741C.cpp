#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=2e6+10,MAXM=4e4+10;
const int INF=INT_MAX,MOD=1e9+7,mod=998244353;
const ll llINF=~(1ll<<63);

int head[MAXN],to[MAXN],_next[MAXN],ecnt;
vector<pii> ans;

void add_Edge(int u,int v)
{
	_next[++ecnt]=head[u];
	to[ecnt]=v;
	head[u]=ecnt;
}

int col[MAXN];

void dfs(int u,int c)
{
	col[u]=c;
	for(int i=head[u];i;i=_next[i])
	{
		int v=to[i];
		if(!col[v])dfs(v,3-c);
	}
}

int main()
{
	int n,m;
	scanf("%d",&n);
	m=2*n;
	for(int i=1;i<=n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		ans.push_back({u,v});
		add_Edge(u,v);
		add_Edge(v,u);
		add_Edge(i*2,i*2-1);
		add_Edge(i*2-1,i*2);
	}
	for(int i=1;i<=m;i++)
		if(!col[i])dfs(i,1);
	for(int i=1;i<=m;i++)
		for(int j=head[i];j;j=_next[j])
			if(col[i]==col[to[j]])return puts("-1"),0;
	for(int i=1;i<=n;i++)
		printf("%d %d\n",col[ans[i-1].first],col[ans[i-1].second]);
	return 0;
}