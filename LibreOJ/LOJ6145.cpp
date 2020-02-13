#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

const int inf=1e9;

struct link
{
	int to,val,nxt;
};

link e[MAXN<<1];
int head[MAXN],cnt;
int n,u,v,w,T,R,SIZE,G,lg[MAXN<<1],pt[MAXN],euler[MAXN<<1];
int siz[MAXN],mx[MAXN],f[MAXN],dis[MAXN],dep[MAXN<<1],fa[18][MAXN<<1];
bool vis[MAXN];
int x[MAXN*85],ls[MAXN*85],rs[MAXN*85],rt[MAXN],tot;

inline void add(int u,int v,int w)
{
	e[cnt]=(link){v,w,head[u]};head[u]=cnt++;
	e[cnt]=(link){u,w,head[v]};head[v]=cnt++;
}

inline void dfs(int x,int f,int deep,int v)
{
	pt[x]=++R;euler[R]=x;dep[R]=deep;dis[x]=v;
	for (int i=head[x];~i;i=e[i].nxt)
		if (e[i].to!=f)
		{
			dfs(e[i].to,x,deep+1,e[i].val+v);
			euler[++R]=x;dep[R]=deep;
		}
	return ;
}

inline void RMQLCA()
{
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

inline int getLCA(int x,int y)
{
	x=pt[x];y=pt[y];
	if (x>y) swap(x,y);
	int t=lg[y-x+1];int a=fa[t][x],b=fa[t][y-(1<<t)+1];
	return dep[a]<=dep[b]?euler[a]:euler[b];
}

inline int getdis(int x,int y)
{
	return dis[x]+dis[y]-2*dis[getLCA(x,y)];
}

inline void DFS_size_and_G(int x,int fa)
{
	siz[x]=1;mx[x]=0;
	for (int i=head[x];~i;i=e[i].nxt)
		if (e[i].to!=fa&&!vis[e[i].to])
		{
			DFS_size_and_G(e[i].to,x);
			siz[x]+=siz[e[i].to];
			mx[x]=max(mx[x],siz[e[i].to]);
		}
	mx[x]=max(mx[x],SIZE-siz[x]);
	if (mx[x]<mx[G]) G=x;
	return ;
}

inline void TreeDC(int x)
{
	vis[x]=true;
	for (int i=head[x];~i;i=e[i].nxt)
		if (!vis[e[i].to])
		{
			mx[0]=SIZE=siz[e[i].to];G=0;
			DFS_size_and_G(e[i].to,x);f[G]=x;
			TreeDC(G);
		}
	vis[x]=false;
	return ;
}

inline void modify(int &u,int p,int v,int l,int r)
{
	if (!u) x[u=++tot]=v;
	else x[u]=min(x[u],v);
	if (l==r) return ;int m=l+r>>1;
	if (p<=m) modify(ls[u],p,v,l,m);
	else modify(rs[u],p,v,m+1,r);
	return ;
}

inline int query(int u,int l,int r,int pl,int pr)
{
	if (!u) return inf;
	if (pl==l&&pr==r) return x[u];
	int m=pl+pr>>1;
	if (r<=m) return query(ls[u],l,r,pl,m);
	else if (l>m) return query(rs[u],l,r,m+1,pr);
	else return min(query(ls[u],l,m,pl,m),query(rs[u],m+1,r,m+1,pr));
}

inline int Q(int l,int r,int x)
{
	if (l<=x&&x<=r) return 0;
	int ans=~(1<<31);
	for (int i=x;i;i=f[i])
		ans=min(ans,query(rt[i],l,r,1,n)+getdis(i,x));
	return ans;
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
	read(n);memset(head,-1,sizeof head);
	for (int i=1;i<n;i++) read(u),read(v),read(w),add(u,v,w);
	dfs(1,-1,0,0);RMQLCA();
	SIZE=mx[0]=n;DFS_size_and_G(1,-1);TreeDC(G);
	for (int i=1;i<=n;i++)
		for (int j=i;j;j=f[j])
			modify(rt[j],i,getdis(i,j),1,n);
	read(T);
	while (T--)
	{
		read(u),read(v),read(w);
		printf("%d\n",Q(u,v,w));
	}
	return 0;
}