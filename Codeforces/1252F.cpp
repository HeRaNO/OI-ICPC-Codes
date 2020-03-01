#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
const int inf=0x3f3f3f3f;
const ll mod1=1e9+7;
const ll mod2=998244353LL;
const int N=4050;
ll H1[N],H2[N];
struct HASH
{
	ll h1,h2,n;
}h[N];
vector <HASH> vec[N];
HASH hashmerge(HASH ha,HASH hb)
{
	HASH ret=HASH{0,0,ha.n+hb.n};
	ret.h1=(ha.h1*H1[hb.n]+hb.h1)%mod1;
	ret.h2=(ha.h2*H2[hb.n]+hb.h2)%mod2;
	return ret;
}
bool vis[N];
vector <int> e[N];
bool cmp(const int &x,const int &y)
{
	return h[x].h1<h[y].h1||(h[x].h1==h[y].h1&&h[x].h2<h[y].h2);
}
int n;
void dfs(int u,int fa)
{
	h[u]=HASH{1,1,1};
	for(auto v:e[u])
	{
		if(v==fa)continue;
		dfs(v,u);
	}
	sort(e[u].begin(),e[u].end(),cmp);
	for(auto v:e[u])
	{
		if(v==fa)continue;
		h[u]=hashmerge(h[u],h[v]);
	}
}
int ans=-1;
void dfs_ans(int u,int fa)
{
	h[u]=HASH{1,1,1};
	vec[u].push_back(h[u]);
	sort(e[u].begin(),e[u].end(),cmp);
	HASH tmp=HASH{0,0,0};
	bool flag=true;
	for(auto v:e[u])
	{
		h[u]=hashmerge(h[u],h[v]);
		vec[u].push_back(h[u]);
		if(!tmp.n)tmp=h[v];
		else if(tmp.h1!=h[v].h1||tmp.h2!=h[v].h2)flag=0;
	}
	int sz=e[u].size();
	if(flag&&sz>=2)ans=max(ans,sz);
	HASH nxt=HASH{0,0,0};
	for(int i=sz-1;i>=0;--i)
	{
		int v=e[u][i];
		h[u]=hashmerge(vec[u][i],nxt);
		nxt=hashmerge(h[v],nxt);
		if(v==fa)continue;
		dfs_ans(v,u);
	}
}

int main()
{
	H1[0]=1,H2[0]=1;
	for(int i=1;i<N;++i)
	{
		H1[i]=H1[i-1]*137LL%mod1;
		H2[i]=H2[i-1]*233LL%mod2;
	}
	cin>>n;
	for(int i=1;i<n;++i)
	{
		int x,y;scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(1,0);
	dfs_ans(1,0);
	printf("%d\n",ans);
	return 0;
}
