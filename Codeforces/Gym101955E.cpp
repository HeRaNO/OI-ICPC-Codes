#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

struct data
{
	long long mx,smx;
	int mxc,smxc;
	data(){}
	data(long long _a,int _b,long long _c,int _d):
		mx(_a),mxc(_b),smx(_c),smxc(_d){}
	void join(long long x,int xc)
	{
		if (!~xc) return ;
		if (xc==mxc) mx=max(mx,x);
		else
		{
			if (!~smxc||x>smx)
			{
				smx=x;smxc=xc;
			}
			if (smx>mx)
			{
				swap(smx,mx);
				swap(smxc,mxc);
			}
		}
		return ;
	}
	data operator + (const data &a)const{
		data res=data(mx,mxc,smx,smxc);
		res.join(a.mx,a.mxc);
		res.join(a.smx,a.smxc);
		return res;
	}
};

struct E
{
	long long ans;
	data pp,pn,np,nn;
};

struct SegmentTree
{
	int p,r,m;
	E x;
};

SegmentTree tree[1<<18];
int T,n,m,c[MAXN],o,k,_x,_y,cas;
long long x[MAXN],y[MAXN];

inline long long merge(data x,data y)
{
	if (x.mxc!=y.mxc) return x.mx+y.mx;
	long long res=0;
	if (~x.smxc) res=max(res,x.smx+y.mx);
	if (~y.smxc) res=max(res,y.smx+x.mx);
	return res;
}

inline E PushUp(E x,E y)
{
	E res;
	res.ans=max(x.ans,y.ans);
	res.pp=x.pp+y.pp;res.np=x.np+y.np;res.pn=x.pn+y.pn;res.nn=x.nn+y.nn;
	res.ans=max(res.ans,merge(x.pp,y.nn));
	res.ans=max(res.ans,merge(x.pn,y.np));
	res.ans=max(res.ans,merge(x.np,y.pn));
	res.ans=max(res.ans,merge(x.nn,y.pp));
	return res;
}

inline void BuildTree(int u)
{
	if (tree[u].p+1==tree[u].r)
	{
		int p=tree[u].p;
		tree[u].x.pp=data( x[p]+y[p],c[p],0,-1);
		tree[u].x.np=data(-x[p]+y[p],c[p],0,-1);
		tree[u].x.pn=data( x[p]-y[p],c[p],0,-1);
		tree[u].x.nn=data(-x[p]-y[p],c[p],0,-1);
		tree[u].x.ans=0;
		return ;
	}
	tree[u].m=tree[u].p+tree[u].r>>1;
	tree[u<<1].p=tree[u].p;tree[u<<1].r=tree[u].m;BuildTree(u<<1);
	tree[u<<1|1].p=tree[u].m;tree[u<<1|1].r=tree[u].r;BuildTree(u<<1|1);
	tree[u].x=PushUp(tree[u<<1].x,tree[u<<1|1].x);
	return ;
}

inline void modify(int u,int l)
{
	if (tree[u].p+1==tree[u].r)
	{
		int p=l;
		tree[u].x.pp=data( x[p]+y[p],c[p],0,-1);
		tree[u].x.np=data(-x[p]+y[p],c[p],0,-1);
		tree[u].x.pn=data( x[p]-y[p],c[p],0,-1);
		tree[u].x.nn=data(-x[p]-y[p],c[p],0,-1);
		tree[u].x.ans=0;
		return ;
	}
	if (l<tree[u].m) modify(u<<1,l);
	else modify(u<<1|1,l);
	tree[u].x=PushUp(tree[u<<1].x,tree[u<<1|1].x);
	return ;
}

inline E query(int u,int l,int r)
{
	if (tree[u].p==l&&tree[u].r==r) return tree[u].x;
	if (r<=tree[u].m) return query(u<<1,l,r);
	else if (tree[u].m<=l) return query(u<<1|1,l,r);
	else return PushUp(query(u<<1,l,tree[u].m),query(u<<1|1,tree[u].m,r));
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&n,&m);
		for (int i=1;i<=n;i++) scanf("%I64d %I64d %d",&x[i],&y[i],&c[i]);
		tree[1].p=1;tree[1].r=n+1;BuildTree(1);
		printf("Case #%d:\n",++cas);
		while (m--)
		{
			scanf("%d",&o);
			if (o==1)
			{
				scanf("%d %d %d",&k,&_x,&_y);
				x[k]+=_x;y[k]+=_y;
				modify(1,k);
			}
			else if (o==2)
			{
				scanf("%d",&k);scanf("%d",&c[k]);
				modify(1,k);
			}
			else
			{
				scanf("%d %d",&_x,&_y);
				printf("%I64d\n",query(1,_x,_y+1).ans);
			}
		}
	}
	return 0;
}