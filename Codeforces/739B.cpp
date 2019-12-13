#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(a,b) memset(a,b,sizeof(a))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
const int N=200050;
int n;
ll a[N];
ll p[N];
ll dep[N];
int ans[N];
struct edge
{
	int v,nxt;
	ll w;
}e[N];
vector < pair<ll,int> > vec;
int head[N],ecnt;
inline void ad(int u,int v,ll w)
{
	e[++ecnt].v=v;e[ecnt].w=w;
	e[ecnt].nxt=head[u];head[u]=ecnt;
}
void dfs(int u)
{
	ans[u]++;
	int p=lower_bound(vec.begin(),vec.end(),mp(dep[u]-a[u],-1))-vec.begin();
	if(p)ans[vec[p-1].second]--;
	vec.push_back(mp(dep[u],u));
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		dep[v]=dep[u]+e[i].w;
		dfs(v);
		ans[u]+=ans[v];
	}
	vec.pop_back();
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
	for(int i=2;i<=n;++i)
	{
		int P;ll W;
		scanf("%d%lld",&P,&W);
		p[i]=P;
		ad(P,i,W);
	}
	dfs(1);
	for(int i=1;i<=n;++i) printf("%d ",ans[i]-1);
	return 0;
}