#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define pb(x) push_back(x)
using namespace std;
const int N=400050;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
int n;
vector <int> e[N];
bool vis[N];
ll ans,cost[N];
int extim;
struct node
{
	ll cost;
	int id;
	bool operator < (const node &x)const
	{
		return cost>x.cost;
	}
}a[N];

void dfs(int u)
{
	if(vis[u])return;
	vis[u]=true;
	if(!vis[u]&&e[u].size()==0)
	{
		ans=max(ans,cost[u]+extim);
		extim++;return;
	}
	for(auto v:e[u])
	{
		if(vis[v])continue;
		dfs(v);
	}
	ans=max(ans,cost[u]+extim);
	extim++;
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&a[i].cost);
		cost[i]=a[i].cost;
		a[i].id=i;
		int num;scanf("%d",&num);
		while(num--)
		{
			int x;scanf("%d",&x);
			e[i].pb(x);
		}
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
	{
		int id=a[i].id;
		if(!vis[id])dfs(id);
	}
	printf("%lld\n",ans);
	return 0;
}
