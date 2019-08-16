#include <bits/stdc++.h>
#define MAXN 100005
#define MAXM 5000005
using namespace std;

struct mxinfo
{
	long long m,s;int t;
	mxinfo(){}
	mxinfo(long long _,long long __,int ___):m(_),s(__),t(___){}
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
	long long m,s;int t;
	mninfo(){}
	mninfo(long long _,long long __,int ___):m(_),s(__),t(___){}
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

SegmentTreeBeats tree[1<<18];
int T,n,m,l,r,v,_x,_y,_z;
unsigned int x,y,z,f[MAXM*3];

inline void PushUp(int u)
{
	tree[u].x=tree[u<<1].x+tree[u<<1|1].x;
	tree[u].mn=tree[u<<1].mn+tree[u<<1|1].mn;
	tree[u].mx=tree[u<<1].mx+tree[u<<1|1].mx;
	return ;
}

inline void addmax(int u,long long v)
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

inline void addmin(int u,long long v)
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
	tree[u].lazy=0;
	if (tree[u].p+1==tree[u].r)
	{
		tree[u].x=0;
		tree[u].mn=mninfo(0,~(1<<31),1);
		tree[u].mx=mxinfo(0,  1<<31 ,1);
		return ;
	}
	tree[u].m=tree[u].p+tree[u].r>>1;
	tree[u<<1].p=tree[u].p;tree[u<<1].r=tree[u].m;BuildTree(u<<1);
	tree[u<<1|1].p=tree[u].m;tree[u<<1|1].r=tree[u].r;BuildTree(u<<1|1);
	PushUp(u);
	return ;
}

inline void changemax(int u,int l,int r,long long v)
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

inline void read(int &x)
{
	x=0;bool f=false;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=true;ch=getchar();}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	if (f) x=-x;return ;
}

void RNG61()
{
	x=x^(x<<11);x=x^(x>>4);x=x^(x<<5);x=x^(x>>14);
	unsigned int w=x^(y^z);x=y;y=z;z=w;
	return ;
}

int main()
{
	read(T);
	while (T--)
	{
		long long ans=0;
		read(n);read(m);read(_x);read(_y);read(_z);
		tree[1].p=1;tree[1].r=n+1;BuildTree(1);
		x=_x;y=_y;z=_z;
		for (int i=1,p=3*m;i<=p;i++)
		{
			RNG61();f[i]=z;
		}
		for (int i=1;i<=m;i++)
		{
			l=min(f[3*i-2]%n+1,f[3*i-1]%n+1);
			r=max(f[3*i-2]%n+1,f[3*i-1]%n+1);
			v=f[3*i]%(1<<30);
			changemax(1,l,r+1,v);
		}
		for (int i=1;i<=n;i++) ans^=i*query(1,i,i+1);
		printf("%lld\n",ans);
	}
	return 0;
}
