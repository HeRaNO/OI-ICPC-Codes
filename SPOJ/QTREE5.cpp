#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

struct link{int to,nxt;};

struct tree
{
	int a,d;
	tree(){}
	tree(int _a,int _d):a(_a),d(_d){}
	bool operator < (const tree &a)const{
		return d>a.d;
	}
};

link e[MAXN<<1];
int head[MAXN],cnt,wcnt;
int n,u,v,T,R,SIZE,G,ans,o,x,lg[MAXN<<1],pt[MAXN];
int siz[MAXN],mx[MAXN],f[MAXN],dep[MAXN],dis[20][MAXN<<1];
bool vis[MAXN],c[MAXN];
priority_queue <tree> q[MAXN];

inline void add(int u,int v)
{
	e[cnt]=(link){v,head[u]};head[u]=cnt++;
	e[cnt]=(link){u,head[v]};head[v]=cnt++;
}

inline void DFS_size_and_G(int x, int father)
{
	siz[x]=1;mx[x]=0;
	for(int i=head[x];~i;i=e[i].nxt)
		if(e[i].to!=father&&!vis[e[i].to])
		{
			DFS_size_and_G(e[i].to,x);
			siz[x]+=siz[e[i].to];
			mx[x]=max(mx[x],siz[e[i].to]);
		}
	mx[x]=max(mx[x],SIZE-siz[x]);
	if(mx[x]<mx[G])G=x;
	return ;
}

inline void TreeDC(int x)
{
	vis[x]=true;
	for(int i=head[x];~i;i=e[i].nxt)
		if(!vis[e[i].to])
		{
			mx[0]=SIZE=siz[e[i].to];G=0;
			DFS_size_and_G(e[i].to,x);
			f[G]=x;TreeDC(G);
		}
	vis[x]=false;
	return ;
}

inline void dfs(int x,int f)
{
	dis[0][++R]=dep[x];pt[x]=R;
	for (int i=head[x];~i;i=e[i].nxt)
		if (e[i].to!=f)
		{
			dep[e[i].to]=dep[x]+1;
			dfs(e[i].to,x);
			dis[0][++R]=dep[x];
		}
	return ;
}

inline int getdis(int x,int y)
{
	int d=dep[x]+dep[y];
	x=pt[x];y=pt[y];
	if (x>y) swap(x,y);
	int t=lg[y-x+1];
	return d-2*min(dis[t][x],dis[t][y-(1<<t)+1]);
}

inline void modify(int x)
{
	if (c[x])
	{
		c[x]=false;--wcnt;
		return ;
	}
	c[x]=true;++wcnt;
	for (int i=x;i;i=f[i])
	{
		while (!q[i].empty()&&!c[q[i].top().a]) q[i].pop();
		q[i].push(tree(x,getdis(i,x)));
	}
	return ;
}

inline int query(int x)
{
	if (!wcnt) return -1;
	int ans=~(1<<31);
	for (int i=x;i;i=f[i])
	{
		while (!q[i].empty()&&!c[q[i].top().a]) q[i].pop();
		if (!q[i].empty()) ans=min(ans,getdis(x,q[i].top().a));
	}
	return ans;
}

inline void read(int &x)
{
	x=0;char ch=getchar();bool f=false;
	while (ch<'0'||ch>'9'){if (ch=='-') f=true;ch=getchar();}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	if (f) x=-x;return ;
}

int main()
{
	memset(head,-1,sizeof head);
	read(n);
	for (int i=1;i<n;i++){read(u);read(v);add(u,v);}
	dfs(1,-1);
	for (int i=2;i<=R;i++) lg[i]=lg[i>>1]+1;
	for (int j=1;j<=lg[R];j++)
		for (int i=1;i+(1<<j)-1<=R;i++)
			dis[j][i]=min(dis[j-1][i],dis[j-1][i+(1<<(j-1))]);
	SIZE=mx[0]=n;DFS_size_and_G(1,-1);TreeDC(G);
	read(T);
	while (T--)
	{
		read(o);read(x);
		if (!o) modify(x);
		else printf("%d\n",query(x));
	}
	return 0;
}