#include <bits/stdc++.h>
#define MAXN 200005
#define LC(x) tree[(x)].ch[0]
#define RC(x) tree[(x)].ch[1]
using namespace std;

const long long INF=1e16;

struct SplayTree
{
	int ch[2],f,siz;bool rev;long long mn,w,sw;
	SplayTree(){}
	SplayTree(int _f,long long _w):
		f(_f),siz(1),w(_w),sw(_w),rev(false),mn(_w)
		{ch[0]=ch[1]=0;}
};

SplayTree tree[MAXN];
int n,q,root,top,o,l,r,x,a[MAXN],sta[MAXN],ans[MAXN];

inline void Push_Up(int x)
{
	tree[x].siz=1;tree[x].sw=tree[x].mn=tree[x].w;
	if (LC(x))
	{
		tree[x].siz+=tree[LC(x)].siz;
		tree[x].sw+=tree[LC(x)].sw;
		tree[x].mn=min(tree[x].mn,tree[LC(x)].mn);
	}
	if (RC(x))
	{
		tree[x].siz+=tree[RC(x)].siz;
		tree[x].sw+=tree[RC(x)].sw;
		tree[x].mn=min(tree[x].mn,tree[RC(x)].mn);
	}
	return ;
}

inline void Push_Down(int x)
{
	if (tree[x].rev)
	{
		tree[LC(x)].rev^=1;tree[RC(x)].rev^=1;tree[x].rev=false;
		swap(LC(x),RC(x));
	}
	return ;
}

inline void Rotate(int x,int &k)
{
	int y=tree[x].f,z=tree[y].f,l=RC(y)==x,r=l^1;
	if (y==k) k=x;
	else tree[z].ch[RC(z)==y]=x;
	tree[x].f=z;tree[y].f=x;tree[tree[x].ch[r]].f=y;
	tree[y].ch[l]=tree[x].ch[r];tree[x].ch[r]=y;
	Push_Up(y);Push_Up(x);
	return ;
}

inline void Splay(int x,int &k)
{
	int y,z;
	sta[sta[0]=1]=x;
	for (int i=tree[x].f;i;i=tree[i].f) sta[++sta[0]]=i;
	while (sta[0]) Push_Down(sta[sta[0]--]);
	while (x!=k)
	{
		y=tree[x].f;z=tree[y].f;
		if (y!=k)
		{
			if (LC(z)==y^LC(y)==x) Rotate(x,k);
			else Rotate(y,k);
		}
		Rotate(x,k);
	}
	return ;
}

inline int find(int k)
{
	int x=root;
	while (x)
	{
		Push_Down(x);
		if (k==tree[LC(x)].siz) return x;
		if (k<=tree[LC(x)].siz) x=LC(x);
		else k-=tree[LC(x)].siz+1,x=RC(x);
	}
	return -1;
}

inline int BuildTree(int l,int r,int f)
{
	if (l>r) return 0;
	int pos=++top,m=l+r>>1;
	tree[pos]=SplayTree(f,a[m]?a[m]:INF);
	if (l==r) return pos;
	LC(pos)=BuildTree(l,m-1,pos);RC(pos)=BuildTree(m+1,r,pos);
	Push_Up(pos);return pos;
}

inline void add(int p,long long v)
{
	int x=find(p-1),y=find(p+1);
	Splay(x,root);Splay(y,RC(x));int rt=LC(y);
	tree[rt].w+=v;tree[rt].mn+=v;tree[rt].sw+=v;
	Push_Up(rt);
	return ;
}

inline long long query(int l,int r)
{
	int x=find(l-1),y=find(r+1);
	Splay(x,root);Splay(y,RC(x));
	return tree[LC(y)].sw;
}

inline void reverse(int l,int r)
{
	if (l>=r) return ;
	int x=find(l-1),y=find(r+1);
	Splay(x,root);Splay(y,RC(x));int rt=LC(y);
	sta[sta[0]=1]=rt;
	for (int i=tree[rt].f;i;i=tree[i].f) sta[++sta[0]]=i;
	while (sta[0]) Push_Down(sta[sta[0]--]);
	tree[rt].rev^=1;
	return ;
}

inline int getPos(int x,int rt)
{
	int pos=tree[LC(x)].siz+1;
	for (;x!=rt;x=tree[x].f)
		if (RC(tree[x].f)==x) pos+=tree[LC(tree[x].f)].siz+1;
	return pos;
}

inline int qleft(int p,int Y)
{
	int x=find(0),y=find(p+1);
	Splay(x,root);Splay(y,RC(x));int r=LC(y);int rt=r;
	if (tree[r].mn>=Y) return p+1;
	while (true)
	{
		Push_Down(r);
		if (tree[RC(r)].mn<Y) r=RC(r);
		else if (tree[r].w<Y) return getPos(r,rt)+1;
		else if (tree[LC(r)].mn<Y) r=LC(r);
		else return getPos(r,rt);
	}
	return -1;
}

inline void dfs(int x)
{
	if (!x) return ;
	Push_Down(x);
	dfs(LC(x));ans[l++]=tree[x].w;dfs(RC(x));
	return ;
}

const int SIZ =50000000+3;
char buf1[SIZ];
char *p1=buf1,*p2=buf1;
inline char readchar()
{
	if(p1==p2)p1=buf1,p2=buf1+fread(buf1,1,SIZ,stdin);
	return p1==p2?EOF:*p1++;
}
inline int read(int &ret)
{
	ret=0;char c;
	while ((c=readchar())> '9'|c< '0');ret=c-'0';
	while ((c=readchar())>='0'&&c<='9')ret=ret*10+c-'0';
	return ret;
}

inline void Solve()
{
	tree[0].mn=INF;
	read(n);read(q);top=0;
	for (int i=1;i<=n;i++) read(a[i]);a[n+1]=0;
	root=BuildTree(0,n+1,0);
	while (q--)
	{
		read(o);
		if (o==1)
		{
			read(r);read(x);
			int l=qleft(r,x);
			if (l>r){puts("0");continue;}
			printf("%lld\n",query(l,r)-1LL*(r-l+1)*(x-1));
			int al=query(l,l);
			reverse(l,r);reverse(l,r-1);
			add(r,-al+x-1);add(l-1,al-x+1);
		}
		else
		{
			read(l);
			printf("%d\n",query(l,l));
		}
	}
	l=0;dfs(root);
	for (int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ');
	return ;
}

int main()
{
	int T;read(T);
	while (T--) Solve();
	return 0;
}