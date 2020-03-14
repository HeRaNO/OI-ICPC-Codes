#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define flush fflush(stdout)
#define pb(x) push_back(x)
using namespace std;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
const int N=200050;
int n;
ll dp1[N],dp2[N];
vector <int> e[N];
vector <ll> sumL[N],sumR[N];
void dfs1(int u,int fa)
{
	dp1[u]=1;
	for(auto v:e[u])
	{
		if(v==fa)
		{
			sumL[u].pb(1);
			sumR[u].pb(1);
			continue;
		}
		dfs1(v,u);
		dp1[u]=dp1[u]*(dp1[v]+1LL)%mod;
		sumL[u].pb(dp1[v]+1);
		sumR[u].pb(dp1[v]+1);
	}
	for(int i=1;i<sumL[u].size();++i)sumL[u][i]*=sumL[u][i-1],sumL[u][i]%=mod;
	for(int i=sumR[u].size()-2;i>=0;--i)sumR[u][i]*=sumR[u][i+1],sumR[u][i]%=mod;
}

void dfs2(int u,int fa,ll val)
{
	dp2[u]=val;int siz=e[u].size();
	for(int i=0;i<siz;++i)
	{
		int v=e[u][i];
		if(v==fa)continue;
		ll tmp=val;
		if(i!=0)tmp*=sumL[u][i-1],tmp%=mod;
		if(i<siz-1)tmp*=sumR[u][i+1],tmp%=mod;
		dfs2(v,u,tmp+1);
	}
}

int main()
{
	cin>>n;
	for(int i=2;i<=n;++i)
	{
		int P;scanf("%d",&P);
		e[i].pb(P),e[P].pb(i);
	}
	dfs1(1,0);
	dfs2(1,0,1);
	for(int i=1;i<=n;++i)
		printf("%lld ",dp1[i]*dp2[i]%mod);
	return 0;
}