#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

namespace SAM
{
	/* Claris's Templet */
	int tot,last,pre[MAXN<<1],son[MAXN<<1][26],ml[MAXN<<1],pos[MAXN<<1];
	int fa[MAXN<<1][18];
	void init()
	{
		tot=1;last=1;
		memset(ml,0,sizeof ml);
		memset(son,0,sizeof son);
		memset(pre,0,sizeof pre);
		return ;
	}
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
		for (int j=1;j<18;j++)
			for (int i=1;i<=tot;i++)
				fa[i][j]=fa[fa[i][j-1]][j-1];
		return ;
	}
	int getpos(int l,int r)
	{
		int len=r-l+1,pt=pos[r];
		for (int i=17;~i;i--) if (ml[fa[pt][i]]>=len) pt=fa[pt][i];
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
	int R,in[MAXN<<1],out[MAXN<<1],rev[MAXN<<1];

	void init()
	{
		memset(head,-1,sizeof head);cnt=0;R=0;
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
		in[x]=++R;rev[R]=x;
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

	int rt[MAXN<<1],tot;
	bool vis[MAXN<<1];

	int build(int ll,int rr)
	{
		int p=++tot;tr[p].l=ll;tr[p].r=rr;tr[p].x=0;
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

	int query(int ul,int ur,int l,int r,int k)
	{
		if (l==r) return l;
		int m=l+r>>1;
		int cnt=tr[tr[ur].ls].x-tr[tr[ul].ls].x;
		if (k<=cnt) return query(tr[ul].ls,tr[ur].ls,l,m,k);
		return query(tr[ul].rs,tr[ur].rs,m+1,r,k-cnt);
	}

	void init(int n,char s[])
	{
		int p=1;
		memset(vis,false,sizeof vis);
		for (int i=1;i<=n;i++)
		{
			p=SAM::son[p][s[i-1]-'a'];
			vis[p]=true;
		}
		for (int i=1;i<=SAM::tot;i++)
		{
			if (vis[DFSq::rev[i]])
				rt[i]=add(DFSq::rev[i],rt[i-1]);
			else rt[i]=add(SAM::tot+1,rt[i-1]);
		}
		return ;
	}
}

int T,n,m,l,r,k;
char s[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		DFSq::init();SAM::init();
		scanf("%d %d",&n,&m);
		scanf("%s",s);
		for (int i=1;i<=n;i++) SAM::extend(s[i-1]-'a',i);
		SAM::Doubling();
		DFSq::addedge();DFSq::dfs(1,-1);
		SegmentTree::tot=0;
		SegmentTree::rt[0]=SegmentTree::build(1,SAM::tot+1);
		SegmentTree::init(n,s);
		while (m--)
		{
			scanf("%d %d %d",&l,&r,&k);int d=r-l;
			int x=SAM::getpos(l,r);
			l=DFSq::in[x];
			r=DFSq::out[x];
			int p=SegmentTree::query(SegmentTree::rt[l-1],SegmentTree::rt[r],1,SAM::tot+1,k);
			if (p==SAM::tot+1) puts("-1");
			else printf("%d\n",SAM::ml[p]-d);
		}
	}
	return 0;
}