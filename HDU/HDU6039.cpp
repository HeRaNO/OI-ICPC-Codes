#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

const double _ln2=log(2.0);

struct link
{
	int to,val,nxt;
};

struct SegmentTree
{
	int p,r,m,x,lazy;
};

SegmentTree tree[1<<18];
link e[MAXN<<1];
int head[MAXN],cnt;
int n,T,R,m,q,u,v,o,w[MAXN],r[MAXN],f[MAXN],dfn[MAXN],in[MAXN],out[2][MAXN];
bool clv[MAXN];
map <int,int> _2log;

inline int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

inline void add(int u,int v,int w)
{
	--w;
	e[cnt]=(link){v,w,head[u]};head[u]=cnt++;
	e[cnt]=(link){u,w,head[v]};head[v]=cnt++;
	int fx=getf(u),fy=getf(v);
	if (fx!=fy) f[fy]=fx;
	return ;
}

void dfs(int x,int f)
{
	dfn[R]=x;in[x]=R++;
	for (int i=head[x];~i;i=e[i].nxt)
		if (e[i].to!=f&&e[i].val)
		{
			w[e[i].to]=w[x];clv[e[i].to]=true;
			dfs(e[i].to,x);
		}
	out[0][x]=R;
	for (int i=head[x];~i;i=e[i].nxt)
		if (e[i].to!=f&&!e[i].val)
		{
			w[e[i].to]=w[x]+r[x]-r[e[i].to];
			dfs(e[i].to,x);
		}
	out[1][x]=R;
	return ;
}

void BuildTree(int u)
{
	tree[u].lazy=0;
	if (tree[u].p+1==tree[u].r){tree[u].x=w[dfn[tree[u].p]];return ;}
	tree[u].m=tree[u].p+tree[u].r>>1;
	tree[u<<1].p=tree[u].p;tree[u<<1].r=tree[u].m;BuildTree(u<<1);
	tree[u<<1|1].p=tree[u].m;tree[u<<1|1].r=tree[u].r;BuildTree(u<<1|1);
	tree[u].x=max(tree[u<<1].x,tree[u<<1|1].x);
	return ;
}

inline void PushDown(int u)
{
	if (!tree[u].lazy) return ;
	tree[u<<1].lazy+=tree[u].lazy;tree[u<<1].x+=tree[u].lazy;
	tree[u<<1|1].lazy+=tree[u].lazy;tree[u<<1|1].x+=tree[u].lazy;
	tree[u].lazy=0;
	return ;
}

inline void modify(int u,int l,int r,int v)
{
	if (tree[u].p==l&&tree[u].r==r)
	{
		tree[u].x+=v;tree[u].lazy+=v;
		return ;
	}
	PushDown(u);
	if (r<=tree[u].m) modify(u<<1,l,r,v);
	else if (tree[u].m<=l) modify(u<<1|1,l,r,v);
	else
	{
		modify(u<<1,l,tree[u].m,v);
		modify(u<<1|1,tree[u].m,r,v);
	}
	tree[u].x=max(tree[u<<1].x,tree[u<<1|1].x);
	return ;
}

inline int query(int u,int l,int r)
{
	if (tree[u].p==l&&tree[u].r==r) return tree[u].x;
	PushDown(u);
	if (r<=tree[u].m) return query(u<<1,l,r);
	else if (tree[u].m<=l) return query(u<<1|1,l,r);
	else return max(query(u<<1,l,tree[u].m),query(u<<1|1,tree[u].m,r));
}

inline void read(int &x)
{
	x=0;char ch;
	if ((ch=getchar())==EOF){x=-1;return ;}
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return ;
}

int main()
{
	for (int i=0;i<=30;i++) _2log.insert(make_pair(1<<i,i));
	while (true)
	{
		read(n);if (!~n) break;read(m);read(q);
		printf("Case #%d:\n",++T);
		memset(head,-1,sizeof head);memset(clv,false,sizeof clv);
		cnt=0;R=1;
		for (int i=1;i<=n;i++)
		{
			f[i]=i;read(r[i]);r[i]=_2log[r[i]];
		}
		for (int i=1;i<=m;i++)
		{
			read(o);read(u);read(v);
			add(u,v,o);
		}
		for (int i=1;i<=n;i++)
			if (getf(i)==i)
			{
				w[i]=0;clv[i]=true;dfs(i,-1);
			}
		tree[1].p=1;tree[1].r=n+1;BuildTree(1);
		while (q--)
		{
			read(o);read(u);read(v);v=_2log[v];
			if (o==1)
			{
				if (clv[u]&&out[0][u]<out[1][u])
					modify(1,out[0][u],out[1][u],v-r[u]);
				else if (!clv[u]) modify(1,in[u],out[0][u],r[u]-v);
				r[u]=v;
			}
			else
			{
				int fa=getf(u);
				v+=query(1,in[fa],out[1][fa])-query(1,in[u],in[u]+1);
				printf("%.3lf\n",v*_ln2);
			}
		}
	}
	return 0;
}