//If you want to write it right, you'd better not modify ANY CHARACTER in this code.
#include <bits/stdc++.h>
#define MAXN 500010
using namespace std;

struct mxinfo
{
	int m,s,t;
	mxinfo(){}
	mxinfo(int _,int __,int ___):m(_),s(__),t(___){}
	mxinfo operator + (const mxinfo &a)const{
		mxinfo res;
		if (m>a.m)
		{
			res.m=m;res.t=t;
			res.s=max(s,a.m);
		}
		else if (m<a.m)
		{
			res.m=a.m;res.t=a.t;
			res.s=max(a.s,m);
		}
		else
		{
			res.m=a.m;res.t=t+a.t;
			res.s=max(s,a.s);
		}
		return res;
	}
};

struct mninfo
{
	int m,s,t;
	mninfo(){}
	mninfo(int _,int __,int ___):m(_),s(__),t(___){}
	mninfo operator + (const mninfo &a)const{
		mninfo res;
		if (m<a.m)
		{
			res.m=m;res.t=t;
			res.s=min(s,a.m);
		}
		else if (m>a.m)
		{
			res.m=a.m;res.t=a.t;
			res.s=min(a.s,m);
		}
		else
		{
			res.m=a.m;res.t=t+a.t;
			res.s=min(s,a.s);
		}
		return res;
	}
};

struct SegmentTreeBeats
{
	int p,r,m;long long x,lazy;
	mxinfo mx;mninfo mn;
};

SegmentTreeBeats tree[1<<20];
int n,m,o,l,r,x,a[MAXN];

inline void PushUp(int u)
{
	tree[u].x=tree[u<<1].x+tree[u<<1|1].x;
	tree[u].mn=tree[u<<1].mn+tree[u<<1|1].mn;
	tree[u].mx=tree[u<<1].mx+tree[u<<1|1].mx;
	return ;
}

inline void addmax(int u,int v)
{
	tree[u].x+=1LL*tree[u].mn.t*(v-tree[u].mn.m);
	tree[u].mn.m=v;tree[u].mx.m=max(tree[u].mx.m,v);
	if (tree[u].mx.m==tree[u].mn.m)
	{
		tree[u].x=1LL*(tree[u].r-tree[u].p)*v;
		tree[u].mn=mninfo(tree[u].mn.m,~(1<<31),tree[u].r-tree[u].p);
		tree[u].mx=mxinfo(tree[u].mx.m,  1<<31 ,tree[u].r-tree[u].p);
	}
	else tree[u].mx.s=max(tree[u].mx.s,v);
	return ;
}

inline void addmin(int u,int v)
{
	tree[u].x-=1LL*tree[u].mx.t*(tree[u].mx.m-v);
	tree[u].mx.m=v;tree[u].mn.m=min(tree[u].mn.m,v);
	if (tree[u].mx.m==tree[u].mn.m)
	{
		tree[u].x=1LL*(tree[u].r-tree[u].p)*v;
		tree[u].mn=mninfo(tree[u].mn.m,~(1<<31),tree[u].r-tree[u].p);
		tree[u].mx=mxinfo(tree[u].mx.m,  1<<31 ,tree[u].r-tree[u].p);
	}
	else tree[u].mn.s=min(tree[u].mn.s,v);
	return ;
}

inline void Lazy(int u,long long v)
{
	tree[u].lazy+=v;tree[u].x+=(tree[u].r-tree[u].p)*v;
	tree[u].mx.m+=v;if (tree[u].mx.s!=  1<<31 ) tree[u].mx.s+=v;
	tree[u].mn.m+=v;if (tree[u].mn.s!=~(1<<31)) tree[u].mn.s+=v;
	return ;
}

inline void PushDown(int u)
{
	if (tree[u].lazy)
	{
		Lazy(u<<1,tree[u].lazy);
		Lazy(u<<1|1,tree[u].lazy);
		tree[u].lazy=0LL;
	}
	if (tree[u<<1].mx.s<tree[u].mx.m&&tree[u].mx.m<tree[u<<1].mx.m) addmin(u<<1,tree[u].mx.m);
	if (tree[u<<1].mn.m<tree[u].mn.m&&tree[u].mn.m<tree[u<<1].mn.s) addmax(u<<1,tree[u].mn.m);
	if (tree[u<<1|1].mx.s<tree[u].mx.m&&tree[u].mx.m<tree[u<<1|1].mx.m) addmin(u<<1|1,tree[u].mx.m);
	if (tree[u<<1|1].mn.m<tree[u].mn.m&&tree[u].mn.m<tree[u<<1|1].mn.s) addmax(u<<1|1,tree[u].mn.m);
	return ;
}

