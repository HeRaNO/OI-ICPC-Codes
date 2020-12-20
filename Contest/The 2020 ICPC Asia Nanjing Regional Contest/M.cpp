#include <bits/stdc++.h>
using namespace std;
const int MAXN=2005;
typedef long long ll;

int f[MAXN],n,hp[MAXN];
ll dp[MAXN][MAXN][2]; // i: ith vertices, j: cast j times k: del
ll sum[MAXN];
int sz[MAXN];
vector<int> g[MAXN];
ll tmp[MAXN][2],tmp1[MAXN][2];

void dfs(int u)
{
	sz[u]=1;
	vector<pair<int,int>> vec;
	for(auto v:g[u])
	{
		dfs(v);
		vec.push_back({sz[v],v});
	}
	sort(vec.begin(),vec.end(),greater<pair<int,int>>());
	for(auto pp:vec)
	{
		int v=pp.second;
		memset(tmp,0,sizeof(tmp));
		for(int j=0;j<=sz[v];j++)
		{
			for(int k=0;k<=1;k++)
			{
				if(!k)
				{
					tmp[j][0]=max(tmp[j][0],dp[v][j][k]);
					tmp[j][1]=max(tmp[j][1],dp[v][j][k]);
				}
				else
				{
					tmp[j+1][0]=max(tmp[j+1][0],dp[v][j][k]+sum[v]+((v>1)?hp[v]:0ll));
					tmp[j+1][1]=max(tmp[j+1][1],dp[v][j][k]+sum[v]);
				}
			}
		}
		memset(tmp1,0,sizeof(tmp1));
		for(int j=0;j<=sz[v];j++)
			for(int p=0;p<=sz[u];++p)
			for(int k=0;k<=1;k++)
			{
				tmp1[j+p][k]=max(tmp1[j+p][k],tmp[j][k]+dp[u][p][k]);
				//cout<<i<<" "<<p<<" "<<j<<" "<<tmp[j][k]<<" "<<dp[f[u]][p][k]<<endl;
			}
		sz[u]+=sz[v];
		for(int j=0;j<=sz[u];j++)
			for(int k=0;k<=1;k++)
			dp[u][j][k]=tmp1[j][k];

	}
}


inline void Solve()
{
	ll ans=0;
	scanf("%d",&n);
	for(int i=0;i<=n;i++)g[i].resize(0);
	g[0].push_back(1);
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&f[i]);
		g[f[i]].push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&hp[i]);
		if(i!=1)ans+=hp[i];
		ans+=hp[i];
		sum[i]=hp[i];
	}
	for(int i=2;i<=n;i++)sum[f[i]]+=sum[i];
	for(int i=0;i<=n;i++)
		memset(dp[i],0,sizeof(dp[i]));
	dfs(0);
	for(int i=0;i<n;i++)
	{
		printf("%lld ",ans-max(dp[0][i][0],dp[0][i][1]));
	}
	printf("%lld\n",ans-max(dp[0][n][0],dp[0][n][1]));
	return ;
}

int main()
{
	int T;
	scanf("%d",&T);
	while (T--) Solve();
	return 0;
}
