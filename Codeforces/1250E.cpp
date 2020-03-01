#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const int MAXN=500+10,MAXM=2e5+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
#define lowbit(x) x&-x
const int inv2=5e8+4;

int n,m,k;
int head[MAXN],to[MAXM],_next[MAXM],ecnt,val[MAXM];

void add_edge(int u,int v,int w)
{
	_next[++ecnt]=head[u];
	to[ecnt]=v;
	val[ecnt]=w;
	head[u]=ecnt;
}

vector<int> ans;
int cor[MAXN],vis[MAXN];

char st[55][55];

bool check(int u,int v)
{
	int cnt=0;
	for(int i=1;i<=m;i++)cnt+=(st[u][i]==st[v][i]);
	return cnt>=k;
}

bool F;

void init()
{
	ecnt=0;F=1;
	memset(head,0,sizeof(head));
	memset(cor,-1,sizeof(cor));
	memset(vis,0,sizeof(vis));
	ans.clear();
}

vector<int> gtmddfs;

void dfs(int u)
{
	vis[u]=1;
	gtmddfs.push_back(u);
	for(int i=head[u];i;i=_next[i])
	{
		int v=to[i];
		if(val[i])
		{
			if(~cor[v]&&cor[v]!=cor[u])F=0;
			cor[v]=cor[u];
		}
		else
		{
			if(~cor[v]&&cor[v]!=(cor[u]^1))F=0;
			cor[v]=cor[u]^1;
		}
		if(!F)break;
		if(!vis[v])dfs(v);
	}
}

void solve()
{
	init();
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)scanf("%s",st[i]+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			bool f1=0,f2=0;
			if(check(i,j))f1=1;
			reverse(st[j]+1,st[j]+m+1);
			if(check(i,j))f2=1;
			reverse(st[j]+1,st[j]+m+1);
			if(!f1&&!f2)
			{
				puts("-1");
				return;
			}
			if(f1&&f2)continue;
			if(f1)
			{
				add_edge(i,j,1);
				add_edge(j,i,1);
			}
			if(f2)
			{
				add_edge(i,j,0);
				add_edge(j,i,0);
			}
		}
	}
	for(int i=1;i<=n;i++)if(!vis[i])
	{
		int cnt[2]={0,0},now=1;
		cor[i]=1;
		gtmddfs.clear();
		dfs(i);
		if(!F)break;
		for(auto &j:gtmddfs)cnt[cor[j]]++;
		if(cnt[1]>=cnt[0])now=0;
		for(auto &j:gtmddfs)if(cor[j]==now)ans.push_back(j);
	}
	if(!F)
	{
		puts("-1");
		return;
	}
	printf("%d\n",SZ(ans));
	for(auto j:ans)printf("%d ",j);
	puts("");
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
