#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAXN 100005
using namespace std;

vector<int> g[MAXN];
int n,m,R,SZ,G,lg[MAXN<<1],pt[MAXN],f[MAXN];
int siz[MAXN],mx[MAXN],dep[MAXN],dis[20][MAXN<<1];
int val[MAXN],clo[MAXN];
bool vis[MAXN];

inline void DFS_size_and_G(int x,int fa)
{
	siz[x]=1;mx[x]=0;
	for (int v:g[x])
		if (v!=fa&&!vis[v])
		{
			DFS_size_and_G(v,x);
			siz[x]+=siz[v];
			mx[x]=max(mx[x],siz[v]);
		}
	mx[x]=max(mx[x],SZ-siz[x]);
	if (mx[x]<mx[G]) G=x;
	return ;
}

inline void TreeDC(int x)
{
	vis[x]=true;
	for (int v:g[x])
		if (!vis[v])
		{
			mx[0]=SZ=siz[v];G=0;
			DFS_size_and_G(v,x);
			f[G]=x;TreeDC(G);
		}
	vis[x]=false;
	return ;
}

inline void dfs(int x,int f)
{
	dis[0][++R]=dep[x];pt[x]=R;
	for (int v:g[x])
		if (v!=f)
		{
			dep[v]=dep[x]+1;
			dfs(v,x);
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

void modify(int x)
{
	for (int i=x;i;i=f[i])
		if (val[i]>getdis(x,i))
			val[i]=getdis(x,i);
	return ;
}

int query(int x)
{
	int res=0x3f3f3f3f;
	for (int i=x;i;i=f[i])
		if (res>getdis(x,i)+val[i])
			res=getdis(x,i)+val[i];
	return res;
}

int main(int argc,char *argv[])
{
	memset(val,0x3f,sizeof val);
	scanf("%d %d",&n,&m);
	for (int i=1,x,y;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		g[x].push_back(y);g[y].push_back(x);
	}
	dfs(1,-1);
	for (int i=2;i<=R;i++) lg[i]=lg[i>>1]+1;
	for (int j=1;j<=lg[R];j++)
		for (int i=1;i+(1<<j)-1<=R;i++)
			dis[j][i]=min(dis[j-1][i],dis[j-1][i+(1<<(j-1))]);
	SZ=mx[0]=n;DFS_size_and_G(1,-1);TreeDC(G);
	modify(1);
	while (m--)
	{
		int o,x;
		scanf("%d %d",&o,&x);
		if (o==1) modify(x);
		else printf("%d\n",query(x));
	}
	return 0;
}