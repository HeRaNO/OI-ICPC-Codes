#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

struct col
{
	int l,r,all;
	col(){}
	col(int _l,int _r,int _all):l(_l),r(_r),all(_all){}
	col operator + (const col &a)const{
		col res;
		res.l=l;res.r=a.r;res.all=all+a.all-(r&a.l);
		return res;
	}
};

struct SegmentTree
{
	int p,r,m;col w;
};

SegmentTree tree[1<<19];
int n,m,l,r,a[MAXN][2];
pair<int,int*> b[MAXN<<1];

void BuildTree(int u)
{
	if (tree[u].p+1==tree[u].r) return ;
	tree[u].m=tree[u].p+tree[u].r>>1;
	tree[u<<1].p=tree[u].p;tree[u<<1].r=tree[u].m;BuildTree(u<<1);
	tree[u<<1|1].p=tree[u].m;tree[u<<1|1].r=tree[u].r;BuildTree(u<<1|1);
	return ;
}

void Pushdown(int u)
{
	if (tree[u].w.l==1&&tree[u].w.r==1&&tree[u].w.all==1)
	{
		tree[u<<1].w=col(1,1,1);tree[u<<1|1].w=col(1,1,1);
	}
	return ;
}

void modify_one(int u,int x)
{
	if (tree[u].p+1==tree[u].r)
	{
		tree[u].w.l=1;tree[u].w.all=1;
		return ;
	}
	Pushdown(u);
	if (x<tree[u].m) modify_one(u<<1,x);
	else modify_one(u<<1|1,x);
	tree[u].w=tree[u<<1].w+tree[u<<1|1].w;
	return ;
}

void modify(int u,int l,int r)
{
	if (tree[u].p==l&&tree[u].r==r)
	{
		tree[u].w=col(1,1,1);
		return ;
	}
	Pushdown(u);
	if (r<=tree[u].m) modify(u<<1,l,r);
	else if (tree[u].m<=l) modify(u<<1|1,l,r);
	else
	{
		modify(u<<1,l,tree[u].m);
		modify(u<<1|1,tree[u].m,r);
	}
	tree[u].w=tree[u<<1].w+tree[u<<1|1].w;
	return ;
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
	read(n);
	for (int i=0;i<n;i++)
	{
		read(a[i][0]);read(a[i][1]);
		b[i<<1]=make_pair(a[i][0],&a[i][0]);
		b[i<<1|1]=make_pair(a[i][1],&a[i][1]);
	}
	sort(b,b+(n<<1));
	++m;*b[0].second=m;
	for (int i=1,p=n<<1;i<p;i++)
	{
		if (b[i].first!=b[i-1].first) ++m;
		*b[i].second=m;
	}
	tree[1].p=1;tree[1].r=m;BuildTree(1);
	for (int i=0;i<n;i++)
	{
		if (a[i][0]==a[i][1]) modify_one(1,a[i][0]);
		else modify(1,a[i][0],a[i][1]);
		printf("%d%c",tree[1].w.all,i==n-1?'\n':' ');
	}
	return 0;
}