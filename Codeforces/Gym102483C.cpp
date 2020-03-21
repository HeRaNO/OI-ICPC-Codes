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
const double Pi=acos(-1);

int n;
vector<int> g[MAXN];
double dis[MAXN][2];
int sz[MAXN];
double R[2];

void dfs(int u,int f,int sum)
{
	sz[u]=1;
	for(auto j:g[u])
	{
		if(j==f)continue;
		dis[j][0]=cos(Pi*sum/(n-1))+dis[u][0];
		dis[j][1]=sin(Pi*sum/(n-1))+dis[u][1];
		dfs(j,u,sum);
		sz[u]+=sz[j];
		sum+=sz[j];
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1,0,0);
	for(int i=1;i<=n;i++)printf("%.7lf %.7lf\n",dis[i][0],dis[i][1]);
	return 0;
}
