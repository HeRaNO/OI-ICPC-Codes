#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 200005
using namespace std;

pair <int,int> x[1<<19],now;
int n,T,R,ans,o,lg[MAXN<<1],pt[MAXN],p[MAXN],pos[MAXN],dep[MAXN<<1];
int fa[19][MAXN<<1],euler[MAXN<<1];
vector <int> g[MAXN];

inline void dfs(int x,int deep)
{
	pt[x]=++R;euler[R]=x;dep[R]=deep;
	for (auto v:g[x])
	{
		dfs(v,deep+1);
		euler[++R]=x;dep[R]=deep;
	}
	return ;
}

inline void RMQLCA()
{
	dfs(1,0);
	for (int i=1;i<=R;i++) fa[0][i]=i;
	for (int i=2;i<=R;i++) lg[i]=lg[i>>1]+1;
	for (int j=1;j<=lg[R];j++)
		for (int i=1;i+(1<<j)-1<=R;i++)
		{
			int a=fa[j-1][i],b=fa[j-1][i+(1<<(j-1))];
			fa[j][i]=dep[a]<=dep[b]?a:b;
		}
	return ;
}

inline int LCA(int x,int y)
{
	x=pt[x];y=pt[y];
	if (x>y) swap(x,y);
	int t=lg[y-x+1];int a=fa[t][x],b=fa[t][y-(1<<t)+1];
	return dep[a]<=dep[b]?euler[a]:euler[b];
}

inline bool On(int u,int v,int x)
{
	return ((LCA(x,u)==x)^(LCA(x,v)==x))||(LCA(u,v)==x);
}

inline bool On(int x,int y,int u,int v)
{
	if (!~x||!~y||!~u||!~v) return false;
	return On(x,y,u)&&On(x,y,v);
}

inline pair<int,int> PushUp(pair<int,int> l,pair<int,int> r)
{
	pair <int,int> ans={-1,-1};
	int ll=l.first,lr=l.second,rl=r.first,rr=r.second;
	if (On(ll,lr,rl,rr)) ans={ll,lr};
	else if (On(ll,rl,lr,rr)) ans={ll,rl};
	else if (On(ll,rr,lr,rl)) ans={ll,rr};
	else if (On(lr,rl,ll,rr)) ans={lr,rl};
	else if (On(lr,rr,ll,rl)) ans={lr,rr};
	else if (On(rl,rr,ll,lr)) ans={rl,rr};
	return ans;
}

void BuildTree(int u,int l,int r)
{
	if (l+1==r){x[u]={pos[l],pos[l]};return ;}
	int m=l+r>>1;BuildTree(u<<1,l,m);BuildTree(u<<1|1,m,r);
	x[u]=PushUp(x[u<<1],x[u<<1|1]);
	return ;
}

inline void modify(int u,int p,int v,int pl,int pr)
{
	if (pl+1==pr){x[u]={v,v};return ;}
	int m=pl+pr>>1;p<m?modify(u<<1,p,v,pl,m):modify(u<<1|1,p,v,m,pr);
	x[u]=PushUp(x[u<<1],x[u<<1|1]);
	return ;
}

inline void query(int u,int l,int r)
{
	if (l+1==r)
	{
		pair <int,int> t=PushUp(now,x[u]);
		if (!~now.first||(~t.first))
		{
			ans=max(ans,l+1);
			if (~now.first) now=t;
			else now=x[u];
		}
		return ;
	}
	int m=l+r>>1;pair <int,int> t=PushUp(now,x[u<<1]);
	if (~x[u<<1].first&&(!~now.first||(~t.first)))
	{
		if (~now.first) now=t;
		else now=x[u<<1];
		ans=max(ans,m);query(u<<1|1,m,r);
	}
	else query(u<<1,l,m);
	return ;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&p[i]),pos[p[i]]=i;
	for (int i=2,x;i<=n;i++) scanf("%d",&x),g[x].push_back(i);
	RMQLCA();BuildTree(1,0,n);
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&o);
		if (o==1)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			modify(1,p[y],pos[p[x]],0,n);
			modify(1,p[x],pos[p[y]],0,n);
			swap(pos[p[x]],pos[p[y]]);swap(p[x],p[y]);
		}
		else
		{
			ans=0;now={-1,-1};query(1,0,n);
			printf("%d\n",ans);
		}
	}
	return 0;
}