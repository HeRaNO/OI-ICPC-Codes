#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const int MAXN=2e5+10,MAXM=2e7+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
#define lowbit(x) x&-x
const int inv2=5e8+4;

int u[MAXN],v[MAXN],fa[MAXN],n,m;

int _find(int x)
{
	return fa[x]^x?fa[x]=_find(fa[x]):fa[x];
}

vector<int> vec;
vector<pii> g[MAXN];
map<int,int>mp;

struct ANS
{
	int w,a,b;
};

vector<ANS> ans;
set<int>s;

bool vis[MAXN];

pii dfs(int u)
{
	vis[u]=1;
	for(auto j:g[u])
	{
		if(!vis[j.fi])
		return dfs(j.fi);
	}
	return {u,g[u][0].se};
}

void solve()
{
	scanf("%d",&m);
	vec.resize(0);
	vec.push_back(-1);
	mp.clear();
	s.clear();
	ans.resize(0);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u[i],&v[i]);
		vec.push_back(u[i]);
		vec.push_back(v[i]);
	}
	sort(ALL(vec));
	vec.resize(unique(ALL(vec))-vec.begin());
	for(int i=0;i<SZ(vec);i++)mp[vec[i]]=i;
	n=SZ(vec)-1;
	memset(vis,0,(n+5)*sizeof(bool));
	for(int i=1;i<=n;i++)fa[i]=i,g[i].resize(0);
	for(int i=1;i<=m;i++)
	{
		int uu=mp[u[i]],vv=mp[v[i]];
		g[uu].push_back({vv,i});
		g[vv].push_back({uu,i});
		fa[_find(uu)]=_find(vv);
	}
	for(int i=1;i<=n;i++)s.insert(_find(i));
	int cnt=SZ(s)-1;
	for(int i=1;i<=n;i++)if(cnt&&_find(i)!=_find(1))
	{
		pii tmp=dfs(i);
		int u,v;
		tie(v,u)=tmp;
		ans.push_back({u,vec[v],vec[1]});
		fa[_find(v)]=_find(1);
		cnt--;
	}
	printf("%d\n",SZ(ans));
	for(auto j:ans)printf("%d %d %d\n",j.w,j.a,j.b);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}

/*
2
1
4 7
4
1 2
2 3
4 5
5 6
*/
