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
const int MAXN=1e6+10,MAXM=2e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
const int inv2=5e8+4;
const double Pi=acos(-1);

vector<int> g[MAXN];
int n,m;
int vis[MAXN];
bool ok;
vector<int>v[MAXN];

void dfs(int u,int p)
{
	v[p].pb(u);
	for(auto j:g[u])
	{
		if(vis[j])
		{
			if(vis[j]+vis[u]!=3)ok=1;
		}
		else
		{
			vis[j]=3-vis[u];
			dfs(j,p);
		}
	}
}

int l[3][MAXN];
int L[2][MAXN],R[2][MAXN];

struct segtree
{
	int l,r;
	ll v;
}t[MAXN<<2];
inline void pushup(int id)
{
	t[id].v=min(t[ls].v,t[rs].v);
}
void build(int l,int r,int id)
{
	t[id].l=l,t[id].r=r;
	if(l==r)
	{
		t[id].v=max(R[0][l],R[1][l]);
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,ls);
	build(mid+1,r,rs);
	pushup(id);
}
void change(int l,int r,int id,int L,int R,int v)
{
	if(l>=L&&R>=r)
	{
		t[id].v=v;
		return;
	}
	int mid=(l+r)>>1;
	if(R<=mid)change(l,mid,ls,L,R,v);
	else if(L>mid)change(mid+1,r,rs,L,R,v);
	else
	{
		change(l,mid,ls,L,mid,v);
		change(mid+1,r,rs,mid+1,R,v);
	}
	pushup(id);
}
int query(int l,int r,int id,int L,int R)
{
	if(l>=L&&R>=r)return t[id].v;
	int mid=(l+r)>>1;
	if(R<=mid)return query(l,mid,ls,L,R);
	else if(L>mid)return query(mid+1,r,rs,L,R);
	else return min(query(l,mid,ls,L,mid),query(mid+1,r,rs,mid+1,R));
}

struct Node
{
	int l,r,id;
}e[MAXN];

bool treevis[MAXN];

void solve()
{
	scanf("%d%d",&n,&m);
	ok=0;
	memset(vis,0,(n+5)*sizeof(int));
	memset(treevis,0,(n+5)*sizeof(bool));
	for(int i=1;i<=n;i++)g[i].resize(0),v[i].resize(0);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].pb(v);
		g[v].pb(u);
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(!vis[i])vis[i]=1,dfs(i,++cnt);
	for(int i=1;i<=n;i++)scanf("%d%d",&l[1][i],&l[2][i]);
	if(ok)return puts("IMPOSSIBLE"),void();
	for(int i=1;i<=cnt;i++)
	{
		L[0][i]=L[1][i]=-INF,R[0][i]=R[1][i]=INF;
		for(auto j:v[i])
		{
			R[0][i]=min(R[0][i],l[vis[j]][j]);
			L[0][i]=max(L[0][i],l[vis[j]][j]);
			R[1][i]=min(R[1][i],l[3-vis[j]][j]);
			L[1][i]=max(L[1][i],l[3-vis[j]][j]);
		}
		if(L[0][i]<L[1][i])
		{
			swap(L[0][i],L[1][i]);
			swap(R[0][i],R[1][i]);
		}
		e[i*2-1]={L[0][i],R[0][i],i};
		e[i*2]={L[1][i],R[1][i],i};
	}
	build(1,cnt,1);
	int ans=INF;
	sort(e+1,e+cnt*2+1,[&](Node a,Node b){return a.l>b.l;});
	for(int i=1;i<=cnt*2;i++)
	{
		ans=min(ans,e[i].l-query(1,cnt,1,1,cnt));
		change(1,cnt,1,e[i].id,e[i].id,R[1][e[i].id]);
		if(treevis[e[i].id])break;
		treevis[e[i].id]=1;
	}
	printf("%d\n",ans);
}

int main()
{
	int t,kase=0;
	scanf("%d",&t);
	while(t--)
	{
		printf("Case %d: ",++kase);
		solve();
	}
	return 0;
}
