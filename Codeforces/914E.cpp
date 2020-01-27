#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

struct link
{
	int to,nxt;
};

link e[MAXN<<1];
int head[MAXN],cnt;
int n,x,y,SIZE,G,v[MAXN],siz[MAXN],mx[MAXN];
char a[MAXN];
bool vis[MAXN];
long long ans[MAXN],mp[1<<20];

inline void add(int u,int v)
{
	e[cnt]=(link){v,head[u]};head[u]=cnt++;
	e[cnt]=(link){u,head[v]};head[v]=cnt++;
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

inline void dfs(int x,int f,int st,int p)
{
	mp[st]+=p;
	for (int i=head[x];~i;i=e[i].nxt)
		if (!vis[e[i].to]&&e[i].to!=f)
			dfs(e[i].to,x,st^(1<<v[e[i].to]),p);
	return ;
}

inline long long dfsans(int x,int fa,int st)
{
	long long res=mp[st];
	for (int i=0;i<20;i++) res+=mp[st^(1<<i)];
	for (int i=head[x];~i;i=e[i].nxt)
		if (!vis[e[i].to]&&e[i].to!=fa)
			res+=dfsans(e[i].to,x,st^(1<<v[e[i].to]));
	ans[x]+=res;
	return res;
}

inline void Calc(int x)
{
	++ans[x];dfs(x,-1,1<<v[x],1);
	long long now=mp[0];
	for (int i=0;i<20;i++) now+=mp[1<<i];
	for (int i=head[x];~i;i=e[i].nxt)
		if (!vis[e[i].to])
		{
			dfs(e[i].to,x,(1<<v[x])^(1<<v[e[i].to]),-1);
			now+=dfsans(e[i].to,x,1<<v[e[i].to]);
			dfs(e[i].to,x,(1<<v[x])^(1<<v[e[i].to]),1);
		}
	dfs(x,-1,1<<v[x],-1);
	ans[x]+=(now>>1);
	return ;
}

inline void TreeDC(int x)
{
	vis[x]=true;Calc(x);
	for(int i=head[x];~i;i=e[i].nxt)
		if(!vis[e[i].to])
		{
			mx[0]=SIZE=siz[e[i].to];G=0;
			DFS_size_and_G(e[i].to,x);TreeDC(G);
		}
	return ;
}

int main()
{
	memset(head,-1,sizeof head);
	scanf("%d",&n);
	for (int i=1;i<n;i++) scanf("%d %d",&x,&y),add(x,y);
	scanf("%s",a+1);
	for (int i=1;i<=n;i++) v[i]=a[i]-'a';
	SIZE=mx[0]=n;DFS_size_and_G(1,-1);TreeDC(G);
	for (int i=1;i<=n;i++) printf("%lld%c",ans[i],i==n?'\n':' ');
	return 0;
}