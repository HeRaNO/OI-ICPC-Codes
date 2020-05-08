#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int n,u,v,l,r,a[MAXN];
int G,SIZE,siz[MAXN],mx[MAXN];bool vis[MAXN];
int son[MAXN*30][2],cnt[MAXN*30],top,rt;
long long ans;
vector <int> g[MAXN];

inline void add(int u,int v)
{
	g[u].push_back(v);g[v].push_back(u);
	return ;
}

inline int newnode()
{
	son[top][0]=son[top][1]=-1;cnt[top++]=0;
	return top-1;
}

inline void newrt(){top=0;rt=newnode();return ;}

inline void insert(int x)
{
	int now=rt;
	for (int i=29;~i;i--)
	{
		int nxt=(x>>i)&1;
		if (!~son[now][nxt]) son[now][nxt]=newnode();
		now=son[now][nxt];
		++cnt[now];
	}
	return ;
}

inline int query(int x,int L)
{
	if (L<0) return 0;
	int res=0,now=rt;
	for (int i=29;~i&&~now;i--)
	{
		int nxt=(x>>i)&1;
		if (L&(1<<i))
		{
			if (~son[now][nxt]) res+=cnt[son[now][nxt]];
			nxt^=1;
		}
		now=son[now][nxt];
	}
	if (now!=-1) res+=cnt[now];
	return res;
}

inline void Calculate(int x,int fa,int pre)
{
	pre^=a[x];ans+=query(pre,r)-query(pre,l-1);
	for (auto v:g[x])
		if (!vis[v]&&v!=fa) Calculate(v,x,pre);
	return ;
}

inline void DFS(int x,int fa,int pre)
{
	pre^=a[x];insert(pre);
	for (auto v:g[x])
		if (!vis[v]&&v!=fa) DFS(v,x,pre);
	return ;
}

inline void DFS_size_and_G(int x,int fa)
{
	siz[x]=1;mx[x]=0;
	for (auto v:g[x])
		if (v!=fa&&!vis[v])
		{
			DFS_size_and_G(v,x);
			siz[x]+=siz[v];
			mx[x]=max(mx[x],siz[v]);
		}
	mx[x]=max(mx[x],SIZE-siz[x]);
	if (mx[x]<mx[G]) G=x;
	return ;
}

inline void TreeDC(int x)
{
	vis[x]=true;newrt();insert(a[x]);
	for (auto v:g[x])
		if (!vis[v])
		{
			Calculate(v,x,0);
			DFS(v,x,a[x]);
		}
	for (auto v:g[x])
		if (!vis[v])
		{
			SIZE=mx[0]=siz[v];G=0;
			DFS_size_and_G(v,x);
			TreeDC(G);
		}
	return ;
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
	read(n);read(l);read(r);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i<n;i++) read(u),read(v),add(u,v);
	SIZE=mx[0]=n;G=0;DFS_size_and_G(1,-1);
	TreeDC(G);
	printf("%lld\n",ans);
	return 0;
}