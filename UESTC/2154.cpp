#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

struct col
{
	int l,r,all;long long cl,cr;bool same;
	col(){}
	col(int _l,int _r,long long _cl,long long _cr,int _all,bool _x):
		l(_l),r(_r),cl(_cl),cr(_cr),all(_all),same(_x){}
	col operator + (const col &a)const{
		col res;res.cl=cl;res.cr=a.cr;
		res.all=max(all,a.all);
		res.same=same&&a.same&&(cr==a.cl);
		if (cr==a.cl)
		{
			if (same) res.l=l+a.l;
			else res.l=l;
			if (a.same) res.r=r+a.r;
			else res.r=a.r;
			res.all=max(res.all,r+a.l);
		}
		else
		{
			res.l=l;res.r=a.r;
		}
		return res;
	}
};

struct SegmentTree
{
	int p,r,m;col w;long long lazy;
};

SegmentTree tree[1<<18];
int n,T,l,r,o,a,k,p;

void BuildTree(int u)
{
	if (tree[u].p+1==tree[u].r)
	{
		tree[u].w=col(1,1,0,0,1,1);
		return ;
	}
	tree[u].m=tree[u].p+tree[u].r>>1;
	tree[u<<1].p=tree[u].p;tree[u<<1].r=tree[u].m;BuildTree(u<<1);
	tree[u<<1|1].p=tree[u].m;tree[u<<1|1].r=tree[u].r;BuildTree(u<<1|1);
	tree[u].w=tree[u<<1].w+tree[u<<1|1].w;
	return ;
}

void Pushdown(int u)
{
	if (tree[u].lazy)
	{
		tree[u<<1].w.cl+=tree[u].lazy;
		tree[u<<1].w.cr+=tree[u].lazy;
		tree[u<<1|1].w.cl+=tree[u].lazy;
		tree[u<<1|1].w.cr+=tree[u].lazy;
		tree[u<<1].lazy+=tree[u].lazy;
		tree[u<<1|1].lazy+=tree[u].lazy;
		tree[u].lazy=0;
	}
	return ;
}

inline void modify(int u,int l,int r,long long v)
{
	if (tree[u].p==l&&tree[u].r==r)
	{
		tree[u].lazy+=v;tree[u].w.cl+=v;tree[u].w.cr+=v;
		return ;
	}
	Pushdown(u);
	if (r<=tree[u].m) modify(u<<1,l,r,v);
	else if (tree[u].m<=l) modify(u<<1|1,l,r,v);
	else
	{
		modify(u<<1,l,tree[u].m,v);
		modify(u<<1|1,tree[u].m,r,v);
	}
	tree[u].w=tree[u<<1].w+tree[u<<1|1].w;
	return ;
}

inline col query(int u,int l,int r)
{
	if (tree[u].p==l&&tree[u].r==r) return tree[u].w;
	Pushdown(u);
	if (r<=tree[u].m) return query(u<<1,l,r);
	else if (tree[u].m<=l) return query(u<<1|1,l,r);
	else return query(u<<1,l,tree[u].m)+query(u<<1|1,tree[u].m,r);
}

inline void read(int &x)
{
	x=0;char ch;bool f=false;
	while (ch<'0'||ch>'9'){if (ch=='-') f=true;ch=getchar();}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	if (f) x=-x;return ;
}

int main()
{
	read(n);read(T);
	tree[1].p=1;tree[1].r=n+1;BuildTree(1);
	while (T--)
	{
		read(o);
		if (!o)
		{
			read(l);read(r);read(a);read(k);read(p);
			modify(1,l,l+1,a);
			modify(1,l+1,p+1,k);
			modify(1,p+1,r+1,-k);
			if (r+1<=n) modify(1,r+1,r+2,-a-k*(2*p-l-r));
		}
		else
		{
			read(l);read(r);
			if (l==r) puts("1");
			else printf("%d\n",query(1,l+1,r+1).all+1);
		}
	}
	return 0;
}