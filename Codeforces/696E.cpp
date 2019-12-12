#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

struct E
{
	long long x;int y,z;
	E(){}
	E(long long _,int __,int ___):x(_),y(__),z(___){}
	bool operator < (const E &a)const{
		return x==a.x?y<a.y:x<a.x;
	}
	E operator + (const long long &a)const{
		return E(x+a,y,z);
	}
	void operator += (const long long &a){
		this->x+=a;return ;
	}
	bool empty()
	{
		return x==~(1LL<<63);
	}
};

struct SegmentTree
{
	int p,r,m;long long lazy;E x;
};

struct link
{
	int to,nxt;
};

link e[MAXN<<1];
SegmentTree tree[1<<18];
int head[MAXN],cnt;
int n,T,R=1,m,o,u,v,k,c[MAXN];
int fa[MAXN],pos[MAXN],rev[MAXN],in[MAXN],out[MAXN],siz[MAXN],mx[MAXN],dep[MAXN],top[MAXN];
vector <int> a[MAXN];
int pa[MAXN],ans[MAXN];

inline void add(int u,int v)
{
	e[cnt]=(link){v,head[u]};head[u]=cnt++;
	e[cnt]=(link){u,head[v]};head[v]=cnt++;
}

void dfs1(int x)
{
	siz[x]=1;mx[x]=-1;
	for (int i=head[x];~i;i=e[i].nxt)
		if (e[i].to!=fa[x])
		{
			fa[e[i].to]=x;dep[e[i].to]=dep[x]+1;
			dfs1(e[i].to);
			siz[x]+=siz[e[i].to];
			if (!~mx[x]||siz[e[i].to]>siz[mx[x]]) mx[x]=e[i].to;
		}
	return ;
}

void dfs2(int x,int t)
{
	top[x]=t;pos[x]=in[x]=R;rev[R++]=x;
	if (~mx[x]) dfs2(mx[x],t);
	for (int i=head[x];~i;i=e[i].nxt)
		if (e[i].to!=fa[x]&&e[i].to!=mx[x]) dfs2(e[i].to,e[i].to);
	out[x]=R;
	return ;
}

void BuildTree(int u)
{
	if (tree[u].p+1==tree[u].r)
	{
		int p=rev[tree[u].p];
		if (a[p].size()) tree[u].x=E(a[p][0],p,a[p][0]);
		else tree[u].x=E(~(1LL<<63),~(1<<31),-1);
		return ;
	}
	tree[u].m=tree[u].p+tree[u].r>>1;
	tree[u<<1].p=tree[u].p;tree[u<<1].r=tree[u].m;BuildTree(u<<1);
	tree[u<<1|1].p=tree[u].m;tree[u<<1|1].r=tree[u].r;BuildTree(u<<1|1);
	tree[u].x=min(tree[u<<1].x,tree[u<<1|1].x);
	return ;
}

inline void PushDown(int u)
{
	if (!tree[u].lazy) return ;
	if (!tree[u<<1].x.empty())
	{
		tree[u<<1].x+=tree[u].lazy;tree[u<<1].lazy+=tree[u].lazy;
	}
	if (!tree[u<<1|1].x.empty())
	{
		tree[u<<1|1].x+=tree[u].lazy;tree[u<<1|1].lazy+=tree[u].lazy;
	}
	tree[u].lazy=0;return ;
}

void modify(int u,int l,int r,long long v,bool f)
{
	if (tree[u].p==l&&tree[u].r==r)
	{
		if (tree[u].x.empty()) return ;
		if (f)
		{
			tree[u].x+=v;tree[u].lazy+=v;
		}
		else
		{
			int p=rev[tree[u].p];
			if (pa[p]+1==a[p].size()) tree[u].x=E(~(1LL<<63),~(1<<31),-1);
			else
			{
				++pa[p];
				tree[u].x=E(a[p][pa[p]]+tree[u].lazy,tree[u].x.y,a[p][pa[p]]);
			}
		}
		return ;
	}
	PushDown(u);
	if (r<=tree[u].m) modify(u<<1,l,r,v,f);
	else if (tree[u].m<=l) modify(u<<1|1,l,r,v,f);
	else
	{
		modify(u<<1,l,tree[u].m,v,f);
		modify(u<<1|1,tree[u].m,r,v,f);
	}
	tree[u].x=min(tree[u<<1].x,tree[u<<1|1].x);
	return ;
}

inline E query(int u,int l,int r)
{
	if (tree[u].p==l&&tree[u].r==r) return tree[u].x;
	PushDown(u);
	if (r<=tree[u].m) return query(u<<1,l,r);
	else if (tree[u].m<=l) return query(u<<1|1,l,r);
	else return min(query(u<<1,l,tree[u].m),query(u<<1|1,tree[u].m,r));
}

inline int Qlink(int l,int r)
{
	E res=E(~(1LL<<63),~(1<<31),-1);
	while (top[l]!=top[r])
	{
		if (dep[top[l]]<dep[top[r]]) swap(l,r);
		res=min(res,query(1,pos[top[l]],pos[l]+1));
		l=fa[top[l]];
	}
	if (pos[l]>pos[r]) swap(l,r);
	res=min(res,query(1,pos[l],pos[r]+1));
	if (res.z==-1) return -1;
	modify(1,pos[c[res.z]],pos[c[res.z]]+1,0,false);
	return res.z;
}

inline void Q(int u,int v,int k)
{
	ans[0]=0;
	for (int i=1;i<=k;i++)
	{
		int x=Qlink(u,v);
		if (!~x) break;
		ans[++ans[0]]=x;
	}
	printf("%d",ans[0]);
	for (int i=1;i<=ans[0];i++) printf(" %d",ans[i]);
	putchar('\n');
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
	memset(head,-1,sizeof head);
	read(n);read(m);read(T);
	for (int i=1;i<n;i++) read(u),read(v),add(u,v);
	for (int i=1;i<=m;i++) read(c[i]),a[c[i]].push_back(i);
	dfs1(1);dfs2(1,1);tree[1].p=1;tree[1].r=n+1;BuildTree(1);
	while (T--)
	{
		read(o);read(u);read(v);
		if (o==1) read(k),Q(u,v,k);
		else modify(1,in[u],out[u],v,true);
	}
	return 0;
}