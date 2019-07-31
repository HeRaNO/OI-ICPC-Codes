#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;

struct whatever
{
	int mn,smn;
	whatever(){}
	whatever(int _,int __):mn(_),smn(__){}
	whatever operator + (const whatever &a)const{
		whatever res;
		if (mn<a.mn)
		{
			res.mn=mn;
			res.smn=min(smn,a.mn);
		}
		else if (mn>a.mn)
		{
			res.mn=a.mn;
			res.smn=min(a.smn,mn);
		}
		else
		{
			res.mn=a.mn;
			res.smn=min(smn,a.smn);
		}
		return res;
	}
};

struct SegmentTreeBeats
{
	int p,r,m,lazy;whatever x;
};

SegmentTreeBeats tree[1<<19];
int n,T,a[MAXN],o,x,v,ans[MAXN];

inline void BuildTree(int u)
{
	tree[u].lazy=-1;
	if (tree[u].p+1==tree[u].r){tree[u].x=whatever(a[tree[u].p],~(1<<31));return ;}
	tree[u].m=tree[u].p+tree[u].r>>1;
	tree[u<<1].p=tree[u].p;tree[u<<1].r=tree[u].m;BuildTree(u<<1);
	tree[u<<1|1].p=tree[u].m;tree[u<<1|1].r=tree[u].r;BuildTree(u<<1|1);
	tree[u].x=tree[u<<1].x+tree[u<<1|1].x;
	return ;
}

inline void PushDown(int u)
{
	if (!~tree[u].lazy) return ;
	if (tree[u<<1].x.mn<tree[u].lazy) tree[u<<1].lazy=tree[u<<1].x.mn=tree[u].lazy;
	if (tree[u<<1|1].x.mn<tree[u].lazy) tree[u<<1|1].lazy=tree[u<<1|1].x.mn=tree[u].lazy;
	tree[u].lazy=-1;
	return ;
}

inline void modify(int u,int x,int v)
{
	if (tree[u].p+1==tree[u].r){tree[u].x=whatever(v,~(1<<31));return ;}
	PushDown(u);
	if (x<tree[u].m) modify(u<<1,x,v);
	else modify(u<<1|1,x,v);
	tree[u].x=tree[u<<1].x+tree[u<<1|1].x;
	return ;
}

inline void changemax(int u,int l,int r,int v)
{
	if (tree[u].x.mn>=v) return ;
	if (tree[u].x.smn>v)
	{
		tree[u].lazy=v;
		tree[u].x.mn=v;
		return ;
	}
	if (tree[u].p+1==tree[u].r) return ;
	PushDown(u);
	if (r<=tree[u].m) changemax(u<<1,l,r,v);
	else if (tree[u].m<=l) changemax(u<<1|1,l,r,v);
	else
	{
		changemax(u<<1,l,tree[u].m,v);
		changemax(u<<1|1,tree[u].m,r,v);
	}
	tree[u].x=tree[u<<1].x+tree[u<<1|1].x;
	return ;
}

inline void query(int u)
{
	if (tree[u].p+1==tree[u].r){ans[tree[u].p]=tree[u].x.mn;return ;}
	PushDown(u);
	query(u<<1);query(u<<1|1);
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
	read(n);
	for (int i=1;i<=n;i++) read(a[i]);
	tree[1].p=1;tree[1].r=n+1;BuildTree(1);
	read(T);
	while (T--)
	{
		read(o);read(x);
		if (o==1)
		{
			read(v);modify(1,x,v);
		}
		else changemax(1,1,n+1,x);
	}
	query(1);
	for (int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ');
	return 0;
}