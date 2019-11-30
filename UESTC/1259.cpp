#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

struct longint
{
	long long a,b;
	longint(){}
	longint(long long _a,long long _b):a(_a),b(_b){}
	longint operator | (const longint &p)const{
		return longint(a|p.a,b|p.b);
	}
	int count(){ return __builtin_popcountll(a)+__builtin_popcountll(b); }
	void set(int x)
	{
		x>63?a|=(1LL<<(x-64)):b|=(1LL<<x);
		return ;
	}
	bool empty(){ return a==0&&b==0; }
	void clean(){ a=b=0; }
};

struct SegmentTree
{
	int p,r,m;longint x,lazy;
};

SegmentTree tree[1<<18];
int n,m,T,o,l,r,x,a[MAXN];

void BuildTree(int u)
{
	if (tree[u].p+1==tree[u].r)
	{
		tree[u].x.set(a[tree[u].p]);
		return ;
	}
	tree[u].m=tree[u].p+tree[u].r>>1;
	tree[u<<1].p=tree[u].p;tree[u<<1].r=tree[u].m;BuildTree(u<<1);
	tree[u<<1|1].p=tree[u].m;tree[u<<1|1].r=tree[u].r;BuildTree(u<<1|1);
	tree[u].x=tree[u<<1].x|tree[u<<1|1].x;
	return ;
}

inline void PushDown(int u)
{
	if (tree[u].lazy.empty()) return ;
	tree[u<<1].lazy=tree[u].lazy;
	tree[u<<1].x=tree[u].lazy;
	tree[u<<1|1].lazy=tree[u].lazy;
	tree[u<<1|1].x=tree[u].lazy;
	tree[u].lazy.clean();
	return ;
}

inline void modify(int u,int l,int r,int v)
{
	if (tree[u].p==l&&tree[u].r==r)
	{
		tree[u].x.clean();
		tree[u].lazy.clean();
		tree[u].x.set(v);
		tree[u].lazy.set(v);
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
	tree[u].x=tree[u<<1].x|tree[u<<1|1].x;
	return ;
}

longint query(int u,int l,int r)
{
	if (tree[u].p==l&&tree[u].r==r) return tree[u].x;
	PushDown(u);
	if (r<=tree[u].m) return query(u<<1,l,r);
	else if (tree[u].m<=l) return query(u<<1|1,l,r);
	else return query(u<<1,l,tree[u].m)|query(u<<1|1,tree[u].m,r);
}

inline void read(int &x)
{
	x=0;char ch=getchar();
	while (ch<'0'||ch>'9')
	{
		if (ch=='M'){x=0;return ;}
		if (ch=='Q'){x=1;return ;}
		ch=getchar();
	}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return ;
}

int main()
{
	read(n);read(m);
	for (int i=1;i<=n;i++) read(a[i]);
	tree[1].p=1;tree[1].r=n+1;BuildTree(1);
	read(T);
	while (T--)
	{
		read(o);read(l);read(r);
		if (!o) read(x),modify(1,l,r+1,x);
		else printf("%d\n",query(1,l,r+1).count());
	}
	return 0;
}