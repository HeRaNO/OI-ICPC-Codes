#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 300005
#define fi first
#define se second
using namespace std;

const int INF=0x3f3f3f3f;

int n,m,k,u,v,w,cnte,f[MAXN],_2pow[20],fa[MAXN][20],dep[MAXN];
long long ans=~(1LL<<63),cnt;
bool vis[MAXN];
pair<int,pair<int,int> > e[MAXN];
vector <pair<int,int> > g[MAXN];
pair<int,int> dis[MAXN][20];

inline int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

inline pair<int,int> update(pair<int,int> a,pair<int,int> b)
{
	pair<int,int> res={-INF,-INF};
	res.fi=max(a.fi,b.fi);
	if (a.fi==b.fi) res.se=max(a.se,b.se);
	else if (a.fi<b.fi) res.se=max(a.fi,b.se);
	else res.se=max(b.fi,a.se);
	return res;
}

inline void dfs(int x,int f,int v,int deep)
{
	fa[x][0]=f;dis[x][0]={v,-INF};dep[x]=deep;
	for (auto v:g[x]) if (v.fi!=f) dfs(v.fi,x,v.se,deep+1);
	return ;
}

inline void LCA()
{
	for (int j=1;j<=k;j++)
		for (int i=1;i<=n;i++)
		{
			fa[i][j]=fa[fa[i][j-1]][j-1];
			dis[i][j]=update(dis[i][j-1],dis[fa[i][j-1]][j-1]);
		}
	return ;
}

inline void LCAMUL()
{
	for (_2pow[0]=1;_2pow[k]<=n;k++) _2pow[k+1]=_2pow[k]<<1;
	dfs(1,0,0,1);LCA();
	return ;
}

inline pair<int,int> query(int u,int v)
{
	pair<int,int> res={-INF,-INF-1};
	if (dep[u]>dep[v]) swap(u,v);
	for (int i=k;~i;i--)
		if (_2pow[i]<=dep[v]-dep[u])
		{
			res=update(res,dis[v][i]);
			v=fa[v][i];
		}
	for (int i=k;~i;i--)
		if (fa[u][i] != fa[v][i])
		{
			res=update(res,update(dis[u][i],dis[v][i]));
			u=fa[u][i];v=fa[v][i];
		}
	if (u!=v) res=update(res,update(dis[u][0],dis[v][0]));
	return res;
}

inline void read(int &x)
{
	x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return ;
}

int main()
{
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++) f[i]=i;
	for (int i=1;i<=m;i++) scanf("%d %d %d",&u,&v,&w),e[i]={w,{u,v}};
	sort(e+1,e+m+1);
	for (int i=1;i<=m;i++)
	{
		u=e[i].se.fi;v=e[i].se.se;w=e[i].fi;
		int fx=getf(u),fy=getf(v);
		if (fx!=fy)
		{
			cnt+=w;vis[i]=true;f[fy]=fx;++cnte;
			g[u].push_back({v,w});g[v].push_back({u,w});
			if (cnte==n-1) break;
		}
	}
	LCAMUL();
	for (int i=1;i<=m;i++)
	{
		if (vis[i]) continue;
		if (e[i].se.fi==e[i].se.se) continue;
		pair <int,int> t=query(e[i].se.fi,e[i].se.se);
		if (t.fi==e[i].fi)
		{
			if (t.se!=~(1LL<<63))
				ans=min(ans,cnt-t.se+e[i].fi);
		}
		else ans=min(ans,cnt-t.fi+e[i].fi);
	}
	printf("%lld\n",ans);
	return 0;
}
