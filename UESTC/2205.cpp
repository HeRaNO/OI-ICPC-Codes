#include <bits/stdc++.h>
#define MAXN 500005
using namespace std;

namespace SAM
{
	/* Claris's Templet */
	int tot=1,last=1,pre[MAXN<<1],son[MAXN<<1][26],ml[MAXN<<1],pos[MAXN<<1];
	int fa[MAXN<<1][20];
	void extend(int w,int rr){
		int p=++tot,x=last,r,q;
		for(ml[last=p]=ml[x]+1;x&&!son[x][w];x=pre[x])son[x][w]=p;
		if(!x)pre[p]=1;
		else if(ml[x]+1==ml[q=son[x][w]])pre[p]=q;
		else{
			pre[r=++tot]=pre[q];memcpy(son[r],son[q],sizeof son[r]);
			ml[r]=ml[x]+1;pre[p]=pre[q]=r;
			for(;x&&son[x][w]==q;x=pre[x])son[x][w]=r;
		}
		pos[rr]=p;
		return ;
	}
	void Doubling()
	{
		for (int i=1;i<=tot;i++) fa[i][0]=pre[i];
		for (int j=1;j<20;j++)
			for (int i=1;i<=tot;i++)
				fa[i][j]=fa[fa[i][j-1]][j-1];
		return ;
	}
	int getpos(int l,int r)
	{
		int len=r-l+1,pt=pos[r];
		for (int i=19;~i;i--) if (ml[fa[pt][i]]>=len) pt=fa[pt][i];
		return pt;
	}
}

namespace DFSq
{
	struct link
	{
		int to,nxt;
	};

	link e[MAXN<<2];
	int head[MAXN<<1],cnt;
	int R,in[MAXN<<1],out[MAXN<<1],pos[MAXN<<1];

	void init()
	{
		memset(head,-1,sizeof head);
	}

	void add(int u,int v)
	{
		e[cnt]=(link){v,head[u]};head[u]=cnt++;
		e[cnt]=(link){u,head[v]};head[v]=cnt++;
	}

	void addedge()
	{
		for (int i=2;i<=SAM::tot;i++) add(i,SAM::pre[i]);
		return ;
	}

	void dfs(int x,int f)
	{
		pos[x]=in[x]=++R;
		for (int i=head[x];~i;i=e[i].nxt) if (e[i].to!=f) dfs(e[i].to,x);
		out[x]=R;
		return ;
	}
}

namespace SegmentTree
{
	struct node
	{
		int l,r,ls,rs,x;
	}tr[MAXN*40];

	int rt[MAXN],tot;

	int build(int ll,int rr)
	{
		int p=++tot;tr[p].l=ll;tr[p].r=rr;
		if (ll==rr) return p;
		int m=ll+rr>>1;
		tr[p].ls=build(ll,m);tr[p].rs=build(m+1,rr);
		return p;
	}

	int add(int x,int now)
	{
		int p=++tot;tr[p]=tr[now];++tr[p].x;
		if (tr[p].l==tr[p].r) return p;
		int m=tr[p].l+tr[p].r>>1;
		if (x<=m) tr[p].ls=add(x,tr[p].ls);
		else tr[p].rs=add(x,tr[p].rs);
		return p;
	}

	int query(int u,int ll,int rr)
	{
		if (tr[u].l==ll&&tr[u].r==rr) return tr[u].x;
		int m=tr[u].l+tr[u].r>>1;
		if (rr<=m) return query(tr[u].ls,ll,rr);
		else if (ll>m) return query(tr[u].rs,ll,rr);
		else return query(tr[u].ls,ll,m)+query(tr[u].rs,m+1,rr);
	}

	void init(int n,char s[])
	{
		int p=1;
		for (int i=1;i<=n;i++)
		{
			p=SAM::son[p][s[i-1]-'a'];
			rt[i]=add(DFSq::pos[p],rt[i-1]);
		}
		return ;
	}
}

int n,T,l,r,a,b,x;
char s[MAXN];

int main()
{
	DFSq::init();
	scanf("%d %d",&n,&T);
	scanf("%s",s);
	for (int i=1;i<=n;i++) SAM::extend(s[i-1]-'a',i);
	SAM::Doubling();
	DFSq::addedge();DFSq::dfs(1,-1);
	SegmentTree::rt[0]=SegmentTree::build(1,SAM::tot);
	SegmentTree::init(n,s);
	while (T--)
	{
		scanf("%d %d %d %d",&l,&r,&a,&b);
		x=SAM::getpos(l,r);
		printf("%d\n",SegmentTree::query(SegmentTree::rt[b],DFSq::in[x],DFSq::out[x])-SegmentTree::query(SegmentTree::rt[min(a+r-l-1,b)],DFSq::in[x],DFSq::out[x]));
	}
	return 0;
}