#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

struct link
{
	int to,nxt;
};

struct SegmentTree
{
	int p,r,m,mn,mx;
};

SegmentTree tree[1<<18];
link e[MAXN<<1];
int head[MAXN],cnt;
int n,m,R,x,u,v,in[MAXN],seq[MAXN],dep[MAXN];
int LCAFather[MAXN][18],_2pow[18],k;

inline void add(int u,int v)
{
	e[cnt]=(link){v,head[u]};head[u]=cnt++;
	e[cnt]=(link){u,head[v]};head[v]=cnt++;
}

void dfs(int x,int f)
{
	in[x]=++R;seq[R]=x;LCAFather[x][0]=f;
	for (int i=head[x];~i;i=e[i].nxt)
		if (e[i].to!=f) dep[e[i].to]=dep[x]+1,dfs(e[i].to,x);
	return ;
}

inline void LCA()
{
	for (int j=1;j<=k;j++)
		for (int i=1;i<=n;i++)
			LCAFather[i][j]=LCAFather[LCAFather[i][j-1]][j-1];
	return ;
}

void BuildTree(int u)
{
	if (tree[u].p+1==tree[u].r)
	{
		tree[u].mn=tree[u].mx=in[tree[u].p];
		return ;
	}
	tree[u].m=tree[u].p+tree[u].r>>1;
	tree[u<<1].p=tree[u].p;tree[u<<1].r=tree[u].m;BuildTree(u<<1);
	tree[u<<1|1].p=tree[u].m;tree[u<<1|1].r=tree[u].r;BuildTree(u<<1|1);
	tree[u].mn=min(tree[u<<1].mn,tree[u<<1|1].mn);
	tree[u].mx=max(tree[u<<1].mx,tree[u<<1|1].mx);
	return ;
}

inline int qmin(int u,int l,int r)
{
	if (l>=r) return ~(1<<31);
	if (tree[u].p==l&&tree[u].r==r) return tree[u].mn;
	if (r<=tree[u].m) return qmin(u<<1,l,r);
	else if (tree[u].m<=l) return qmin(u<<1|1,l,r);
	else return min(qmin(u<<1,l,tree[u].m),qmin(u<<1|1,tree[u].m,r));
}

inline int qmax(int u,int l,int r)
{
	if (l>=r) return 1<<31;
	if (tree[u].p==l&&tree[u].r==r) return tree[u].mx;
	if (r<=tree[u].m) return qmax(u<<1,l,r);
	else if (tree[u].m<=l) return qmax(u<<1|1,l,r);
	else return max(qmax(u<<1,l,tree[u].m),qmax(u<<1|1,tree[u].m,r));
}

inline int GetLCA(int x,int y)
{
	if (dep[x]<dep[y]) swap(x,y);
	for (int i=k;~i;i--)
		if (_2pow[i]<=dep[x]-dep[y])
			x=LCAFather[x][i];
	if (x==y) return x;
	for (int i=k;~i;i--)
		if (LCAFather[x][i]!=LCAFather[y][i]&&LCAFather[x][i]!=-1)
			x=LCAFather[x][i],y=LCAFather[y][i];
	return LCAFather[x][0];
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
	memset(head,-1,sizeof head);
	read(n);read(m);
	for (_2pow[0]=1;_2pow[k]<=n;k++) _2pow[k+1]=_2pow[k]<<1;
	for (int i=2;i<=n;i++) read(x),add(i,x);
	dfs(1,-1);LCA();tree[1].p=1;tree[1].r=n+1;BuildTree(1);
	while (m--)
	{
		read(u);read(v);
		int dmx=qmax(1,u,v+1),dmn=qmin(1,u,v+1);
		dmx=seq[dmx];dmn=seq[dmn];
		int pmx=max(qmax(1,u,dmx),qmax(1,dmx+1,v+1)),pmn=min(qmin(1,u,dmn),qmin(1,dmn+1,v+1));
		pmx=seq[pmx];pmn=seq[pmn];
		int a=GetLCA(dmn,pmx),b=GetLCA(dmx,pmn);
		if (dep[a]>=dep[b]) printf("%d %d\n",dmx,dep[a]);
		else printf("%d %d\n",dmn,dep[b]);
	}
	return 0;
}