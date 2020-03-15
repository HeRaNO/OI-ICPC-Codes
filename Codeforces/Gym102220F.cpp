#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
#define lowbit(x) x&-x
#define pb push_back
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)>>1)
typedef long long ll;
typedef pair<ll,ll> pii;
typedef double db;
const int MAXN=5e5+10,MAXM=2e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
const int inv2=5e8+4;

int n,m;
vector<int> g[MAXN],G[MAXN];
int dp[MAXN][7],vis[MAXN<<3];

int nxtid(int x)
{
	return (x+1)%6;
}

char s[50];
int team[8],group[8];
int num[MAXN][7][4];

void init(int u)
{
	for(int i=0;i<6;i++)dp[u][i]=2-team[i];
}

bool check(int u,int p)
{
	int tmp=dp[u][p];
	if(group[p]==1)
	{
		if(num[u][p][2])dp[u][p]=2;
		else if(num[u][p][0])dp[u][p]=0;
		else if(num[u][p][1])dp[u][p]=1;
	}
	else
	{
		if(num[u][p][1])dp[u][p]=1;
		else if(num[u][p][0])dp[u][p]=0;
		else if(num[u][p][2])dp[u][p]=2;
	}
	return tmp!=dp[u][p];
}

queue<int> q;
int cnt;

void bfs()
{
	for(int i=1;i<=n;i++)
	if(!SZ(g[i]))
	{
		init(i);
		for(auto v:G[i])for(int k=0;k<6;k++)
		{
			num[v][k][0]--;
			num[v][k][dp[i][(k+1)%6]]++;
			int j=(v<<3)|k;
			if(!vis[j])
			{
				vis[j]=1;
				q.push(j);
			}
		}
	}
	while(!q.empty())
	{
		int p=q.front();q.pop();
		int u=p>>3;
		vis[p]=0;
		p=p&7;
		int tmp=dp[u][p];
		if(check(u,p))
		{
			int tp=dp[u][p];
			p=(p+5)%6;
			for(auto v:G[u])
			{
				int j=(v<<3)|p;
				num[v][p][tmp]--;
				num[v][p][tp]++;
				if(!vis[j])
				{
					cnt++;
					vis[j]=1;
					if(cnt>=1e7)q.pop();
					q.push(j);
				}
			}
		}
	}
}

void solve()
{
	cnt=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)g[i].resize(0),G[i].resize(0);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].pb(v);
		G[v].pb(u);
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<6;j++)dp[i][j]=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<6;j++)
		{
			num[i][j][0]=SZ(g[i]);
			num[i][j][1]=num[i][j][2]=0;
		}
	memset(vis,0,(n+5)*8*sizeof(int));
	scanf("%s",s);
	for(int i=0;i<6;i++)team[i]=(s[i]=='B');
	scanf("%s",s);
	for(int i=0;i<6;i++)group[i]=(team[i]^(s[i]=='1'));
	bfs();
	for(int i=1;i<=n;i++)
	{
		if(dp[i][0]==0)printf("D");
		else if(dp[i][0]==1)printf("A");
		else printf("B");
	}
	puts("");
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		solve();
	}
	return 0;
}