void BuildTree(int u)
{
	if (tree[u].p+1==tree[u].r)
	{
		tree[u].x=a[tree[u].p];
		tree[u].mn=mninfo(a[tree[u].p],~(1<<31),1);
		tree[u].mx=mxinfo(a[tree[u].p],  1<<31 ,1);
		return ;
	}
	tree[u].m=tree[u].p+tree[u].r>>1;
	tree[u<<1].p=tree[u].p;tree[u<<1].r=tree[u].m;BuildTree(u<<1);
	tree[u<<1|1].p=tree[u].m;tree[u<<1|1].r=tree[u].r;BuildTree(u<<1|1);
	PushUp(u);
	return ;
}

inline void add(int u,int l,int r,int v)
{
	if (tree[u].p==l&&tree[u].r==r)
	{
		Lazy(u,v);
		return ;
	}
	PushDown(u);
	if (r<=tree[u].m) add(u<<1,l,r,v);
	else if (tree[u].m<=l) add(u<<1|1,l,r,v);
	else
	{
		add(u<<1,l,tree[u].m,v);
		add(u<<1|1,tree[u].m,r,v);
	}
	PushUp(u);
	return ;
}

inline void changemin(int u,int l,int r,int v)
{
	if (v>=tree[u].mx.m) return ;
	if (tree[u].p==l&&tree[u].r==r&&v>tree[u].mx.s){addmin(u,v);return ;}
	if (tree[u].p+1==tree[u].r) return ;
	PushDown(u);
	if (r<=tree[u].m) changemin(u<<1,l,r,v);
	else if (tree[u].m<=l) changemin(u<<1|1,l,r,v);
	else
	{
		changemin(u<<1,l,tree[u].m,v);
		changemin(u<<1|1,tree[u].m,r,v);
	}
	PushUp(u);
	return ;
}

inline void changemax(int u,int l,int r,int v)
{
	if (v<=tree[u].mn.m) return ;
	if (tree[u].p==l&&tree[u].r==r&&v<tree[u].mn.s){addmax(u,v);return ;}
	if (tree[u].p+1==tree[u].r) return ;
	PushDown(u);
	if (r<=tree[u].m) changemax(u<<1,l,r,v);
	else if (tree[u].m<=l) changemax(u<<1|1,l,r,v);
	else
	{
		changemax(u<<1,l,tree[u].m,v);
		changemax(u<<1|1,tree[u].m,r,v);
	}
	PushUp(u);
	return ;
}

inline long long query(int u,int l,int r)
{
	if (tree[u].p==l&&tree[u].r==r) return tree[u].x;
	PushDown(u);
	if (r<=tree[u].m) return query(u<<1,l,r);
	else if (tree[u].m<=l) return query(u<<1|1,l,r);
	else return query(u<<1,l,tree[u].m)+query(u<<1|1,tree[u].m,r);
}

inline int qmin(int u,int l,int r)
{
	if (tree[u].p==l&&tree[u].r==r) return tree[u].mn.m;
	PushDown(u);
	if (r<=tree[u].m) return qmin(u<<1,l,r);
	else if (tree[u].m<=l) return qmin(u<<1|1,l,r);
	else return min(qmin(u<<1,l,tree[u].m),qmin(u<<1|1,tree[u].m,r));
}

inline int qmax(int u,int l,int r)
{
	if (tree[u].p==l&&tree[u].r==r) return tree[u].mx.m;
	PushDown(u);
	if (r<=tree[u].m) return qmax(u<<1,l,r);
	else if (tree[u].m<=l) return qmax(u<<1|1,l,r);
	else return max(qmax(u<<1,l,tree[u].m),qmax(u<<1|1,tree[u].m,r));
}

inline void read(int &x)
{
	x=0;bool f=false;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=true;ch=getchar();}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	if (f) x=-x;return ;
}

int main()
{
	read(n);
	for (int i=1;i<=n;i++) read(a[i]);
	tree[1].p=1;tree[1].r=n+1;BuildTree(1);
	read(m);
	while (m--)
	{
		read(o);read(l);read(r);if (o<=3) read(x);
		if (o==1) add(1,l,r+1,x);
		else if (o==2) changemax(1,l,r+1,x);
		else if (o==3) changemin(1,l,r+1,x);
		else if (o==4) printf("%lld\n",query(1,l,r+1));
		else if (o==5) printf("%d\n",qmax(1,l,r+1));
		else printf("%d\n",qmin(1,l,r+1));
	}
	return 0;
}
