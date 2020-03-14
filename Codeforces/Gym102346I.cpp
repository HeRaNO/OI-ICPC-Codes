#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
#define lowbit(x) x&-x
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const int MAXN=6e5+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
const int Lim=(1<<19);

int n,m;
int T[MAXN];
int w[405][405],dis[2][405][405][405];
vector<int> vec;
map<int,int> H;
vector<int> P[405];

void add_node(int type,int u,int k)
{
	//for(int i=1;i<=n;i++)if(w[u][i])dis[type][k][u][i]=dis[type][k][i][u]=min(dis[type][k][u][i],w[u][i]);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	dis[type][k][i][j]=dis[type][k][j][i]=min(dis[type][k][i][j],dis[type][k][i][u]+dis[type][k][u][j]);
}

void add_temp(int type,int k)
{
	int c=(type==0)?k:SZ(vec)-k+1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		dis[type][k][i][j]=dis[type][k-1][i][j];
	if (c<1||c>SZ(vec)) return ;
	for(auto j:P[c])add_node(type,j,k);
}

int main()
{
	memset(dis,0x3f,sizeof(dis));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&T[i]),vec.pb(T[i]);
	sort(ALL(vec));
	vec.resize(unique(ALL(vec))-vec.begin());
	for(int i=0;i<SZ(vec);i++)H[vec[i]]=i+1;
	for(int i=1;i<=n;i++)P[H[T[i]]].pb(i);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&v,&u);
		scanf("%d",&w[u][v]);
		w[v][u]=w[u][v];
		dis[0][0][u][v]=dis[1][0][u][v]=dis[0][0][v][u]=dis[1][0][v][u]=w[u][v];
	}
	for(int i=1;i<=n;i++)
	{
		add_temp(0,i);
		add_temp(1,i);
	}
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		int a,b,type,k;
		scanf("%d%d%d%d",&a,&b,&k,&type);
		if(dis[type][k][a][b]==SINF) puts("-1");
		else printf("%d\n",dis[type][k][a][b]);
	}
	return 0;
}
